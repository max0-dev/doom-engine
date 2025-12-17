cmake_minimum_required(VERSION 3.10.0)

project(Demo VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Demo src/main.cpp)
target_sources(Demo PRIVATE src/DemoLayer.cpp)
target_include_directories(Demo PRIVATE src/include)

target_compile_definitions(Demo PUBLIC ASSIMP_BUILD_NO_EXPORT)

target_link_libraries(Demo PRIVATE Engine)