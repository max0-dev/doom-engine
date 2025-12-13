cmake_minimum_required(VERSION 3.10.0)

# Set vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/strel/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(DoomEngine VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)

add_executable(DoomEngine src/main.cpp)

# Link libraries
target_link_libraries(DoomEngine PRIVATE fmt::fmt spdlog::spdlog glfw GLEW::GLEW)