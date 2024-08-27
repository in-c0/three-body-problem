#include <iostream>
#include <vulkan/vulkan.h>

extern "C" void compute();  // Declaration of Fortran function

int main() {
    std::cout << "Hello from C++!" << std::endl;
    compute();  // Call Fortran subroutine
    return 0;
}
