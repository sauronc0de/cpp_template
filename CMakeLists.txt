cmake_minimum_required(VERSION 3.16)
set(ProjectName "DnT4")
project(${ProjectName} LANGUAGES C CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER "/usr/bin/clang" CACHE INTERNAL "C compiler")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE INTERNAL "C++ compiler")

# Clang as a compiler
SET (CMAKE_C_COMPILER             "/usr/bin/clang")
SET (CMAKE_C_FLAGS                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")
SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find the SDL2 package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Add defines of project
add_definitions(-DASSETS_PATH="${CMAKE_SOURCE_DIR}/assets")

# Internal libraries
add_subdirectory(libraries/rendering_system)

# External libraries
# add_subdirectory(external)

# Examples
# add_subdirectory(examples/SDL2_hellow_world)
add_subdirectory(examples/rendering_system)

# Executable
add_executable(${ProjectName} src/main.cpp)
target_link_libraries(${ProjectName} PRIVATE SDL2::SDL2)