cmake_minimum_required (VERSION 2.8.11)
project (USESIMPLELIB)

# Example from:
#   https://cmake.org/examples/
# Add executable called "hello" that is built from the source files
# "hello.cpp".  The extensions are automatically found.
add_executable (useSimpleLib useSimpleLib.cpp)

target_link_libraries (useSimpleLib LINK_PUBLIC simpleLib)



