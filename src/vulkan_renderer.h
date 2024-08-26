#pragma once
#include <GLFW/glfw3.h>

class VulkanRenderer {
public:
    bool init(GLFWwindow* window);
    void drawFrame();
    void cleanup();
};
