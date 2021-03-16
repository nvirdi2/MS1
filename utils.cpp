#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
//#include "cstring.h"
#include "utils.h"
#include "Time.h"

using namespace std;
namespace sdds {
const int size = 5;
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

     int strLen(const char* s)
    {
        int lenght = 0;
        int x;

        for (x = 0; s[x] != 0; x++)
        {
            lenght++;
        } return (lenght);
    }


int getInt(){
    
    char entry[size] {};
    
    string str;
 
    getline(cin, str);
    for(int i = 0; i < size; i++){
        entry[i] = str[i];
    }
    //cout << "proverka stroki " << entry << endl;
    
    int check = 1;
    bool symbol = 0;
    int symbolcounter = 0;
    int temp = atoi(entry);

    
    do {
    long int x = sdds::strLen(entry);
    int counter = 0;
        //cout << "проверка длины " << sizeof(entry) << endl;
        
    for (int i = 0; entry[i] != '\0'; i++){
        if(std::isdigit(entry[i]) && !isspace(entry[i])) counter++;
        else {symbolcounter++; symbol = 1;}
    }
        
            //если не все знаки = цифры, просим ещё циферок
        if (counter != x || temp == 0 || symbol == 1){
            
            if (symbol == 1 && symbolcounter > 0 && counter > 0){
                cout << "Enter only an integer, try again: ";
            }
            
            else if (counter != x || temp == 0){
                cout << "Bad integer value, try again: ";
            }
            
            for(int i=0;i<size;i++){entry[i] = '\0';}
            
            //повторный ввод
            //cin >> entry;
            
            symbol = 0;
            
            getline(cin, str);
            for(int i = 0; i < size; i++){
                entry[i] = str[i];
            }
            temp = atoi(entry);
        }
            //если все цифры, то всё ок "приятного пути"
        else{
            check = 0;
        }
    } while (check != 0);
    
    int result = atoi(entry);
    for( int i = 0; i < size; i++){
        entry[i] = '\0';
        str[i] = '\0';
    }
    return result;
};

int getInt(const char* prompt){
    cout << *prompt;
    int result = getInt();
    return result;
}

int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError){
    
    int num = getInt(prompt);
    
    while (max < num || num < min) {
        if (errorMessage != nullptr) cout << errorMessage;
        if (showRangeAtError) cout << "[" << min << " <= value <= " << max<< "]: ";
        //cout << "checker 3: " << num << endl;
        num = getInt();
    }
    return num;
 };

    char* getcstr(const char* prompt, std::istream& istr, char delimiter){
    
    cout << prompt;
    string input;
    getline(istr, input);
    
    char *text = new char[input.length()];
    text[input.length()] = delimiter; // последний знак
        for (int i = 0; i < input.length(); i++) {
            text[i] = input[i];
        }
        return text;
    }
}
