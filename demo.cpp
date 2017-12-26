#include<chrono>
#include<thread>
#include<string>
#include<iostream>
using namespace std;
#include "TimeUnivChronoSimple.h"

typedef unsigned long long ULL;


int main(int argc,char **argv){
    ChronoSimple chrono; // we create our chrono object
    chrono.start(); // we start the chrono

    char exit = 'n';
    while(exit != 'y'){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "enter 'y' to stop, or 'n' to not do that" << endl;
        cin >> exit;   
    }
    //we stop the chrono using the correct unit 
    ULL elapsedTimeNano = chrono.stopNanoSec();
    ULL elapsedTimeMS = chrono.stopMilliSec();
    ULL elapsedTimeSec = chrono.stopSec();
    cout << "elapsedTimeNano = " << elapsedTimeNano << endl;
    cout << "elapsedTimeMS = " << elapsedTimeMS << endl;
    cout << "elapsedTimeSec = " << elapsedTimeSec << endl;
    cout << "------------------------------------------------" << endl;
    cout << "------------------------------------------------" << endl;
    // we create construct UnivTime object with the specific unit type 
    UnivTime univTimeNano = UnivTime(elapsedTimeNano,'n');
    UnivTime univTimeMS = UnivTime(elapsedTimeMS,'m');
    UnivTime univTimeSec = UnivTime(elapsedTimeSec,'s');
    
    // we get the formated string if we want 
    string elapsedTimeNanoStr = univTimeNano.getString();
    string elapsedTimeMSStr = univTimeMS.getString();
    string elapsedTimeSecStr = univTimeSec.getString();
    cout << "--------- getString() ------------" << endl;    
    cout << "elapsed time from nano string => "<< endl << elapsedTimeNanoStr << endl;
    cout << "elapsed time from milisec string => "<< endl << elapsedTimeMSStr << endl;
    cout << "elapsed time from Sec string => "<< endl << elapsedTimeSecStr << endl;

    // or directly print the result
    cout << "----------------"<<endl;
    cout << "----------------"<<endl;
    cout << "--------- printCompleteMessageExecTime() ------------" << endl; 
    cout << "univTimeNano.printCompleteMessageExecTime(); ===> "<<endl;
    univTimeNano.printCompleteMessageExecTime();
    cout << "univTimeMS.printCompleteMessageExecTime(); ===> "<<endl;
    univTimeMS.printCompleteMessageExecTime();
    cout << "univTimeSec.printCompleteMessageExecTime(); ===> "<<endl;
    univTimeSec.printCompleteMessageExecTime();

    cout << "----------------"<<endl;
    cout << "----------------"<<endl;
    cout << "--------- print() ------------" << endl; 
    cout << "univTimeNano.print(); ===> "<<endl;
    univTimeNano.print();
    cout << endl;
    cout << "univTimeMS.print(); ===> "<<endl;
    univTimeMS.print(); 
    cout << endl;
    cout << "univTimeSec.print(); ===> "<<endl;
    univTimeSec.print();
    cout << endl;

    cin.get();
    return 0;
}
