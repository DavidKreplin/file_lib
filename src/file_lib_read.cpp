#include "file_lib.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void read_string(const char *path, std::string &data) {

   std::ifstream file;
   file.open (path);

   if (file.is_open()) {
      file.seekg(0,std::ios::end);
      int length = file.tellg();
      file.seekg(0,std::ios::beg);
      char* buffer  = new char [length];
      file.read (buffer,length);
      data.append(buffer,length);
      delete buffer;
   } 
   else {
      throw std::runtime_error("File could not be loaded");
   } 
   file.close();
   return;
}
