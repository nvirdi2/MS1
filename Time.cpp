// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: March 16, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cmath>
#include <string>

#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    Time &Time::setToNow()
    {
        *this = getTime();
            return (*this);
    }
    
    Time::Time(unsigned int minutes)
    {
        m_minutes = minutes;
    }

    ostream &Time::write(ostream &ostr) const
    {
        double Hours = 0;
        double Mins;

            if (m_minutes >= 60)
            {  
                Hours = floor(m_minutes / 60);
            }
        Mins = m_minutes - (60 * Hours);

            ostr.width(2);
            ostr.fill('0');

            ostr << Hours;

            ostr << ":";

            ostr.width(2);
            ostr.fill('0');

            ostr << Mins;

        return ostr;
    }

    istream &Time::read(istream &istr)
    {
        char Input = '\0';
        unsigned x;
        string Mins;
        string Hours;
        string inputFromUser;

        istr >> inputFromUser;

            for (unsigned x = 0; x < inputFromUser.length(); x++)
            {
                Input = inputFromUser[x];

                if (!(Input == ':' || Input == '0' || Input == '1' || Input == '2' ||
                     Input == '3' || Input == '4' || Input == '5' || Input == '6' ||   
                     Input == '7' || Input == '8' || Input == '9'))
                {
                    istr.setstate(std::ios_base::failbit);
                    return istr;
                }
            }

            for (x = 0; x < inputFromUser.length(); x++)
            {
                Input = inputFromUser[x];

                if (Input == ':')
                {
                    Hours = inputFromUser.substr(0, x);
                    x++;
                    Mins = inputFromUser.substr(x, (inputFromUser.length() - 1));
                    break;
                }
            }

        m_minutes = (stoi(Hours.c_str()) * 60) + stoi(Mins.c_str());
            return istr;
    }


    Time &Time::operator=(unsigned int val)
    {
        m_minutes = val;
            return *this;
    }

    Time &Time::operator*=(unsigned int val)
    {
        m_minutes *= val;
            return *this;
    }

    Time &Time::operator/=(unsigned int val)
    {
        m_minutes /= val;
            return *this;
    }



    ostream &operator<<(ostream &ostr, const Time &D)
    {
        D.write(ostr);
            return ostr;
    }

    istream &operator>>(istream &istr, Time &D)
    {
        D.read(istr);
            return istr;
    }



    Time::operator unsigned int() const
    {
        return m_minutes;
    }

    Time::operator int() const
    {
        return int(m_minutes);
    }



    Time &Time::operator+=(const Time &D)
    {
        m_minutes += D.m_minutes;
        return *this;
    }

    Time Time::operator+(const Time &D) const
    {
        Time tmp(m_minutes);
            tmp += D;
                return tmp;
    }



    Time Time::operator-(const Time &D) const
    {
        Time tmp(m_minutes);
        tmp -= D;
        return tmp;
    }

    Time Time::operator*(unsigned int val) const
    {
        Time tmp(m_minutes);
            tmp *= val;
                return tmp;
    }

    Time Time::operator/(unsigned int val) const
    {
        Time tmp(m_minutes);
            tmp /= val;
                return tmp;
    }


    Time &Time::operator-=(const Time &D)
    {
        if (m_minutes > D.m_minutes)
        {
            m_minutes -= D.m_minutes;
        }
            else
            {
                double hour = 0;
                double min;
                double Hours = 0;
                double Mins;

            if (m_minutes >= 60)
            {
                Hours = floor(m_minutes / 60);
            }
                Mins = m_minutes - (60 * Hours);


            if (D.m_minutes >= 60)
            {
                hour = floor(D.m_minutes / 60);
            }
                min = D.m_minutes - (60 * hour);

                if (Mins < min)
                {
                    Mins += 60;
                    Mins -= min;
                    Hours--;
                }
                else
                {
                    Mins -= min;
                }

            double ttime = ceil(hour / 24);

            Hours += 24.0 * ttime;
            Hours -= hour;

            m_minutes = int(Mins + (Hours * 60));
        } return *this;
    }

}
