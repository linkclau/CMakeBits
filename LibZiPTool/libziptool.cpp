// Little program using libzip
//    https://nih.at/libzip/
// Requires the instalation of libzip-dev

#include <zip.h>

#include <iostream>

int main( int argc, char** argv ) {
  if( argc < 3 ) {
    // Usage
    return 1;
  }
  int result=0;
  // The Ubuntu version doesn't suppoer ZIP_TRUNCATE
  zip *archive = zip_open( argv[1], ZIP_CREATE|ZIP_EXCL , &result);
  if( result != 0 ) {
    char error[256]="";
    zip_error_to_str( error, 256, 0, result);
    std::cerr << error << std::endl;
    return 1;
  }

  struct zip_source *s;
  char buffer[1024*1024*10]="";
  s=zip_source_buffer(archive, buffer, sizeof(buffer), 0);
  if (s == nullptr ) {
    //printf("error open source: %s", zip_strerror(archive));
    return 1;
  }

  for( int i = 2; i<argc; ++i) {
    std::cout << i << ": " << argv[i] << std::endl;
    zip_add( archive, argv[i], s);
  }
  zip_source_free(s);
  
  if( zip_close( archive ) != 0 ) {
    // chekc the error code in the archive
    std::cerr << zip_strerror(archive) << std::endl;
    return 2;
  }
  return 0;
}
