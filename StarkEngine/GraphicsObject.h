#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

class GraphicsObject {
public:
	GraphicsObject() {}
	void init();
	void redraw();
	void deallocate();
	void addVertexShader(std::string filePath);
	void addFragmentShader(std::string filePath);

private:
	std::string vertexShaderFile;
	std::string fragmentShaderFile;
	GLuint shaderProgram;
	GLuint vertexArrayObj;
	GLuint vertexBufferObject;

	GLuint buildShader(std::string filePath, GLenum shaderType);
	GLuint buildShaderProgram(GLuint vertexShader, GLuint fragmentShader);
};