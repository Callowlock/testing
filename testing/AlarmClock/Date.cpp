#include "Date.h"


Date::Date(const int& month, const int& day, const int& year) {
    _year = year;
    _day = day;
    _month = month;
    _time = new Time();
    _leapYear = (_year % 4 == 0) && (_year % 100 != 0);
}

Date::~Date() {
    delete _time;
}

bool Date::getLeapYear() {
    return _leapYear;
}

void Date::setDate(const int& month, const int& day, const int& year) {
    _year = year;
    _day = day;
    _month = month;
}

void Date::setTime(const int& hours, const int& mins) {
    _time->setHours(hours);
    _time->setMins(mins);
    _time->setSecs(0); 
}

void Date::incrementSec() {
    _time->addSec();
    if(_time->getSecs() == 60) {
        _time->setSecs(0);
        incrementMin();
    }
}


void Date::incrementMin() {
    _time->addMin();
    if(_time->getMins() == 60) {
        _time->setMins(0);
        incrementHour();
    }
    

}
void Date::incrementHour() {
    _time->addHour();
    if(_time->getHours() == 24) {
        _time->setHours(0);
        incrementDay();
    }
}

void Date::incrementDay(){
    _day++;
    if(_day > getDaysInMonth()) {
        incrementMonth();
        _day = 1;
    }
}

void Date::incrementMonth(){
    _month++;
    if(_month > 12) {
        _month = 1;
        incrementYear();
    }
}

void Date::incrementYear(){
    _year++;
    _leapYear = (_year % 4 == 0) && (_year % 100 != 0);

}

int Date::getDaysInMonth(){
    if (_month == 2) {
        if(_leapYear) {
            return 29;
        } else {
            return 28;
        }
    } else if(_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
        return 31;
    } else {
        return 30;
    }

}

Time* Date::getTime() {
    return _time;
}
int Date::getDay(){
    return _day;
}

int Date::getMonth(){
    return _month;
}

int Date::getYear(){
    return _year;
}
/*string Date::timeToString(){
    string output = "";
    if(_time.getHours() < 10) {
        output += "0";
        output += to_string(_time.getHours()) + ":";
    } else {
        output += to_string(_time.getHours()) + ":";
    }
    if(_time.getMins() < 10) {
        output += "0";
        output += to_string(_time.getMins()) + ":";
    } else {
        output += to_string(_time.getMins()) + ":";
    }
    if(_time.getSecs() < 10) {
        output += "0";
        output += to_string(_time.getSecs());
    } else {
        output += to_string(_time.getSecs());
    }

    if(_time.getHours() < 12 ) {
        return output += " AM";
    } else {
        return output += " PM";
    }

}*/

char* Date::dateToString() {
    char* c = new char[16];
    
    for(int i = 0; i < 16; i++) {
        c[i] = ' ';
    }
    c[4] = char(_month/10);
    c[5] = char(_month%10);
    c[6] = '/';
    c[7] =  char(_day/10);
    c[8] = char(_day%10);
    c[9] = '/';
    c[10] = char(_year/10);
    c[11] = char(_year%10);
    return c;
}
