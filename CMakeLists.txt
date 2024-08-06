cmake_minimum_required(VERSION 3.10)

# Project Name
project(ipc_project)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/ipc.cpp
    src/registry.cpp
    main.cpp
)

# Executable
add_executable(ipc_example ${SOURCES})

# Link pthread library (for mutex)
target_link_libraries(ipc_example pthread)
