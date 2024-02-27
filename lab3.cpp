//preprocessor directives
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//main function
int main(){

    //var declaration
    float principal,
        interestRate,
        timesCompounded,
        finalBalance;
    
    //input
    cout << "What is your principal?" << endl;
    cin >> principal;
    cout << "what is your interest rate?" << endl;
    cin >> interestRate;
    cout << "How many times is your interest compounded per year?" << endl;
    cin >> timesCompounded;


    cout << "Interest Rate:    " << right << setw(10) << interestRate << "%" << endl;
    
    //divide interestRate by 100 to convert to a decimal
    interestRate /= 100;
    
    //calculate final balance
    finalBalance = principal * pow((1 + (interestRate / timesCompounded)), timesCompounded);

    //output
    cout <<  "Times Compounded: " << setw(10) <<  timesCompounded << endl;
    cout <<  "Principal:       $" << setw(10) << fixed << setprecision(2) << principal << endl;
    cout <<  "Interest:        $" << setw(10) << fixed << setprecision(2) << finalBalance - principal << endl;
    cout <<  "Final Balance:   $" << setw(10) << fixed << setprecision(2) << finalBalance << endl;

    return 0;
}