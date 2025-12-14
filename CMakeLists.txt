cmake_minimum_required(VERSION 3.10.0)

# Set vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/strel/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(DoomEngine VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(vendor/imgui)
add_subdirectory(demo)