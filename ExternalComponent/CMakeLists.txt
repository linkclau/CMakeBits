cmake_minimum_required (VERSION 2.8.11)
project ( ExternalComponent )

include(ExternalProject)

set_property(DIRECTORY PROPERTY EP_STEP_TARGETS configure build test)

#ExternalProject_Add( Thrift
#  #URL http://www-eu.apache.org/dist/thrift/0.9.3/thrift-0.9.3.tar.gz
#  #URL ${CMAKE_SOURCE_DIR}/thrift-0.9.3.tar.gz
#  DOWNLOAD_COMMAND "" 
#  SOURCE_DIR ${CMAKE_SOURCE_DIR}/thrift
#  INSTALL_DIR /tmp/thrift-0.9.3
#  INSTALL_COMMAND echo Install manually 
#  )
# Thrift caused an error as the CMakeLists.txt used CPP (instead of CXX)
# as language.
add_subdirectory( thrift )

message( "SOURCE_DIR ${CMAKE_SOURCE_DIR}/SimpleMake/ ")

ExternalProject_Add( SimpleMake
  DOWNLOAD_COMMAND "" 
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/SimpleMake
  CONFIGURE_COMMAND ""
  BUILD_IN_SOURCE 1
  # Don't install
  INSTALL_COMMAND ""
)

ExternalProject_Add( re2
  GIT_REPOSITORY https://github.com/google/re2.git
  GIT_TAG 2016-07-01
  #INSTALL_COMMAND echo "Install manually"
  INSTALL_DIR /tmp/re2-2016-07-01
)

add_subdirectory ( googletest )
