
#include "StarkBase.h"
#include "Vector3.h"

#include <vector>

using namespace std;

int main() {
	StarkBase *base = new StarkBase(800, 600, "Stark Engine Example");

	vector<Vector3> points(4);
	points[0] = Vector3(0.5f, 0.5f, 0.0f);
	points[1] = Vector3(0.5f, -0.5f, 0.0f);
	points[2] = Vector3(-0.5f, -0.5f, 0.0f);
	points[3] = Vector3(-0.5f, 0.5f, 0.0f);

	// TODO: next time, also pass the indices of the points to make Graphics Object
	GraphicsObject *object = base->createNewGraphicsObject(points);
	object->addVertexShader("../StarkEngine/default.vs");
	object->addFragmentShader("../StarkEngine/default.fs");

	base->setKeyCallback([](GLFWwindow* window, int key, int scancode, int action, int mode) -> void {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	});
	base->run();
}
