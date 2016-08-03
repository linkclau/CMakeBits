cmake_minimum_required (VERSION 2.8)
project ( CMakeGTests )

find_package(Threads REQUIRED)


message( "CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")
message( "ENV{CMAKE_MODULE_PATH} $ENV{CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "first1 firts2" "another1" "another2")
list( APPEND CMAKE_MODULE_PATH  $ENV{CMAKE_MODULE_PATH} )
message( "CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")
SET(TESTDIR "${CMAKE_SOURCE_DIR}/path with blanks" )
list( APPEND CMAKE_MODULE_PATH  ${TESTDIR} "d2" "d3")
message( "CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")


enable_testing()
set( GTEST_ROOT /home/clink/Programming/CMakeBits/ExternalComponent/googletest )
find_package(GoogleTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(cMakeGTests someTest.cpp )
target_link_libraries(cMakeGTests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )

add_test(AllTestsBits cMakeGTests)
