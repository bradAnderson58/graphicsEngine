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

#include "GraphicsObject.h"

class StarkBase {
public:
	StarkBase() : windowHeight(0), windowWidth(0), windowLabel("") { }
	StarkBase(int width, int height, const char *label):
		windowWidth(width), windowHeight(height), windowLabel(label) { }

	int run();
	void setKeyCallback(void callback(GLFWwindow* window, int key, int scancode, int action, int mode));

	void addGraphicsObject(GraphicsObject object) {
		objects.push_back(object);
	}

private:
	int windowHeight;
	int windowWidth;
	const char *windowLabel;
	GLFWwindow *window;
	std::vector<GLFWkeyfun> registeredCallbacks;
	std::vector<GraphicsObject> objects; // TODO: this should be a collection of Graphics Objects - or better yet a Graphics Object Manager

	bool setupGlfw();
	bool setupGlew();
	void initializeObjects();
	void redrawObjects();
	void deallocateObjects();
};