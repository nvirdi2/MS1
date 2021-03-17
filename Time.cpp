#include <cmath>
#include <string>
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    Time::Time(unsigned int minutes)
    {
        m_minutes = minutes;
    }

    Time &Time::setToNow()
    {
        *this = getTime();
        return *this;
    }

    ostream &Time::write(ostream &ostr) const
    {
        double hour = 0;
        double minutes;
        if (m_minutes >= 60)
            hour = floor(m_minutes / 60);
        minutes = m_minutes - (60 * hour);
        ostr.width(2);
        ostr.fill('0');
        ostr << hour;
        ostr << ":";
        ostr.width(2);
        ostr.fill('0');
        ostr << minutes;
        return ostr;
    }

    istream &Time::read(istream &istr)
    {
        string hours;
        string minutes;
        char cInput = '\0';
        string user_input;

        istr >> user_input;

        for (unsigned i = 0; i < user_input.length(); i++)
        {
            cInput = user_input[i];
            if (!(cInput == ':' || cInput == '0' || cInput == '1' || cInput == '2' || cInput == '3' || cInput == '4' || cInput == '5' || cInput == '6' || cInput == '7' || cInput == '8' || cInput == '9'))
            {
                istr.setstate(std::ios_base::failbit);
                return istr;
            }
        }

        for (unsigned i = 0; i < user_input.length(); i++)
        {
            cInput = user_input[i];
            if (cInput == ':')
            {
                hours = user_input.substr(0, i);
                i++;
                minutes = user_input.substr(i, (user_input.length() - 1));
                break;
            }
        }

        m_minutes = (stoi(hours.c_str()) * 60) + stoi(minutes.c_str());

        return istr;
    }

    Time &Time::operator-=(const Time &D)
    {
        if (m_minutes > D.m_minutes)
            m_minutes -= D.m_minutes;
        else
        {
            double hour = 0, minutes, d_hour = 0, d_min;

            if (m_minutes >= 60)
                hour = floor(m_minutes / 60);
            minutes = m_minutes - (60 * hour);
            if (D.m_minutes >= 60)
                d_hour = floor(D.m_minutes / 60);
            d_min = D.m_minutes - (60 * d_hour);

            if (minutes < d_min)
            {
                minutes += 60;
                minutes -= d_min;
                hour--;
            }
            else
                minutes -= d_min;

            double addTime = ceil(d_hour / 24);
            hour += 24.0 * addTime;
            hour -= d_hour;
            m_minutes = int(minutes + (hour * 60));
        }

        return *this;
    }

    Time Time::operator-(const Time &D) const
    {
        Time temp(m_minutes);
        temp -= D;
        return temp;
    }

    Time &Time::operator+=(const Time &D)
    {
        m_minutes += D.m_minutes;
        return *this;
    }

    Time Time::operator+(const Time &D) const
    {
        Time temp(m_minutes);
        temp += D;
        return temp;
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

    Time Time::operator*(unsigned int val) const
    {
        Time temp(m_minutes);
        temp *= val;
        return temp;
    }

    Time Time::operator/(unsigned int val) const
    {
        Time temp(m_minutes);
        temp /= val;
        return temp;
    }

    Time::operator unsigned int() const
    {
        return m_minutes;
    }

    Time::operator int() const
    {
        return int(m_minutes);
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
}
