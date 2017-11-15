#pragma once

#include <iostream>
#include <fstream>

#include "headers/graphics_objects/GraphicsObject.h"

using namespace std;

void GraphicsObject::init() {
	// use our shader program when we want to render an object
	GLuint vertexShader = buildShader(vertexShaderFile, GL_VERTEX_SHADER);
	GLuint fragmentShader = buildShader(fragmentShaderFile, GL_FRAGMENT_SHADER);
	shaderProgram = buildShaderProgram(vertexShader, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLfloat* vertArray = new GLfloat[vertices.size() * 3];
	fillVertArray(vertArray);
	GLuint* indexArray = new GLuint[indices.size()];
	fillIndexArray(indexArray);

	GLuint elementBufferObj;
	glGenVertexArrays(1, &vertexArrayObj);
	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &elementBufferObj);

	// bind the vertex array object first, then bind and set vertex buffers and attribute pointers
	glBindVertexArray(vertexArrayObj);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, computeVertSize(), vertArray, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObj);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, computeIndexSize(), indexArray, GL_STATIC_DRAW);

	// then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);  // must unbind vao first

	delete []vertArray;
	delete []indexArray;
}

void GraphicsObject::redraw() {

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shaderProgram);

	// doing some uniform code here TODO
	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");

	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	glBindVertexArray(vertexArrayObj);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}

void GraphicsObject::deallocate() {
	// properly de-allocate all the resources
	glDeleteVertexArrays(1, &vertexArrayObj);
	glDeleteBuffers(1, &vertexBufferObject);
}

void GraphicsObject::addVertexShader(std::string filePath) {
	vertexShaderFile = filePath;
}
void GraphicsObject::addFragmentShader(std::string filePath) {
	fragmentShaderFile = filePath;
}

// private methods

GLuint GraphicsObject::buildShader(string filePath, GLenum shaderType) {
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
	}
	else {
		cout << "ERROR::SHADER::UNABLE_TO_OPEN_FILE " << filePath << '\n';
	}
	return shader;
}

GLuint GraphicsObject::buildShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
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


void GraphicsObject::fillVertArray(GLfloat *vertArray) {
	int index = 0;
	for (Vector3 vector : vertices) {
		vertArray[index++] = vector.x;
		vertArray[index++] = vector.y;
		vertArray[index++] = vector.z;
	}
}

void GraphicsObject::fillIndexArray(GLuint *indexArray) {
	int ind = 0;
	for (int objIndex : indices) {
		indexArray[ind++] = objIndex;
	}
}