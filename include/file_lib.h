#ifndef _FILE_LIB_H
#define _FILE_LIB_H

#include <string>

/** @defgroup rwl_group Read and Write Library 
 *  The library file_lib provied functions to read or write strings into a file.
 *  @{
 */

/** @brief Reads a file into a string
 *
 * @param path Path to the file
 * @param data Returns the content of the file specified in path.
 */
void read_string(std::string path, std::string &data);

/** @brief Writes a string into the file
 *
 * If the file exist, the string is attached at the end of the file
 *
 * @param path Path to the file
 * @param data String, which is writen into the file
 */
void write_string(std::string path, std::string &data);


/** @} */

#endif
