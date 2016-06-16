# Example from:
#   https://cmake.org/examples/
# Add executable called "hello" that is built from the source files
# "hello.cpp".  The extensions are automatically found.
add_library (simplelib_default simplelib.cpp)
add_library (simplelib SHARED simplelib.cpp)
add_library (simplelib_static STATIC simplelib.cpp)
