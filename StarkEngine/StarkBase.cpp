
#include "StarkBase.h"
#include "GraphicsObject.h"
#include <fstream>
#include <algorithm>

using namespace std;

int StarkBase::init() {
	if (!setupGlfw()) {
		return -1;
	}
	if (!setupGlew()) {
		return -1;
	}
	return 0;
}

GraphicsObject* StarkBase::createNewGraphicsObject() {
	GraphicsObject *object = new GraphicsObject();
	//object.addVertexShader("../StarkEngine/default.vs");
	//object.addFragmentShader("../StarkEngine/default.fs");
	addGraphicsObject(object);
	return object;
}

int StarkBase::run() {
	for (GLFWkeyfun callback : registeredCallbacks) {
		glfwSetKeyCallback(window, callback);
	}
	initializeObjects();

	// draw the object each iteration
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		redrawObjects();
		glfwSwapBuffers(window);
	}

	deallocateObjects();
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

void StarkBase::initializeObjects() {
	std::for_each(objects.begin(), objects.end(), [](GraphicsObject* object) {
		object->init();
	});
}

void StarkBase::redrawObjects() {
	std::for_each(objects.begin(), objects.end(), [](GraphicsObject* object) {
		object->redraw();
	});
}

void StarkBase::deallocateObjects() {
	std::for_each(objects.begin(), objects.end(), [](GraphicsObject* object) {
		object->deallocate();
	});
}