cmake_minimum_required (VERSION 2.8.11)
project ( Thrift )

include(ExternalProject)

set_property(DIRECTORY PROPERTY EP_STEP_TARGETS configure build test)

#URL http://www-eu.apache.org/dist/thrift/0.9.3/thrift-0.9.3.tar.gz
#ExternalProject_Add( Thrift
#  URL ${CMAKE_SOURCE_DIR}/thrift-0.9.3.tar.gz
#  INSTALL_DIR /tmp/thrift-0.9.3
#  CONFIGURE_CMD "./configure --prefix=INSTALL_DIR"
#  )
#INSTALL_COMMAND echo Install manually 

message( "SOURCE_DIR ${CMAKE_SOURCE_DIR}/SimpleMake/ ")

ExternalProject_Add( SimpleMake
  DOWNLOAD_COMMAND "" 
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/SimpleMake

  CONFIGURE_CMD " "
)
