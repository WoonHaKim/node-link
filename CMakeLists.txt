cmake_minimum_required(VERSION 3.2)

# Name of the project (will be the name of the plugin)
project(node-link)

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

# This line will tell CMake that we're building a shared library
# from the above source files
# named after the project's name
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

# This line will give our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


# Essential library files to link to a node addon,
# you should add this line in every CMake.js based project.
# Define Boost dependencies there.
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB};${Boost_LIBRARIES})


include(link/AbletonLinkConfig.cmake)
target_link_libraries(${PROJECT_NAME} Ableton::Link)

# Declare the location of the source files
file(GLOB SOURCE_FILES "node-link.cc")
