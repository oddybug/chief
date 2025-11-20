cmake_minimum_required(VERSION 3.28)

# Project name and language
project(sim LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(sim
    src/main.cpp
)

