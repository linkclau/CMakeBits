To build the subprojects
   (cd build/ &&  cmake -G "Unix Makefiles" .. && make)

After creating the configuration for the generator. E.g. with

  cmake -G "Unix Makefiles"  ..

you can call the generator directly through cmake with
  
  cmake --build .


Do see all the commands as they are executed you can call

  cmake --build . -- VERBOSE=1
or
  make VERBOSE=1
 
Actually this is a nice Make Idiom

  # Suppress display of executed commands.
  $(VERBOSE).SILENT:

If VERBOSE is not set the .SILENT option is activated.
If verbos is set, the option becomens <Whatever>.SILENT 
which is not known to Make and therfore ignored.

Use Clang and the compiler

  cmake -G "Unix Makefiles" \
    -DCMAKE_CXX_COMPILER=clang++-3.7 \
    -DCMAKE_CC_COMPILER=clang-3.7 \
    ..

Build different modes
   -DCMAKE_BUILD_TYPE=Debug ..


##########################################################
# CTest
##########################################################
Feels a bit basic and applicable only in theory, 
for more or less trivial programms.
Addapting a program to the way ctest works is IMHO the same order of
magnitude like adding Unit Tests.
But you pay the performace overhead of executing the programm again and again.


  cpack --config CPackConfig.cmake -G DEB

  cpack --help

shows the supported generators.


