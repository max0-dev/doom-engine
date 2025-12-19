cmake_minimum_required(VERSION 3.10.0)

project(Editor VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Editor src/main.cpp)

file(GLOB_RECURSE EDITOR_SOURCES 
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

target_sources(Editor PRIVATE ${EDITOR_SOURCES})
target_include_directories(Editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_link_libraries(Editor PRIVATE Engine)