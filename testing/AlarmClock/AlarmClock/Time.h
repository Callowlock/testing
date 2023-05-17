#ifndef TIME_
#define TIME_
#include <string.h>
using namespace std;

class Time {

    private:
        int _hours;
        int _mins;
        int _secs;
    public:

        Time();
        Time(const int& hours, const int& mins);
        void setTime(const int& hours, const int& mins);
        void setHours(const int& hours);
        void setMins(const int& mins);
        void setSecs(const int& secs);
        int getMins();
        int getHours();
        int getSecs();
        void incrementMins();
        void incrementHours();
        void incrementSecs();
        void addSec();
        void addMin();
        void addHour();
        string timeToString();
        bool timeEqual(Time* t);
        virtual ~Time();


};


#endif // TIME_
