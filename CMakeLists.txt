#
# Copyright (c) 2018, 2019 Amine Ben Hassouna <amine.benhassouna@gmail.com>
#
# Permission is hereby granted, free of charge, to any
# person obtaining a copy of this software and associated
# documentation files (the "Software"), to deal in the
# Software without restriction, including without
# limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of
# the Software, and to permit persons to whom the Software
# is furnished to do so, subject to the following
# conditions:
#
# The above copyright notice and this permission notice
# shall be included in all copies or substantial portions
# of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
# ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
# SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
# IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#

# Define the project name
SET(PROJECT_NAME retro_engine)
project("${PROJECT_NAME}")

# Set the cmake minimum version to 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# Settings
set(CMAKE_CXX_STANDARD 23)

# Add SDL2 CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

#Source and Binaries
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/bin")
SET (PROJECT_RES_DIR "${PROJECT_SOURCE_DIR}/res")
SET (PROJECT_GAME_DIR "${PROJECT_SOURCE_DIR}/game")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}")

# Configure Dependencies Directories
SET (PROJECT_GAME_DIR "${PROJECT_SOURCE_DIR}/game")
SET (PROJECT_FRAMEWORK_DIR "${PROJECT_SOURCE_DIR}/framework")
SET (PROJECT_GRAPHIC_DIR "${PROJECT_FRAMEWORK_DIR}/graphic")

# Files
file(GLOB SOURCES "src/*.cpp")
file(GLOB SOURCE_GAME_DIR ${PROJECT_GAME_DIR}/*.cpp)
file(GLOB SOURCE_FRAMEWORK_FILES ${PROJECT_FRAMEWORK_DIR}/*.cpp)
file(GLOB SOURCE_GRAPHIC_DIR ${PROJECT_FRAMEWORK_DIR}/graphic/*.cpp)

add_executable(
        ${PROJECT_NAME}
        ${SOURCES}
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${SOURCE_FRAMEWORK_FILES}
        ${SOURCE_GRAPHIC_DIR}
        ${SOURCE_GAME_DIR}
        )



# Add all headers files under the include directory
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Add compiler errors/warnings flags
target_compile_options(${PROJECT_NAME} PRIVATE $<$<C_COMPILER_ID:MSVC>:/W4 /WX>)
#target_compile_options(${PROJECT_NAME} PRIVATE $<$<NOT:$<C_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<NOT:$<C_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>)

# Configure Dependencies Directories
SET (PROJECT_GAME_DIR "${PROJECT_SOURCE_DIR}/game")
SET (PROJECT_FRAMEWORK_DIR "${PROJECT_SOURCE_DIR}/framework")
SET (PROJECT_GRAPHIC_DIR "${PROJECT_FRAMEWORK_DIR}/graphic")

# Directories
include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_BINARY_DIR}
        ${PROJECT_ROOT}
        ${PROJECT_SOURCE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIR}
)

# Add SDL2 library
find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main)

# Add SDL2_image library
find_package(SDL2_image REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Image)


# Add SDL2_ttf library
#find_package(SDL2_ttf REQUIRED)
#target_link_libraries(${PROJECT_NAME} SDL2::TTF)

# Add SDL2_net library
#find_package(SDL2_net REQUIRED)
#target_link_libraries(${PROJECT_NAME} SDL2::Net)

# Add SDL2_mixer library
#find_package(SDL2_mixer REQUIRED)
#target_link_libraries(${PROJECT_NAME} SDL2::Mixer)

# Add SDL2_gfx library
#find_package(SDL2_gfx REQUIRED)
#target_link_libraries(${PROJECT_NAME} SDL2::GFX)

