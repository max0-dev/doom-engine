cmake_minimum_required(VERSION 3.10.0)

project(Engine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Static library
add_library(Engine STATIC 
    src/Application.cpp
    src/Shader.cpp
    src/Window.cpp
)

# Include headers
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Find dependencies
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)

# Link dependencies
target_link_libraries(Engine PUBLIC spdlog::spdlog glfw GLEW::GLEW)