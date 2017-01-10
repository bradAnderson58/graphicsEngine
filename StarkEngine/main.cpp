
#include "StarkBase.h"

using namespace std;

int main() {
	StarkBase *base = new StarkBase(800, 600, "Stark Engine Example");

	//base->setKeyCallback(key_callback);
	base->setKeyCallback([](GLFWwindow* window, int key, int scancode, int action, int mode) -> void {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	});
	base->run();
}
