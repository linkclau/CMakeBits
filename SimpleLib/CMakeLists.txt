cmake_minimum_required(VERSION 2.8.11)

# Example from:
#   http://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-version-of-the-sam
# Doing it like this it turns out every targes has it's complete own set of objects
# So every source is compiled 3 time.
#
# Object libraries can be used to avoid this
# See:
#   https://cmake.org/Wiki/CMake/Tutorials/Object_Library
# But then xou need to compile to position-independent code

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# The syntax is a bit archaic
add_library(simpleLib_objects OBJECT simplelib.cpp simplelib_base.cpp)

# The  $<TARGET_OBJECTS:*> is a generator-expressions
# See
#   https://cmake.org/cmake/help/v3.0/manual/cmake-generator-expressions.7.html
add_library (simplelib_default $<TARGET_OBJECTS:simplelib_objects>)
add_library (simplelib SHARED $<TARGET_OBJECTS:simplelib_objects>)
add_library (simplelib_static STATIC $<TARGET_OBJECTS:simplelib_objects>)
# Set the name to match the dynamic name
set_target_properties(simpleLib_static PROPERTIES OUTPUT_NAME simpleLib)

# Objects can't be dependencies.
#add_library (simpleLib_other SHARED simpleLib.o)

# Define the include directory for usage through CMake from other projects
# This needs to be done after the target is defined.
target_include_directories (simpleLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

