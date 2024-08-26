#include "vulkan_renderer.h"
#include "imgui_setup.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Three Body Simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Initialize Vulkan Renderer
    VulkanRenderer renderer;
    if (!renderer.init(window)) {
        std::cerr << "Failed to initialize Vulkan Renderer" << std::endl;
        return -1;
    }

    // Initialize Dear ImGui
    ImGuiSetup imgui;
    imgui.init(window, renderer);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        renderer.drawFrame();
        imgui.render();

        glfwSwapBuffers(window);
    }

    // Cleanup
    imgui.cleanup();
    renderer.cleanup();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
