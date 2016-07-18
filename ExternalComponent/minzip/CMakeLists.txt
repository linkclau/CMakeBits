cmake_minimum_required (VERSION 2.8.11)
project ( Minzip )
# CMake 2.8 not yet support specifying the version directly IVERSION 1.0.1) 
set (Minzip_VERSION_MAJOR 1)
set (Minzip_VERSION_MINOR 01e)
set (Minzip_VERSION ${Minzip_VERSION_MAJOR}.${Minzip_VERSION_MINOR})

# It turns out that we are not using the minzip version from
#
# but from the contrubution section of
#   http://www.zlib.net/
# or
#   https://github.com/madler/zlib
# 
# The changes we introduced seem to be quit unneccessary
# CBEXP_CBMINIZIP can be simply replaced by defining ZEXPORT accordingly


message( "Version ${Minzip_VERSION}" )

SET( Minzip_HEADER ioapi.h unzip.h zip.h )

add_library(minzip ioapi.c unzip.c zip.c ${Minzip_HEADER} )

install (TARGETS minzip DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)


