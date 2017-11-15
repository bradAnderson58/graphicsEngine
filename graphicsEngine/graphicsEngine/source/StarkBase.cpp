
#include "headers/StarkBase.h"

#include <vector>

using namespace std;

int StarkBase::init() {
    if (!setupGlfw()) {
        return -1;
    }
    if (!setupGlew()) {
        return -1;
    }
    // testing purposes
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    cout << "Maximum nr of vertex attributes supported: " << nrAttributes << '\n';
    return 0;
}

int StarkBase::run() {
    for (GLFWkeyfun callback : registeredCallbacks) {
        glfwSetKeyCallback(window, callback);
    }
    objectManager.initializeObjects();
    
    // draw the object each iteration
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        objectManager.redrawObjects();
        glfwSwapBuffers(window);
    }
    
    objectManager.deallocateObjects();
    glfwTerminate();
    return 0;
}

GraphicsObject* StarkBase::createNewGraphicsObject(vector<Vector3> vertices, vector<int> indices) {
    return objectManager.createNewGraphicsObject(vertices, indices);
}

void StarkBase::setKeyCallback(void callback(GLFWwindow* window, int key, int scancode, int action, int mode)) {
    // TODO: what if callback cant be cast to GLFWkeyfun check
    registeredCallbacks.push_back(static_cast<GLFWkeyfun>(callback));
}


// Private methods

bool StarkBase::setupGlfw() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    window = glfwCreateWindow(windowWidth, windowHeight, windowLabel, nullptr, nullptr);
    if (window == nullptr) {
        cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    return true;
}

bool StarkBase::setupGlew() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        cout << "Failed to initialize GLEW\n";
        return false;
    }
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    return true;
}
