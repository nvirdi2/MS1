#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt) {
       string user_input;
       bool needInt = true;
       bool invalidInt;
       bool notOnlyInt;
       unsigned i;
       if (prompt != nullptr) cout << prompt; 
       getline(cin, user_input);
       while (needInt) {
           invalidInt = false;
           notOnlyInt = false;
           if(!isdigit(user_input.c_str()[0])) invalidInt = true;
           for (i = 0; i < user_input.length() && !invalidInt && !notOnlyInt; i++) {
               if (!isdigit(user_input.c_str()[i]) && i != 0) notOnlyInt = true;
           }
           if (invalidInt) {
               cout << "Bad integer value, try again: ";
               getline(cin, user_input);
           }
           if (notOnlyInt) {
               cout << "Enter only an integer, try again: ";
               getline(cin, user_input);
           }
           if (!invalidInt && !notOnlyInt) needInt = false;
       }

       return atoi(user_input.c_str());
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
       int userInput = getInt(prompt);
       bool invalid = true;
       while (invalid) {
           if (userInput >= min && userInput <= max) invalid = false;
           else {
               if (errorMessage != nullptr) cout << errorMessage;
               else getInt(prompt);
               if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
               userInput = getInt();
           }
       }
       return userInput;
   }

   char* getcstr(const char* prompt, istream& istr, char delimiter) {
       string str;
       char* cstr;
       if (prompt != nullptr) cout << prompt;

       getline(istr, str);
       cstr = new char[str.length() + 1];
       strcpy(cstr, str.c_str());
       return cstr;
   }
}
