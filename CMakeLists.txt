cmake_minimum_required(VERSION 3.10.0)

# Set vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/strel/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(Template VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(Template src/main.cpp)

target_sources(Template PRIVATE src/test.cpp)
target_include_directories(Template PRIVATE src/test.h)

# Link libraries
target_link_libraries(Template PRIVATE fmt::fmt spdlog::spdlog)