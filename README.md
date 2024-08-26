# Three-body-problem
A real-time simulation of the three-body problem using Fortran, wrapped in C++ and rendered with Vulkan.


## Overview
### Project Structure
```
three-body-simulation/
├── CMakeLists.txt                       # CMake build configuration
├── README.md            
├── LICENSE             
├── src/                 
│   ├── main.cpp                         # Entry point for the application
│   ├── vulkan_renderer.cpp   
│   ├── vulkan_renderer.h     
│   ├── fortran_wrapper.cpp   
│   ├── fortran_wrapper.h     
│   ├── imgui_setup.cpp       
│   ├── imgui_setup.h        
├── include/             
├── fortran/             
│   ├── three_body.f90   
├── shaders/             
│   ├── raytrace.rgen.spv  
│   ├── raytrace.rmiss.spv 
│   ├── raytrace.rchit.spv 
├── assets/              
└── third_party/                        # External libraries (e.g., GLFW, GLM, Dear ImGui)
```

![image](https://github.com/user-attachments/assets/e82e1fc2-c26a-4bc9-b989-976cfd26509a)


## Prerequisites

To build and run this project, you need the following dependencies installed:

- **CMake** (version 3.10 or higher)
- **Fortran Compiler** (e.g., gfortran)
- **Vulkan SDK** (including Vulkan libraries and drivers)
- **GLFW** (for window management)
- **GLM** (for mathematics)
- **Dear ImGui** (for the GUI interface)

## Building the Project

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/yourusername/three-body-simulation.git
    cd three-body-simulation
    ```

2. **Set up the Build Directory:**

    ```bash
    mkdir build
    cd build
    ```

3. **Generate the Build Files with CMake:**

    ```bash
    cmake ..
    ```

4. **Build the Project:**

    ```bash
    make
    ```


### Setting Up Dependencies

Dependencies are included in the third_party directory, but you can also add them as a separate submodule:

- **Vulkan SDK**: Download and install the Vulkan SDK from [LunarG Vulkan SDK](https://vulkan.lunarg.com/).
- **GLFW** and **GLM**: These can be downloaded and included in the `third_party/` directory, or you can use package managers like `vcpkg` or `conan` to manage them.
- **Dear ImGui**: You can include Dear ImGui in the `third_party/` directory or fetch it as a submodule.

Example:
```
git submodule add https://github.com/glfw/glfw.git third_party/glfw
git submodule add https://github.com/ocornut/imgui.git third_party/imgui
git submodule update --init --recursive
```



## Running the Simulation

After building, you can run the simulation by executing the binary from the `build` directory:

```bash
./three_body_simulation
```

## Contributing

Contributions are welcome! If you find bugs or have suggestions for improvements, feel free to create issues or submit pull requests.

1. **Fork the repository**.
2. **Create a new branch** (`git checkout -b feature-branch`).
3. **Make your changes**.
4. **Commit your changes** (`git commit -m 'Add some feature'`).
5. **Push to the branch** (`git push origin feature-branch`).
6. **Open a pull request**.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Vulkan](https://vulkan.lunarg.com/) - The graphics API used.
- [Dear ImGui](https://github.com/ocornut/imgui) - For the immediate mode GUI.
- [GLFW](https://www.glfw.org/) - For window and input management.
- [GLM](https://glm.g-truc.net/0.9.9/index.html) - For math operations.

## Contact

If you have any questions, feel free to reach out to the repository owner at [wldud5192@gmail.com](mailto:wldud5192@gmail.com).

