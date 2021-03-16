#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow() { m_min = getTime(); return *this; } //cout << "check setToNow(): " << m_min / 60 << ":" << m_min - m_min / 60 * 60;  m_min = getTime();  cout << "check: getTime() " << m_min / 60 << ":" << m_min - m_min / 60 * 60 << "check end" << endl;
    Time::Time(unsigned int min) { m_min = min; } //cout << m_min << endl;

    std::ostream& Time::write(std::ostream& ostr) const { return cout; }
    std::istream& Time::read(std::istream& istr) { 
        
        string input, hourString, minuteString;
        istr >> input;

        istr.setstate(std::ios_base::goodbit);//std::ios_base::

        for (int i = 0; i < input.length(); i++) {

            if (input[i] == ':' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9' || input[i] == '0'){
                //continue;
            }
            else {
                //std::cout << input[i] << endl; //// x
                istr.setstate(std::ios_base::failbit);
                return istr;  
            }
        }
                      //std::cout <<"!!!!  data  is good, input is: "<< input << endl; //// x

        for (int i = 0; i < input.length(); i++) { // write input in to hour/minutes string - transfer to write function

            if(input[i] == ':') { // do nothing while havnig ":" sign (avoid it)

                hourString = input.substr(0, i);
                i++;                                                                  // cout << "$$" << i << endl;  // x
                minuteString = input.substr(i, (input.length() - 1));
                                                                                  // cout << "$$" << i << endl;  /// x
                break;// i = input.length(); // block the looping
            } 
        }            //std::cout << " check hourString:" << hourString << "minuteString:" << minuteString << endl;   /// DISLAY h / m 
                    
        unsigned hours, minutes;

        hours = stoi(hourString.c_str()); minutes = stoi(minuteString.c_str());
                    //std::cout << " check hours:" << hours << "minutes:" << minutes << endl;   /// DISLAY h / m 
        m_min = hours*60 + minutes;

        //istr << m_min;///////
                    //std::cout << "check  m_min:" << m_min << endl; /// DISLAY m_min
        return istr;
    }

    /// #################################### STOI ################################
    unsigned Time::stoi(const char* s) {

        unsigned i = 0;

        while (*s >= '0' && *s <= '9'){
            i = i * 10 + (*s - '0');
            s++;
        }
        return i;
    }
    /// #################################### STACK OVERFLOW ################################
    Time& Time::operator=(unsigned int val) { m_min = val; return *this; }
    Time& Time::operator *= (unsigned int val) { m_min = m_min * val; return *this; }
    Time& Time::operator /= (unsigned int val) { m_min = m_min / val; return *this; }
    Time Time::operator *(unsigned int val)const { Time Temp; Temp.m_min = m_min; Temp.m_min = m_min * val; return Temp; }
    Time Time::operator /(unsigned int val)const { Time Temp; Temp.m_min = m_min; Temp.m_min = m_min / val; return Temp; }
    Time Time::operator+(const Time& Input)const { Time TempThis; TempThis.m_min = m_min + Input.m_min; return TempThis; }
    Time& Time::operator+=(const Time& Input) { *this = m_min + Input.m_min; return *this; }
    Time Time::operator-(const Time& Input)const { Time TempThis, TempOut; TempThis.m_min = m_min; TempOut.m_min= Input.m_min; while (Input.m_min > TempThis.m_min){ TempThis.m_min += 1440;} TempOut.m_min = TempThis.m_min - Input.m_min; return TempOut; }
    Time& Time::operator-=(const Time& Input) { Time TempThis, TempOut; TempThis.m_min = m_min; while (Input.m_min > TempThis.m_min) { TempThis.m_min += 1440; } *this = TempThis.m_min - Input.m_min; return *this; }

    Time::operator unsigned int()const { return 0; }
    Time::operator int()const { int output = m_min;  return output; }

    std::ostream& operator<<(std::ostream& ostr, const Time& O) { O.view(ostr); return ostr; }
    std::ostream& Time::view(std::ostream& ostr)const {
        // ***cout << m_min;
        //cout << "cheeeeeeeeeeek: " << m_min / 60 << ":" << m_min - m_min / 60 * 60;

        unsigned int hours = m_min / 60;
        unsigned int minutes = m_min - hours * 60;

                       //cout << "TIME: " <<hours << ":" << minutes << endl;
        //if(hours < 10) { ostr << 0; };
        //ostr << hours << ":"; if (minutes < 10) { ostr << 0; }; ostr << minutes; //<<m_min;//
        
        if (hours < 10) { cout << 0; };
        cout << hours << ":"; if (minutes < 10) { cout << 0; }; ostr << minutes; //<<m_min;//
        //string output;
        //output.append(hours, minutes);
        //cout << "appended sting" << output << endl;
        //ostr << output;
        return ostr;
        
    }
    std::istream& operator>>(std::istream& istr, Time& Object_for_Input) { 
        
        Object_for_Input.read(istr);

        return istr;
    }
}
