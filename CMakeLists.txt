cmake_minimum_required(VERSION 3.16)
project(ThreeBodySimulation LANGUAGES CXX Fortran)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_Fortran_COMPILER gfortran)

find_package(Vulkan REQUIRED)

set(FORTRAN_SOURCES
    fortran/three_body.f90
)

# Add submodules
add_subdirectory(third_party/glfw)

# Add executable with your source files
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/vulkan_setup.cpp
    src/vulkan_setup.h
    ${FORTRAN_SOURCES}
)

include_directories(
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    third_party/glfw/include
)

# Link Vulkan and GLFW libraries
target_link_libraries(${PROJECT_NAME}
    ${Vulkan_LIBRARIES}
    glfw
    Vulkan::Vulkan
)

# Testing setup (GoogleTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_executable(runTests
    tests/test_main.cpp
)
target_link_libraries(runTests gtest_main)

add_test(
    NAME ExampleTest
    COMMAND runTests
)