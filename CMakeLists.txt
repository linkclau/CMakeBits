#cmake_minimum_required (VERSION 3.0)
#project ( CMakeBits VERSION 1.2.3)
cmake_minimum_required (VERSION 2.8)
project ( CMakeBits )

# Required below CMake 2.8.11?
# No, not sure why I thought this was required
#include_directories ("${PROJECT_SOURCE_DIR}/SimpleLib")
#link_directories ( ${PROJECT_BINARY_DIR}/SimpleLib )
#
#message( "BUIDLID ${BUILDID}" )
#
#get_property( INCLUDE_DIRECTORIES DIRECTORY PROPERTY INCLUDE_DIRECTORIES ) 
#message( "INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} " )

add_subdirectory (Hello)
add_subdirectory (SimpleLib)
add_subdirectory (UseSimpleLib )
