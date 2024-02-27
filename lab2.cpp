/* This is a code that stores the integers 62 and 99,
displays the sum of the two on the screen, and displays my name along with a beep.
I opted to use short integers to be as efficient as possible with memory */

#include<iostream>
using namespace std;

int main() {
    //var declaration
    short num1 = 62,
          num2 = 99;

    //add of the two numbers
    short total = num1 + num2;

    //output
    cout << "The sum of " << num1 << " and " << num2 << " is " << total << endl;
    cout << "My name is Brandon Lowe\a" << endl;
}