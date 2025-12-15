## Requirements ##
-vcpkg
-cmake
-Ninja
-C++20

## Packages ##
-glfw
-glew
-imgui
-spdlog

## Install Packages ##
!note - set the vcpkg toolchain in the root cmake file
vpckg install --triplet (target platform e.q. x64-windows)
