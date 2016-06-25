project (MathFunctions)

# does this system provide the log and exp functions?
include (CheckFunctionExists)
# Distinguish the system type. See
#   https://cmake.org/Wiki/CMake_Useful_Variables
# UNIX 
#  is TRUE on all UNIX-like OS's, including Apple OS X and CygWin
# WIN32 
#  is TRUE on Windows. Prior to 2.8.4 this included CygWin
# APPLE 
#  is TRUE on Apple systems. 
#   Note this does not imply the system is Mac OS X
#   Check IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") for Mac OS X
IF(UNIX)
  #set(CMAKE_REQUIRED_INCLUDES "math.h")
  set(CMAKE_REQUIRED_LIBRARIES "m")
ENDIF(UNIX)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

configure_file (
  "${PROJECT_SOURCE_DIR}/MathFunctionsConfig.h.in"
  "${PROJECT_BINARY_DIR}/MathFunctionsConfig.h"
  )
# We need this to find the generated header file
include_directories("${PROJECT_BINARY_DIR}/")

# first we add the executable that generates the table
add_executable(MakeTable MakeTable.cxx)
 
# add the command to generate the source code
add_custom_command (
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )
 
# add the binary tree directory to the search path for 
# include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )
 
# add the main library
add_library(MathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h )


install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)
