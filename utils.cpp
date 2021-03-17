#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug{false};
    int getInt(const char *prompt)
    {
        string userEntry;
        bool intFlag{true};
        bool notInt;
        bool voidInt;
        unsigned i;
        if (prompt != nullptr)
            cout << prompt;
        getline(cin, userEntry);
        while (intFlag)
        {
            voidInt = false;
            notInt = false;
            if (!isdigit(userEntry.c_str()[0]))
                voidInt = true;
            for (i = 0; i < userEntry.length() && !voidInt && !notInt; i++)
            {
                if (!isdigit(userEntry.c_str()[i]) && i != 0)
                    notInt = true;
            }
            if (voidInt)
            {
                cout << "Bad integer value, try again: ";
                getline(cin, userEntry);
            }
            if (notInt)
            {
                cout << "Enter only an integer, try again: ";
                getline(cin, userEntry);
            }
            if (!voidInt && !notInt)
                intFlag = false;
        }

        return atoi(userEntry.c_str());
    }

    int getInt(int min, int max, const char *prompt, const char *errorMessage, bool showRangeAtError)
    {
        int userInput = getInt(prompt);
        bool invalid{true};
        while (invalid)
        {
            if (userInput <= max && userInput >= min)
                invalid = false;
            else
            {
                if (errorMessage != nullptr)
                    cout << errorMessage;
                else
                    getInt(prompt);
                if (showRangeAtError)
                    cout << "[" << min << " <= value <= " << max << "]: ";
                userInput = getInt();
            }
        }
        return userInput;
    }

    char *getcstr(const char *prompt, istream &istr, char delimiter)
    {
        char *cstr;
        string str;
        if (prompt != nullptr)
            cout << prompt;

        getline(istr, str);
        cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        return cstr;
    }

    int getTime()
    {
        int mins{-1};
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do
            {
                cin.clear();
                cin >> t;
                if (!cin)
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
}
