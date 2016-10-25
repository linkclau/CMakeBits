cmake_minimum_required (VERSION 2.8.11)
project ( Visibility )


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# The syntax is a bit archaic
add_library(simpleLib_objects OBJECT simplelib.cpp simplelib_base.cpp)

# The  $<TARGET_OBJECTS:*> is a generator-expressions
# See
#   https://cmake.org/cmake/help/v3.0/manual/cmake-generator-expressions.7.html
add_library (lib_static STATIC lib.cpp )
target_include_directories (lib_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/static)

add_library (lib_shared SHARED lib.cpp )
target_include_directories (lib_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/shared)

add_executable (use_shared use_shared.cpp)
target_link_libraries (use_shared LINK_PUBLIC lib_shared)

