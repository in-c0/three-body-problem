cmake_minimum_required(VERSION 3.10)
project(ThreeBodySimulationVulkan)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_Fortran_COMPILER "C:/msys64/mingw64/bin/gfortran.exe")
# set(CMAKE_Fortran_FLAGS "-Wall -g")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/glm)
include_directories(${CMAKE_SOURCE_DIR}/third_party/imgui)
include_directories(${CMAKE_SOURCE_DIR}/third_party/glfw/include)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Add GLFW
add_subdirectory(third_party/glfw)

# Add ImGui
add_library(imgui STATIC
    third_party/imgui/imgui.cpp
    third_party/imgui/imgui_draw.cpp
    third_party/imgui/imgui_tables.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/backends/imgui_impl_glfw.cpp
    third_party/imgui/backends/imgui_impl_vulkan.cpp
)

# Include directories for ImGui
target_include_directories(imgui PUBLIC third_party/imgui third_party/imgui/backends)

# Shader Compilation
file(GLOB SHADER_SOURCES "${CMAKE_SOURCE_DIR}/shaders/*.glsl")

set(SPIRV_BINARIES "")

foreach(SHADER ${SHADER_SOURCES})
    get_filename_component(SPIRV_OUTPUT_FILE ${SHADER} NAME_WE)
    set(SPIRV_OUTPUT_FILE "${CMAKE_SOURCE_DIR}/shaders/${SPIRV_OUTPUT_FILE}.spv")

    # Add only if it does not exist yet
    if(NOT TARGET ${SPIRV_OUTPUT_FILE})
        add_custom_command(
            OUTPUT ${SPIRV_OUTPUT_FILE}
            COMMAND glslangValidator -V ${SHADER} -o ${SPIRV_OUTPUT_FILE}
            DEPENDS ${SHADER}
            COMMENT "Compiling ${SHADER} to SPIR-V..."
        )
        list(APPEND SPIRV_BINARIES ${SPIRV_OUTPUT_FILE})
    endif()
endforeach()

if(SPIRV_BINARIES)
    add_custom_target(compile_shaders ALL DEPENDS ${SPIRV_BINARIES})
endif()

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

# Ensure shaders are compiled before building the executable
if(SPIRV_BINARIES)
    add_dependencies(${PROJECT_NAME} compile_shaders)
endif()

# Link Vulkan, GLM, and other necessary libraries
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw imgui)
