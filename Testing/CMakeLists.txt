cmake_minimum_required (VERSION 2.8)
project ( CMakeGTests )

find_package(Threads REQUIRED)

enable_testing()
set( GTEST_ROOT /home/clink/Programming/CMakeBits/ExternalComponent/googletest )
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(cMakeGTests someTest.cpp )
target_link_libraries(cMakeGTests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )

add_test(AllTestsBits cMakeGTests)
