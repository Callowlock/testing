#include "Time.h"

Time::Time(){
    _hours = 0;
    _mins = 0;
    _secs = 0;
}

Time::~Time(){}

Time::Time(const int& hours, const int& mins) {
    _hours = hours;
    _mins = mins;
    _secs = 0;
}
void Time::setHours(const int& hours){
    _hours = hours;
}
void Time::setMins(const int& mins) {
    _mins = mins;
}
void Time::setSecs(const int& secs){
    _secs = secs;
}


void Time::setTime(const int& hours, const int& mins){
    _hours = hours;
    _mins = mins;
    _secs = 0;
}
void Time::incrementMins(){
    _mins++;
    if(_mins == 60) {
        _mins = 0;
        incrementHours();
    }
}
void Time::incrementHours(){
    _hours++;
    _mins = 0;
    if(_hours == 24) {
        _hours = 0;
    }
}
void Time::incrementSecs(){
    _secs++;
    if(_secs == 60) {
        _secs = 0;
        incrementMins();    
    }
}

int Time::getMins() {
    return _mins;
}
int Time::getHours() {
    return _hours;
}
int Time::getSecs() {
    return _secs;
}

void Time::addSec() {
    _secs++;
}

void Time::addMin() {
    _mins++;
}

void Time::addHour(){
    _hours++;
}

string Time::timeToString(){
    string output = "";
    if(_hours < 10) {
        output += "0";
        output += to_string(_hours) + ":";
    } else {
        output += to_string(_hours) + ":";
    }
    if(_mins < 10) {
        output += "0";
        output += to_string(_mins) + ":";
    } else {
        output += to_string(_mins) + ":";
    }
    if(_secs < 10) {
        output += "0";
        output += to_string(_secs);
    } else {
        output += to_string(_secs);
    }

    if(_hours < 12 ) {
        return output += " AM";
    } else {
        return output += " PM";
    }

}

bool Time::timeEqual(Time* t) {
    return (_hours == t->getHours()) && (_mins == t->getMins());
}
