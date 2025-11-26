cmake_minimum_required(VERSION 3.28)

# Project name and language
project(sim LANGUAGES CXX C)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party")

#SDL 3
add_subdirectory(${THIRD_PARTY_DIR}/SDL3 EXCLUDE_FROM_ALL)

#GLM 1.0.2
add_subdirectory(${THIRD_PARTY_DIR}/glm EXCLUDE_FROM_ALL)


set(INCLUDE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/"

    "${THIRD_PARTY_DIR}/glad/include/"
)

set(LIBS
    SDL3::SDL3
    glm
)

file(GLOB LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp

    ${THIRD_PARTY_DIR}/glad/src/glad.c
)

# Add the executable
add_executable(sim
    ${LIB_SRC}
)


target_link_libraries(sim PRIVATE ${LIBS})

target_include_directories(sim PRIVATE ${INCLUDE_DIRS})
