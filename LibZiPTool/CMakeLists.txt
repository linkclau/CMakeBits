cmake_minimum_required (VERSION 2.8.11)
project ( LibZiPTool )

list( APPEND CMAKE_CXX_FLAGS -std=c++11 )
#set (CMAKE_CXX_STANDARD 11)
# add_compile_options(-std=c++11)

#find_package
add_executable (libzip libziptool.cpp )
target_link_libraries (libzip  zip )

