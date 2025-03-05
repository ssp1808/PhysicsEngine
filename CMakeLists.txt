cmake_minimum_required(VERSION 3.10)

# Set the project name
project(PhysicsEngine)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ensure MSVC is used
if (MSVC)
    message(STATUS "Compiling with MSVC")
    add_compile_options(/W4)  # Enable warnings for MSVC
endif()

# Collect all source files
file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/GUI/Classes/*.cpp"
    "${PROJECT_SOURCE_DIR}/Math/Classes/*.cpp"
    "${PROJECT_SOURCE_DIR}/Object/Classes/*.cpp"
    "${PROJECT_SOURCE_DIR}/Main.cpp"
)

# Collect all header files
file(GLOB_RECURSE HEADERS 
    "${PROJECT_SOURCE_DIR}/GUI/Headers/*.h"
    "${PROJECT_SOURCE_DIR}/Math/Headers/*.h"
    "${PROJECT_SOURCE_DIR}/Object/Headers/*.h"
)

# Create the executable
add_executable(PhysicsEngine ${SOURCES})

# Include directories
target_include_directories(PhysicsEngine PRIVATE 
    ${PROJECT_SOURCE_DIR}/GUI/Headers
    ${PROJECT_SOURCE_DIR}/Math/Headers
    ${PROJECT_SOURCE_DIR}/Object/Headers
)

# Enable debug symbols if building in debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(PhysicsEngine PRIVATE /Zi /Od)
endif()
