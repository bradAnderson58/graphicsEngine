#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include "headers/vector_math/Vector3.h"

#include <string>
#include <vector>

class GraphicsObject {
public:
	GraphicsObject(std::vector<Vector3> vertices, std::vector<int> indices) :
		vertices(vertices), indices(indices) { }
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
	std::vector<Vector3> vertices;
	std::vector<int> indices;

	GLuint buildShader(std::string filePath, GLenum shaderType);
	GLuint buildShaderProgram(GLuint vertexShader, GLuint fragmentShader);
	int computeVertSize() { return vertices.size() * 3 * sizeof(GLfloat); }
	int computeIndexSize() { return indices.size() * sizeof(GLuint); }
	void fillVertArray(GLfloat *vertArray);
	void fillIndexArray(GLuint *indexArray);
};