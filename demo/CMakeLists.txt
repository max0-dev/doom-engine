cmake_minimum_required(VERSION 3.10.0)

project(Demo VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Demo src/main.cpp)

target_link_libraries(Demo PRIVATE Engine)