cmake_minimum_required(VERSION 3.10.0)

# Set vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/strel/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(Root VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_DOUBLE_PRECISION ON CACHE BOOL "" FORCE)

add_subdirectory(vendor/assimp)
add_subdirectory(vendor/imgui-cmake)

add_subdirectory(core)
add_subdirectory(demo)

function(set_output_dirs target)
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib
    )
endfunction()

set_output_dirs(Engine)
set_output_dirs(Demo)