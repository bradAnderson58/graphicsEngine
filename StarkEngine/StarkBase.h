#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicsObjectManager.h"
#include "Vector3.h"

class StarkBase {
public:
	StarkBase() : windowHeight(0), windowWidth(0), windowLabel("") {
		init();
	}
	StarkBase(int width, int height, const char *label):
		windowWidth(width), windowHeight(height), windowLabel(label) {
		init();
	}

	int run();
	void setKeyCallback(void callback(GLFWwindow* window, int key, int scancode, int action, int mode));

	GraphicsObject* createNewGraphicsObject(std::vector<Vector3>);

private:
	int windowHeight;
	int windowWidth;
	const char *windowLabel;
	GLFWwindow *window;
	std::vector<GLFWkeyfun> registeredCallbacks;
	GraphicsObjectManager objectManager;

	int init();
	bool setupGlfw();
	bool setupGlew();
};