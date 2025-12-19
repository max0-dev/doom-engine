cmake_minimum_required(VERSION 3.10.0)

project(Engine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ENGINE_SOURCES 
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Static library
add_library(Engine STATIC 
    ${ENGINE_SOURCES}
)

# Include headers
target_include_directories(Engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    ${Stb_INCLUDE_DIR}
)

target_precompile_headers(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/std_common.h
)

# Find dependencies
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)

# Link dependencies
target_link_libraries(Engine PUBLIC
    spdlog::spdlog
    glfw
    GLEW::GLEW
    imgui::imgui
    glm::glm
    assimp::assimp
)