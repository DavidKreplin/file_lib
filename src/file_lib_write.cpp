#include "file_lib.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void write_string(std::string path, std::string &data) {

   std::ofstream file;
   file.open(path.c_str(),std::ios::app);

   if (file.is_open()) {
      file << data.c_str();
      file.close();
   } 
   else {
      throw std::runtime_error("File could not be opendd");
   } 
   return;
}
