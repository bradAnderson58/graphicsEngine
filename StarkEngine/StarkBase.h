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
	StarkBase() : windowHeight(0), windowWidth(0), windowLabel("") {
		init();
	}
	StarkBase(int width, int height, const char *label):
		windowWidth(width), windowHeight(height), windowLabel(label) {
		init();
	}

	int run();
	void setKeyCallback(void callback(GLFWwindow* window, int key, int scancode, int action, int mode));

	GraphicsObject *createNewGraphicsObject();

private:
	int windowHeight;
	int windowWidth;
	const char *windowLabel;
	GLFWwindow *window;
	std::vector<GLFWkeyfun> registeredCallbacks;
	std::vector<GraphicsObject*> objects; // TODO: this should be a collection of Graphics Objects - or better yet a Graphics Object Manager

	int init();
	bool setupGlfw();
	bool setupGlew();
	void initializeObjects();
	void redrawObjects();
	void deallocateObjects();
	void addGraphicsObject(GraphicsObject *object) {
		objects.push_back(object);
	}
};