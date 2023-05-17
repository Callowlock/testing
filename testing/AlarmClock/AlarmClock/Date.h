#ifndef DATE_
#define DATE_
#include "Time.h"
#include <string>
using namespace std;

class Date {
    private:
        int _year;
        int _day;
        int _month;
        bool _leapYear;
        Time* _time;
    public:
        Date(const int& month, const int& day, const int& year);
        void setDate(const int& month, const int& day, const int& year);
        void setTime(const int& hours, const int& mins);
        void incrementDay();
        void incrementMonth();
        void incrementYear();
        int getDaysInMonth();
        int getDay();
        int getMonth();
        int getYear();
        bool getLeapYear();
        Time* getTime();
        string dateToString();
        //string timeToString();
        void incrementHour();
        void incrementMin();
        void incrementSec();
        virtual ~Date();

};

#endif //DATE_
