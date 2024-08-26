cmake_minimum_required(VERSION 3.10)
project(ThreeBodySimulationVulkan)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/imgui)
include_directories(${CMAKE_SOURCE_DIR}/third_party/glfw/include)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/vulkan_renderer.cpp
    src/fortran_wrapper.cpp
    src/imgui_setup.cpp
)

# Fortran source files
enable_language(Fortran)
set(FORTRAN_SOURCES
    fortran/three_body.f90
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${FORTRAN_SOURCES})

# Link Vulkan and other necessary libraries
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw imgui)
