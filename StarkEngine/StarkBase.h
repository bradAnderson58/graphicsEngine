#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>
#include <functional>


class StarkBase {
public:
	StarkBase() : windowHeight(0), windowWidth(0), windowLabel("") { }
	StarkBase(int width, int height, const char *label):
		windowWidth(width), windowHeight(height), windowLabel(label) { }

	int run();
	//void setKeyCallback(GLFWkeyfun callback);
	void setKeyCallback(void callback(GLFWwindow* window, int key, int scancode, int action, int mode));

private:
	int windowHeight;
	int windowWidth;
	const char *windowLabel;
	GLFWwindow *window;
	std::vector<GLFWkeyfun> registeredCallbacks;

	bool StarkBase::setupGlfw();
	bool StarkBase::setupGlew();
	GLuint buildShader(std::string filePath, GLenum shaderType);
	GLuint buildShaderProgram(GLuint vertexShader, GLuint fragmentShader);
};