#ifndef __FILE_OPERATION_H__
#define __FILE_OPERATION_H__
#include <string>
void  test();
bool readFile(const char* fileName, zmArray::Array<std::string, 5ul>& words);
bool readFileToMap(const char* fileName, Map<std::string, int>& map);
#endif
