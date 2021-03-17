#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   extern bool debug;
   int getInt(const char* prompt = nullptr);
   int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);
   char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');
   int getTime();
}
#endif // !SDDS_UTILS_H_

