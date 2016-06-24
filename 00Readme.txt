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
If verbos is set, the option becomens <Whatever>.SILENT which is not known to Make
and therfore ignored.
  
TO build the subprojects
   (cd build/ &&  cmake -G "Unix Makefiles" .. && make)

