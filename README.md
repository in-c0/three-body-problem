⚠️As of 26/08/2024, the project is in WIP and may not be functioning as described
### TODO
- ~~Complete CMake configuration~~
- Set up tests for the app initialisation/library integration
- Implement a UI slider for parameter 'n' for n body simulation

#### Sources of Inspiration:
- https://pavelsevecek.github.io/
- https://github.com/pavelsevecek/OpenSPH
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

2. **Build the Project:**

    To build the project, simply run the provided `build.sh` script by typing:
    ```bash
     ./build.sh
    ```
    See [Build Troubleshooting Guide](#troubleshooting) for more.

## Testing
We are using [Gtest]([url](https://github.com/google/googletest)) for basic testing. Test files are located in the `tests/` directory.

Example:
```cpp
#include <gtest/gtest.h>

// Example test
TEST(InitializationTest, BasicTest) {
    // Replace this with actual initialization code
    ASSERT_TRUE(true);  // Example assertion
}

```

### How to Run Tests

After building the project, you can run the tests using `ctest`:

```sh
mkdir build
cd build
cmake ..
cmake --build .
ctest
```

## [Installation Guide](#installation-guide)

Recommended setup (for Windows): WSL and Ubuntu (22.04 LTS):
- [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
- [Ubuntu (22.04)](https://ubuntu.com/download#products)
(WSL allows developers install a Linux distribution (such as Ubuntu) on Windows.)

### 1. Open Ubuntu and Navigate to the cloned project directory
If your project is located in the Windows file system (e.g. `C:\Users\YourName\yourproject`), you can access them from WSL/Ubuntu under:
```
/mnt/c/Users/YourName/yourproject
```

### 2.Install and Update Dependencies
You can install them by typing the following commands:
```bash
 sudo apt-get install gfortran
 sudo apt-get install build-essential
 sudo apt install -y vulkan-utils libvulkan-dev
 sudo apt install xz-utils
 sudo apt install qtbase5-dev qtwayland5
```
This will install GFortran, CMake and Vulkan SDK on your WSL Ubuntu environment.


Alternatively, you can download via:
[GFortran]([url](https://fortran-lang.org/learn/os_setup/install_gfortran/)) - A Fortran compiler is required to compile the Fortran source code.
[CMake]([url](https://cmake.org/download/)) (version 3.10 or higher) - CMake is a cross-platform build system that helps manage the build process of software using a simple, platform-independent configuration file.
[Vulkan]([url](https://vulkan.lunarg.com/doc/sdk/1.3.290.0/linux/getting_started.html)) - The Vulkan SDK includes the Vulkan libraries, drivers, and development tools needed for building Vulkan applications.

If any of these commands fails, ensure your system is up-to-date:
```
 sudo apt update
 sudo apt upgrade
```

If you're not on the latest Ubuntu LTS version (e.g., 22.04 LTS), you can upgrade by:
 ```
 sudo do-release-upgrade
 ```

If this doesn't fix the issue, consider re-installing WSL and Ubuntu by following these steps:
 1. Open PowerShell or Command Prompt and run:
 3. Uninstall the current Ubuntu distribution:
     ```
     wsl --unregister Ubuntu
     ```     
     (or check `wsl --list --verbose` for specific distribution name to unregsiter)
 4. Reinstall Ubuntu LTS:
     ```
     wsl --install -d Ubuntu-22.04
     ```

### 3. Now you should be able to build the project by navigating to the project root directory and typing:
 
 ```
  ./build.sh
 ```

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


## Troubleshooting
[](#troubleshooting)

### Troubleshooting Build
`./build.sh` runs a shell script built for Unix-based systems only. 

If you see a permission error, you can manually set it by:
```
 chmod +x build.sh
```

If, at any point, manual building using CMake is required, you can trigger it by:
```bash
cmake -B build
```    
This will create a new `/build` directory under your root project directory.
If you encounter any error during the build process, make sure that the build directory is clean before triggering a build.
The following command will **remove everything** in the build directory:
  ```
 cd build
 rm -rf *
 cd ..
 cmake -B build
 ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [LunarG Vulkan SDK](https://vulkan.lunarg.com/) - Graphics API
- [Dear ImGui](https://github.com/ocornut/imgui) - GUI
- [GLFW](https://www.glfw.org/) - Input management
- [GLM](https://glm.g-truc.net/0.9.9/index.html) - Math utilities

## Contact

If you have any questions, feel free to reach out to the repository owner at [wldud5192@gmail.com](mailto:wldud5192@gmail.com).

