#include "file_lib.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

void read_string(std::string path, std::string &data) {

   std::ifstream file;
   file.open (path);

   if (file.is_open()) {
	   std::stringstream buffer;
	   buffer << file.rdbuf();
	   data = buffer.str();
   } 
   else {
      throw std::runtime_error("File could not be loaded");
   } 
   file.close();
   return;
}
