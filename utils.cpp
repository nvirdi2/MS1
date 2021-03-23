// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: March 16, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

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

    int getTime()
    {
        int minutes {-1};

        if (debug)
        {
            Time x(0);

            cout << "Enter current time: ";
                do
                {
                    cin.clear();
                    cin >> x;

                        if (!cin)
                        {
                            cout << "Invlid time, try agian (HH:MM): ";
                            cin.clear();
                        }

                            else
                            {
                                minutes = int(x);
                            }
                    cin.ignore(1000, '\n');

                } while (minutes < 0);
        }
        
        else
        {
            time_t x = time(NULL);

            tm i = *localtime(&x);

            minutes = i.tm_hour * 60 + i.tm_min;
        } return minutes;
    }


    int getInt(const char *prompt)
    {
        int check = 0;
        bool num_found = false;
        int num;

        if (prompt != nullptr)
            cout << prompt;
        string line;
        getline(cin, line);
        line = line + '\n';
        bool neg = false;

        while (check == 0 || check == 1) {
            num = 0;
            int i = 0;
            neg = false;
            num_found = false;
            while (line[i]) {
                if (line[i] == '-')
                    neg = true;
                else if (line[i] < '0' || line[i] > '9') {
                    if (num_found == false) {
                        cout << "Oye Hoye: " << line[i] << endl;
                        check = 0;
                    }

                    else if (line[i] == '\n')
                        check = 2;
                    else
                        check = 1;
                    break;
                }

                else {
                    num_found = true;
                    num = num * 10 + line[i] - '0';
                }

                i++;
            }

            if (neg)
                num = 1 * num;
            if (check != 2) {
                if (check == 0)
                    cout << "Bad integer value, try again: ";
                else
                    cout << "Enter only an integer, try again: ";
                getline(cin, line);
                line = line + '\n';
            }
        }

        return num;
    }

    char *getcstr(const char *prompt, istream &istr, char delimiter)
    {
        char *cstr;

        string tmp;

        if (prompt != nullptr)
        {
            cout << prompt;
        }

        getline(istr, tmp);

        cstr = new char[tmp.length() + 1];

        strcpy(cstr, tmp.c_str());
        
        return cstr;
    }

    int getInt(int min, int max, const char *prompt, const char *errorMessage, bool showRangeAtError)
    {
        int check = 0;
        bool num_found = false;
        int num;

        if (prompt != nullptr)
            cout << prompt;
        string line;
        getline(cin, line);
        line = line + '\n';
        bool neg = false;

        while (check == 0 || check == 1) {
            neg = false;
            num = 0;
            int i = 0;
            num_found = false;

            while (line[i]) {
                if (line[i] == '-')
                    neg = true;
                else if (line[i] < '0' || line[i] > '9') {
                    if (num_found == false)
                        check = 0;
                    else if (line[i] == '\n')
                        check = 2;
                    else
                        check = 1;
                    break;
                }

                else {
                    num_found = true;
                    num = num * 10 + line[i] - '0';
                }

                i++;
            }

            if (neg)
                num = -1 * num;
            if (check != 2) {
                if (check == 0)
                    cout << "Bad integer value, try again: ";
                else
                    cout << "Enter only an integer, try again: ";
                getline(cin, line);
                line = line + '\n';
            }

            else if (num < min || num > max) {
                check = 1;
                if (errorMessage != nullptr)
                    cout << errorMessage;
                if (showRangeAtError) {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }

                getline(cin, line);
                line = line + '\n';
            }
        }
        return num;
    }
}
