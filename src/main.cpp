#define GLFW_INCLUDE_VULKAN
#include <iostream>
#include <stdexcept>
#include <GLFW/glfw3.h>
#include "vulkan_setup.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

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
    VkInstance instance;

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
        window = glfwCreateWindow(WIDTH, HEIGHT, "Three Body Simulation", nullptr, nullptr);
        if (!window) {
            glfwTerminate();
            return;
        }

        vulkan.init(window);

        createInstance();

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

    void createInstance() {
        // VkApplicationInfo is optional and is useful for the driver to optimise our specific application
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Three Body Simulation";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Custom Vulkan-based Engine by In-c0";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        // VkInstanceCreateInfo is not optional and tells the Vulkan driver which global extensions and validation layers we want to use.
        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        // GLFW provides extension for Vulkan to interface with the window system
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;

        // Most Vulkan functions return a VkResult object with value VK_SUCCESS or an error code.
        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance!");
        }
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
