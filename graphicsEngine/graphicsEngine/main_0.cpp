#include "headers/StarkBase.h"
#include "headers/graphics_objects/GraphicsObject.h"
#include "headers/vector_math/Vector3.h"

#include <vector>
#include <unistd.h>
#include <cmath>

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
    // xCode is putting my working directory far away, had to set custom working directory
    // TODO: set up resource folder instead
    object->addVertexShader("resource/shaders/default.vs");
    object->addFragmentShader("resource/shaders/default.fs");
    object->bindRenderColorCallback([]() -> float {
        float timeValue = glfwGetTime();
        return (sin(timeValue) / 2.0f) + 0.5f;
    });
    
    base->setKeyCallback([](GLFWwindow* window, int key, int scancode, int action, int mode) -> void {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    });
    base->run();
    
    return 0;
}
