#ifndef TIMEUNIVCHRONOSIMPLE_H
#define TIMEUNIVCHRONOSIMPLE_H
using namespace std;

class UnivTime{
public:
    unsigned long long int nanosecs;
    unsigned long long int milliseconds;
    unsigned long long int secs;
    unsigned long long int mins;
    unsigned long long int hours;
    unsigned long long int days;
    unsigned long long int years;
    unsigned long long int centuries;
    char chronoType; // 'N'=nanosec,'M'= milisec,'S' =sec

    void fromSec(unsigned long long int timeSec);
    void fromMilliSec(unsigned long long int timeMilliSec);
    void fromNanoSec(unsigned long long int timeNanoSec);

    UnivTime(unsigned long long int time,char timeUnit);

    string getString(); 
    void print();
    void printCompleteMessageExecTime();
};

// chrono simplifying class
typedef chrono::high_resolution_clock::time_point timePoint;

class ChronoSimple{
private:
    timePoint _start;
    timePoint _stop;
public:   
    unsigned long long int stopNanoSec(); // 'N' for nanosec 'M' for milisec and 'S' for sec 
    unsigned long long int stopMilliSec();
    unsigned long long int stopSec();
    void start();
    //ChronoSimple();
    
};

#endif