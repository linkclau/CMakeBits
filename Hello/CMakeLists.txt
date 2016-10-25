# To compile:
#   mkdir hello_build
#   cd hello_build
#   cmake -G "Unix Makefiles" ../Hello/
#   make

#cmake_minimum_required (VERSION 2.8.11)
#project (HELLO)

# Example from:
#   https://cmake.org/examples/
# Add executable called "hello" that is built from the source files
# "hello.cpp".  The extensions are automatically found.
add_executable (hello hello.cpp)


