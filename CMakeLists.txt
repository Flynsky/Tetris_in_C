cmake_minimum_required(VERSION 3.10) # Minimum CMake version required

project(Tetris_in_C) # Name of your project

# Set C++ standard (optional)
# set(CMAKE_CXX_STANDARD 11)

# Add an executable target named 'my_project'
add_executable(Tetris_in_C
    src/main.cpp # Source files for the executable
)

# Add precompiled headers
target_precompile_headers(Tetris_in_C PRIVATE src/precompiled.h)