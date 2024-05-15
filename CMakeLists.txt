cmake_minimum_required(VERSION 3.8)
project(AdventOfCode)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Set source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/Advent-Of-Code)

# Find all source files in the directory and its subdirectories
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Add executable
add_executable(AdventOfCode ${SOURCES})

# Install the executable
install(TARGETS AdventOfCode
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)
