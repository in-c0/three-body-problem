#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "vulkan_setup.h"


void createGraphicsPipeline() {
    // Create Vulkan graphics pipeline (vertex/fragment shaders, etc.)
}

void drawFrame() {
    // Commands to render a frame, update vertex buffers with new body positions
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Three Body Simulation", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    VulkanSetup vulkan;
    vulkan.init(window);


    while (!glfwWindowShouldClose(window)) {
        // Render stuff here

        glfwPollEvents();
        drawFrame();
    }


    // Cleanup
    vulkan.cleanup();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
