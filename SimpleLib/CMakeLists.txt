# Example from:
#   http://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-version-of-the-sam
add_library (simplelib_default simplelib.cpp)
add_library (simplelib SHARED simplelib.cpp)
add_library (simplelib_static STATIC simplelib.cpp)
# Ste the name to match the dynamic name
set_target_properties(simplelib_static PROPERTIES OUTPUT_NAME simplelib)
