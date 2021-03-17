#include <cmath>
#include <string>
#include <cstring>
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds {
	Time& Time::setToNow() {
		*this = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	ostream& Time::write(ostream& ostr)const {
		double hour = 0;
		double min;
		if (m_min >= 60) hour = floor(m_min / 60);
		min = m_min - (60 * hour);
		ostr.width(2);
		ostr.fill('0');
		ostr << hour;
		ostr << ":";
		ostr.width(2);
		ostr.fill('0');
		ostr << min;
		return ostr;
	}

	istream& Time::read(istream& istr) {
		string hours;
		string minutes;
		char c_input = '\0';
		string user_input;

		istr >> user_input;



		for (unsigned i = 0; i < user_input.length(); i++) {
			c_input = user_input[i];
			if (!(c_input == ':' || c_input == '0' || c_input == '1' || c_input == '2' || c_input == '3' || c_input == '4' || c_input == '5' || c_input == '6' || c_input == '7' || c_input == '8' || c_input == '9')) {
				istr.setstate(std::ios_base::failbit);
				return istr;
			}
		}

		for (unsigned i = 0; i < user_input.length(); i++) {
			c_input = user_input[i];
			if (c_input == ':') {
				hours = user_input.substr(0, i);
				i++;
				minutes = user_input.substr(i, (user_input.length() - 1));
				break;
			}
		}

		m_min = (stoi(hours.c_str()) * 60) + stoi(minutes.c_str());

		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		if (m_min > D.m_min) m_min -= D.m_min;
		else {
			double hour= 0, min, d_hour = 0, d_min;

			if (m_min >= 60) hour = floor(m_min / 60);
			min = m_min - (60 * hour);
			if (D.m_min >= 60) d_hour = floor(D.m_min / 60);
			d_min = D.m_min - (60 * d_hour);

			if (min < d_min) {
				min += 60;
				min -= d_min;
				hour--;
			}
			else min -= d_min;

			double addTime = ceil(d_hour / 24);
			hour += 24.0 * addTime;
			hour -= d_hour;
			m_min = int(min + (hour * 60));
		}

		return *this;
	}

	Time Time::operator-(const Time& D)const {
		Time temp(m_min);
		temp -= D;
		return temp;
	}

	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const {
		Time temp(m_min);
		temp += D;
		return temp;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val){
		m_min *= val;
		return *this;
	}

	Time Time::operator*(unsigned int val)const {
		Time temp(m_min);
		temp *= val;
		return temp;
	}

	Time& Time::operator/=(unsigned int val) {
		m_min /= val;
		return *this;
	}

	Time Time::operator/(unsigned int val)const {
		Time temp(m_min);
		temp /= val;
		return temp;
	}

	Time::operator int()const {
		return int(m_min);
	}

	Time::operator unsigned int()const {
		return m_min;
	}

	ostream& operator<<(ostream& ostr, const Time& D) {
		D.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Time& D) {
		D.read(istr);
		return istr;
	}
}
