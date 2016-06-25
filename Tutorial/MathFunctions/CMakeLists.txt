project (MathFunctions)

# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

configure_file (
  "${PROJECT_SOURCE_DIR}/MathFunctionsConfig.h.in"
  "${PROJECT_BINARY_DIR}/MathFunctionsConfig.h"
  )

add_library(MathFunctions mysqrt.cxx)

install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)
