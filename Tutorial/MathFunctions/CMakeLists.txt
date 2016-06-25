project (MathFunctions)

# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

configure_file (
  "${PROJECT_SOURCE_DIR}/MathFunctionsConfig.h.in"
  "${PROJECT_BINARY_DIR}/MathFunctionsConfig.h"
  )
# We need this to find the generated header file
include_directories("${PROJECT_BINARY_DIR}/")

add_library(MathFunctions mysqrt.cxx)

install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)
