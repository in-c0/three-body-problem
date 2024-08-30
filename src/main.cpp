#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "vulkan_setup.h"

class three_body_simulation { 
public:
    void run() {
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    VulkanSetup vulkan;
    GLFWwindow* window;

    void createGraphicsPipeline() {
        // Create Vulkan graphics pipeline (vertex/fragment shaders, etc.)
    }

    void drawFrame() {
        // Commands to render a frame, update vertex buffers with new body positions
    }

    void initVulkan() {            
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            glfwTerminate();
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = glfwCreateWindow(800, 600, "Three Body Simulation", nullptr, nullptr);
        if (!window) {
            glfwTerminate();
            return;
        }

        vulkan.init(window);

    }

    void mainLoop() {            
        while (!glfwWindowShouldClose(window)) {
            // Render stuff here

            glfwPollEvents();
            drawFrame();
        }
    }

    void cleanup() {
        vulkan.cleanup();
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    
    three_body_simulation app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;    
}
