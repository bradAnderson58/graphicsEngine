
#include "StarkBase.h"
#include <fstream>

using namespace std;

int StarkBase::run() {
	if (!setupGlfw()) {
		return -1;
	}
	if (!setupGlew()) {
		return -1;
	}

	for (GLFWkeyfun callback : registeredCallbacks) {
		glfwSetKeyCallback(window, callback);
	}

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	GLuint vertexBufferObject;
	glGenBuffers(1, &vertexBufferObject);

	// copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// use our shader program when we want to render an object
	GLuint vertexShader = buildShader("../StarkEngine/default.vs", GL_VERTEX_SHADER);
	GLuint fragmentShader = buildShader("../StarkEngine/default.fs", GL_FRAGMENT_SHADER);
	GLuint shaderProgram = buildShaderProgram(vertexShader, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glUseProgram(shaderProgram);
	
	// draw the object

	
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		// TODO: move this out to a method
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void StarkBase::setKeyCallback(void callback(GLFWwindow* window, int key, int scancode, int action, int mode)) {
	// TODO: what if callback cant be cast to GLFWkeyfun check
	registeredCallbacks.push_back(static_cast<GLFWkeyfun>(callback));
}


// Private methods

bool StarkBase::setupGlfw() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(windowWidth, windowHeight, windowLabel, nullptr, nullptr);
	if (window == nullptr) {
		cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);
	return true;
}

bool StarkBase::setupGlew() {
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW\n";
		return false;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	return true;
}

GLuint StarkBase::buildShader(string filePath, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	string shaderSourceStr;

	ifstream sourceFile(filePath);
	if (sourceFile) {
		shaderSourceStr.assign((istreambuf_iterator<char>(sourceFile)), istreambuf_iterator<char>());
		const GLchar* shaderSource = shaderSourceStr.c_str();
		glShaderSource(shader, 1, (const GLchar**)&shaderSource, NULL);
		glCompileShader(shader);

		GLint success;
		GLchar infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << '\n';
		}
	} else {
		cout << "ERROR::SHADER::UNABLE_TO_OPEN_FILE " << filePath << '\n';
	}
	return shader;
}

GLuint StarkBase::buildShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		cout << "ERROR::SHADER_PROGRAM::COMPILATION_FAILED\n" << infoLog << '\n';
	}

	return shaderProgram;
}