cmake_minimum_required(VERSION 3.10.0)

# Set vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/strel/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(DoomEngine VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(assimp STATIC IMPORTED)

set_target_properties(assimp PROPERTIES
    IMPORTED_LOCATION
        "${CMAKE_SOURCE_DIR}/vendor/assimp/lib/x64/assimp-vc143-mt.lib"
    INTERFACE_INCLUDE_DIRECTORIES
        "${CMAKE_SOURCE_DIR}/vendor/assimp/include"
)

add_subdirectory(core)
add_subdirectory(vendor/imgui)
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