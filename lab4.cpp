/*
Description: This program takes a number of seconds as input 
and outputs the number of days if the seconds inputted >= 86400,
the number of hours if the seconds inputted >= 3600,
the number of minutes if the seconds inputted >= 60,
or the number of seconds if the seconds inputted > 0.
If the input is less than or equal to zero, the program will output an error message.
*/

//preprocessor directives
#include <iostream>
using namespace std;

int main(){
    //var declaration
    const short SECONDS_IN_MINUTE = 60;
    const short SECONDS_IN_HOUR = 3600;
    const int SECONDS_IN_DAY = 86400;

    double secondsInputted;

    //input
    cout << "Enter any number of seconds: ";
    cin >> secondsInputted;

    /*
    Compare the seconds inputted to the number of seconds in a day, hour, and minute.
    
    If the seconds inputted is greater than or equal to the number of seconds in a day,
    output the number of days.
    
    If the seconds inputted is greater than or equal to the number of seconds in an hour,
    output the number of hours.
    
    If the seconds inputted is greater than or equal to the number of seconds in a minute,
    output the number of minutes.
    
    If the seconds inputted is greater than 0, output the number of seconds.
    
    If the seconds inputted is less than or equal to 0, output an error message.

    If the seconds inputted is equal to one of the day, hour, or minute constants,
    express that the input exactly matches the number of seconds in a day, hour, or minute.
    */

    if(secondsInputted > SECONDS_IN_DAY){
        cout << "That is " << secondsInputted / SECONDS_IN_DAY << " days." << endl;
    } else if(secondsInputted == SECONDS_IN_DAY){
        cout << "That is exactly 1 day." << endl;
    } else if(secondsInputted > SECONDS_IN_HOUR){
        cout << "That is " << secondsInputted / SECONDS_IN_HOUR << " hours." << endl;
    } else if(secondsInputted == SECONDS_IN_HOUR){
        cout << "That is exactly 1 hour." << endl;
    } else if(secondsInputted > SECONDS_IN_MINUTE){
        cout << "That is " << secondsInputted / SECONDS_IN_MINUTE << " minutes." << endl;
    } else if(secondsInputted == SECONDS_IN_MINUTE){
        cout << "That is exactly 1 minute." << endl;
    } else if(secondsInputted > 0){
        cout << "That is " << secondsInputted << " seconds." << endl;
    } else {
        cout << "Invalid input.  Please rerun the program and enter a number greater than zero" << endl;
    }

    return 0;
}