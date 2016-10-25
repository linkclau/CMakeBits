Experimenting with VIsibility and dllex-/-import

This is not really a CMake specific test but rather a Windows/Linux(ELF) test.
Nevertheless CMake hopefully makes this test much easier.

http://gcc.gnu.org/wiki/Visibility
https://www.akkadia.org/drepper/dsohowto.pdf


When creating a DLL on Windows (using  __declspec(dllexport) ) you 
can not create a static and dynamic library from the same object files.
http://stackoverflow.com/questions/4841719/dllimport-dllexport-and-static-libraries-compilation-under-visual-c


== Linux

Linux/GCC Supports for classes of Visibility
Two  commonly used
STV_DEFAULT - Symbols defined with it will be exported. In other words, it declares that symbols are visible everywhere.
STV_HIDDEN - Symbols defined with it will not be exported and cannot be used from other objects.

and ELF specific
STV_PROTECTED: The symbol is visible outside the current executable or shared object, but it may not be overridden. In other words, if a protected symbol in a shared library is referenced by an other code in the shared library, the other code will always reference the symbol in the shared library, even if the executable defines a symbol with the same name.
STV_INTERNAL: The symbol is not accessible outside the current executable or shared library.
