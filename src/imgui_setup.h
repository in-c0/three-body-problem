#pragma once
#include "vulkan_renderer.h"
#include <GLFW/glfw3.h>

class ImGuiSetup {
public:
    void init(GLFWwindow* window, VulkanRenderer& renderer);
    void render();
    void cleanup();
};
