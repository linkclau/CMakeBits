cmake_minimum_required (VERSION 2.8.11)
project (UseSimpleLib)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_PATH}:${CMAKE_MODULE_PATH}") 

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_PREFIX}") 

message( "UseSimpleLib ${PROJECT_SOURCE_DIR} " )
message( "INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} " )
get_property( INCLUDE_DIRECTORIES DIRECTORY PROPERTY INCLUDE_DIRECTORIES ) 
message( "INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} " )
#include_directories ("${PROJECT
# Example from:
#   https://cmake.org/examples/
# Add executable called "hello" that is built from the source files
# "hello.cpp".  The extensions are automatically found.
add_executable (useSimpleLib useSimpleLib.cpp)

target_link_libraries (useSimpleLib LINK_PUBLIC simpleLib)



