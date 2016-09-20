cmake_minimum_required(VERSION 3.2)

# Name of the project (will be the name of the plugin)
project (LinkNode)


# Boost dependency

# Include BoostLib module
file(GLOB_RECURSE boostlib_cmake_path "${CMAKE_CURRENT_SOURCE_DIR}/node_modules" "BoostLib.cmake")
list(GET boostlib_cmake_path 0 boostlib_cmake_path)

get_filename_component(boostlib_cmake_path "${boostlib_cmake_path}" DIRECTORY)
SET(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${boostlib_cmake_path}")
include(BoostLib)

# Essential include files to build a node addon,
# you should add this line in every CMake.js based project.
include_directories(${CMAKE_JS_INC})

# Declare the location of the source files
file(GLOB SOURCE_FILES "node-link.cc")
