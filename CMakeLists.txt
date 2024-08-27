cmake_minimum_required(VERSION 3.10)
project(ThreeBodySimulation LANGUAGES CXX Fortran)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Vulkan REQUIRED)

set(FORTRAN_SOURCES
    fortran/three_body.f90
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    ${FORTRAN_SOURCES}
)

include_directories(
    ${Vulkan_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    ${Vulkan_LIBRARIES}
)

set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -O2")
