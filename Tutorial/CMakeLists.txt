cmake_minimum_required (VERSION 2.6)
project (Tutorial)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# should we use our own math functions?
option (USE_MYMATH "Use tutorial provided math implementation" ON) 
# Options can be switche when generating the build files (-G) via
#  -DUSE_MYMATH=[yes/no|on/off|true/false|1/0] 

 
# configure a header file to pass some of the CMake settings
# to the source code
## Is there no naming convention? Can I use any two files?
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  ## From the naming I would expect this to override the previous setting
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)
 
# add the executable
add_executable (tutorial tutorial.cxx)
target_link_libraries (tutorial  ${EXTRA_LIBS})


############################################################
# Install
############################################################
# add the install targets
# Generating the build files you can specify the prefix through 
#   CMAKE_INSTALL_PREFIX
# (default is /usr/local) E.g.:
#   cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/xyz ..
# With unix Makefiles you can set the destination 
# under which the prefix is rooted. E.g.:
#   DESTDIR=/tmp make install
# or
#   make DESTDIR=/tmp install
# ??? I wonder what is the difference? 
# ??? I uspsect the first is passed to recursive make call 
# ??? as it is part of the environment
# which would lead to an install under
#   /tmp/xyz/
install (TARGETS tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

############################################################
# Test
############################################################
include(CTest)
 
#define a macro to simplify adding tests, then use it
# ??? What about multiline output?
macro (test_if_sqrt_matches arg result)
  add_test (TutorialComp_${arg} tutorial ${arg})
  set_tests_properties (TutorialComp_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (test_if_sqrt_matches)
 
macro (test_if_sqrt_is arg result)
  test_if_sqrt_matches( ${arg} "${arg} is ${result}")
endmacro (test_if_sqrt_is arg result)

# does the application run 
# verifies that the application runs, 
# does not segfault or otherwise crash, 
# and has a zero return value
# ??? Not sure if this is the same on Windows
add_test (TutorialRuns tutorial 25) 

# does it sqrt of 25 
test_if_sqrt_is( 25 5 )

# does it handle negative numbers 
# Intentionally fail
test_if_sqrt_is( -25 0 )

# does it handle small numbers 
test_if_sqrt_is( 0.0001 0.01 )

# does the usage message work? 
# Empty strings are not passed as args  to the SUT
# Adding a space would pass it to the SUT
test_if_sqrt_matches( "" "Usage:.*number")


# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)
