⚠️As of 26/08/2024, the project is in WIP and may not be functioning as described
### TODO
- Complete CMake configuration
- Set up tests for the app initialisation/library integration
- Implement a UI slider for parameter 'n' for n body simulation

#### Sources of Inspiration:
- https://www.youtube.com/watch?v=VVIPjRxDKHc 
- https://www.youtube.com/watch?v=tOlKLJ4WmSE&t=373s
- https://www.youtube.com/watch?v=GjbcvqEOIuE

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

Follow the [installation guide](#installation-guide) for detailed instructions and continue to building the project once all the prerequisites are installed on your machine.

## Building the Project

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/in-c0/three-body-simulation.git
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


## Installation Guide
[](#installation-guide)

### 1. CMake (version 3.10 or higher)
CMake is a cross-platform build system that helps manage the build process of software using a simple, platform-independent configuration file.

#### Installation:
- **Linux**: Install via your package manager (e.g., `sudo apt-get install cmake` for Ubuntu).
- **macOS**: Install via Homebrew: `brew install cmake`.
- **Windows**: Download and install from the [official website](https://cmake.org/download/).

### 2. Fortran Compiler
A Fortran compiler is required to compile the Fortran source code.

#### Recommended: gfortran
- **Linux**: Install via your package manager (e.g., `sudo apt-get install gfortran` for Ubuntu).
- **macOS**: Install via Homebrew: `brew install gcc` (gfortran is included).
- **Windows**: Install via [MinGW](http://www.mingw.org/) or [Cygwin](https://www.cygwin.com/).

### 3. Vulkan SDK
The Vulkan SDK includes the Vulkan libraries, drivers, and development tools needed for building Vulkan applications.

#### Installation:
- **Linux**: Download the latest version from the [LunarG Vulkan SDK](https://vulkan.lunarg.com/sdk/home).
- **macOS**: Download the latest version from the [LunarG Vulkan SDK](https://vulkan.lunarg.com/sdk/home). Note that Vulkan support on macOS is provided through MoltenVK.
- **Windows**: Download and install from the [LunarG Vulkan SDK](https://vulkan.lunarg.com/sdk/home).

### Setting Up Dependencies

The following dependencies are already included in the `third_party` directory: 
- **GLFW**
- **GLM**
- **Dear ImGui**

you can choose to add new dependencies or use package managers like `vcpkg` or `conan` to manage them.

Example:
```
git submodule add https://github.com/glfw/glfw.git third_party/glfw
git submodule add https://github.com/g-truc/glm.git third_party/glm
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

- [LunarG Vulkan SDK](https://vulkan.lunarg.com/) - Graphics API
- [Dear ImGui](https://github.com/ocornut/imgui) - GUI
- [GLFW](https://www.glfw.org/) - Input management
- [GLM](https://glm.g-truc.net/0.9.9/index.html) - Math utilities

## Contact

If you have any questions, feel free to reach out to the repository owner at [wldud5192@gmail.com](mailto:wldud5192@gmail.com).

