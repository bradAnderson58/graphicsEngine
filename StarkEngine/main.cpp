
#include "StarkBase.h"
#include "Vector3.h"

#include <vector>

using namespace std;

int main() {
	StarkBase *base = new StarkBase(800, 600, "Stark Engine Example");

	vector<Vector3> points = {
		Vector3(0.5f, 0.5f, 0.0f),
		Vector3(0.5f, -0.5f, 0.0f),
		Vector3(-0.5f, -0.5f, 0.0f),
		Vector3(-0.5f, 0.5f, 0.0f)
	};
	vector<int> indices = {
		0, 1, 3,
		1, 2, 3
	};

	GraphicsObject *object = base->createNewGraphicsObject(points, indices);
	object->addVertexShader("../StarkEngine/default.vs");
	object->addFragmentShader("../StarkEngine/default.fs");

	base->setKeyCallback([](GLFWwindow* window, int key, int scancode, int action, int mode) -> void {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	});
	base->run();
}
