#include <string>
#include <chrono>
#include <iostream>
#include <cctype>
#include "TimeUnivChronoSimple.h"
using namespace std;


 void UnivTime::fromSec(unsigned long long int timeSec){
    
        if(timeSec < 60) {
            secs = (unsigned long long int) timeSec;
        }
        else {
            secs = timeSec % 60;
            mins = (unsigned long long int) timeSec / 60;
            if(mins >= 60){
                hours = (unsigned long long int) mins /60;
                mins = mins %60;
                if(hours >= 24){
                    days = (unsigned long long int) hours / 24;
                    hours = hours % 24;
                    if(days >= 365){
                        years = (unsigned long long int) days / 365;
                        days = days % 365;
                        if(years >= 100){
                            centuries = (unsigned long long int) years / 100;
                            years = years % 100;
                        }
                    }
                }
            }
        }
        
    }
    
   void UnivTime::fromMilliSec(unsigned long long int timeMilliSec)
    {
        if (timeMilliSec < 1000)
        {
            milliseconds = timeMilliSec;
        }
        else
        {
            secs = (unsigned long long int) (timeMilliSec / 1000);
            milliseconds = timeMilliSec % 1000;
            if (secs >= 60)
            {
                secs = secs % 60;
                mins = (unsigned long long int)secs / 60;
                if (mins >= 60)
                {
                    hours = (unsigned long long int)mins / 60;
                    mins = mins % 60;
                    if (hours >= 24)
                    {
                        days = (unsigned long long int)hours / 24;
                        hours = hours % 24;
                        if (days >= 365)
                        {
                            years = (unsigned long long int)days / 365;
                            days = days % 365;
                            if (years >= 100)
                            {
                                centuries = (unsigned long long int)years / 100;
                                years = (unsigned long long int)years % 100;
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    void UnivTime::fromNanoSec(unsigned long long int timeNanoSec)
    {   
        if (timeNanoSec <  (unsigned long long int) 1000000000)
        {
            nanosecs = (unsigned long long int) timeNanoSec;
        }
        else
        {
            secs = (unsigned long long int) (timeNanoSec / (unsigned long long int) 1000000000);
            nanosecs = timeNanoSec %  (unsigned long long int) 1000000000;
            if (secs >= 60)
            {   
                mins = (unsigned long long int) (secs / (unsigned long long int) 60);
                secs = secs % 60;
                if (mins >= 60)
                {
                    hours = (unsigned long long int) (mins /  (unsigned long long int) 60);
                    mins = mins % 60;
                    if (hours >= 24)
                    {
                        days = (unsigned long long int) (hours /  (unsigned long long int) 24);
                        hours = hours % 24;
                        if (days >= 365)
                        {
                            years = (unsigned long long int) (days /  (unsigned long long int) 365);
                            days = days % 365;
                            if (years >= 100)
                            {
                                centuries = (unsigned long long int) (years /  (unsigned long long int) 100);
                                years = (unsigned long long int) (years %  (unsigned long long int) 100);
                            }
                        }
                    }
                }
            }
        }
    }
    
    
   UnivTime::UnivTime(unsigned long long int time, char timeUnit){
         this->chronoType = toupper(timeUnit);

        //this init is important
         this->nanosecs = 0; 
         this->milliseconds = 0;
         this->secs = 0;
         this->mins = 0;
         this->hours = 0;
         this->days = 0;
         this->years = 0;
         this->centuries = 0;
        
        if(timeUnit == 'N'|| timeUnit == 'n'){
            UnivTime::fromNanoSec(time);// because here we actualise only the values that need to and not all.
        }
        else if(timeUnit == 'M'|| timeUnit == 'm'){
            UnivTime::fromMilliSec(time); 
        }
        else if(timeUnit == 'S' ||timeUnit == 's'){
            UnivTime::fromSec(time);
        }
        
         
    }
    
    string UnivTime::getString(){

        string nanosec;
        if(nanosecs == 1)	{nanosec = "nanosec";} 	else{nanosec = "nanosecs";}
        
        string millisecond;
        if(milliseconds == 1)	{millisecond = "millisecond";} 	else{millisecond = "milliseconds";}

        string sec;
        if(secs == 1)	{sec = "sec";} 	else{sec = "secs";}

        string min;
        if(mins == 1)	{min = "min";	} 	else{min = "mins";}
    
        string hour;
        if(hours == 1)	{hour = "hour";}	else{hour = "hours";}
    
        string day;
        if(days == 1)	{day = "day";}	else{day = "days";}
    
        string year;
        if(years == 1)	{year = "year";}	else{year = "years";}
    
        string century;
        if(centuries == 1)	{century = "century";}	else{century = "centuries";}

        string separator = ":";
        separator = " " + separator + " ";
        string centuryStr = ((centuries != 0))? to_string(centuries) + " " + century + separator  : "";
        string yearStr = ((centuries != 0 || years != 0))? to_string(years) + " " + year + separator : "";
        string dayStr = (centuries != 0 || years != 0 || days != 0 )? to_string(days) + " " + day + separator : "";
        string hourStr = ((centuries != 0 || years != 0 || days != 0 || hours != 0 ))? to_string(hours) + " " + hour + separator : "";
        string minStr = ((centuries != 0 || years != 0 || days != 0 || hours != 0 || mins != 0 ))? to_string(mins) + " " + min + separator : "";
        string secStr = ((centuries != 0 || years != 0 || days != 0 || hours != 0 || mins != 0 || secs != 0))? to_string(secs) +" "+ sec + ((chronoType != 'S')? separator : "") : "";
        string millisecStr = (chronoType == 'M' && ( milliseconds != 0))? to_string(milliseconds) +" "+ millisecond : "";
        string nanoSecStr = (chronoType == 'N' && ( nanosecs != 0))? to_string(nanosecs) +" "+ nanosec : "";
         
        return  centuryStr + yearStr + dayStr + hourStr + minStr + secStr + millisecStr + nanoSecStr;
    }
    
    void UnivTime::print(){
    cout << UnivTime::getString();
    }
    
   void UnivTime::printCompleteMessageExecTime(){
        cout << "Execution time : "<<endl;
        cout << UnivTime::getString()<<endl;
    }
    
    
    
     void ChronoSimple::start(){
        _start = std::chrono::high_resolution_clock::now();
    }
    
    unsigned long long int ChronoSimple::stopNanoSec(){
        _stop = std::chrono::high_resolution_clock::now();
        return (unsigned long long int) std::chrono::duration_cast<std::chrono::nanoseconds>(_stop-_start).count();
    }
    
    unsigned long long int ChronoSimple::stopMilliSec(){
        _stop = std::chrono::high_resolution_clock::now();
        return  (unsigned long long int) std::chrono::duration_cast<std::chrono::milliseconds>(_stop-_start).count();
    }
    
    
  unsigned long long int ChronoSimple::stopSec(){
        _stop = std::chrono::high_resolution_clock::now();
        return (unsigned long long int) std::chrono::duration_cast<std::chrono::seconds>(_stop-_start).count();
    }
