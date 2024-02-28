/*
Just for fun I tackled this problem from the textbook.  
It works on numbers <= 4000 due to us not having the 
proper ASCII characters to go any higher.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    const int TENS = 10, HUNDREDS = 100, THOUSANDS = 1000;
    
    int number;
    string romanNumeral;

    cout << "Enter a number between 1 and 3999: ";
    cin >> number;

    if (number <= 0 || number >= 4000) {
        cout << "Number out of range." << endl;
        return 0;
    }

    while(number > 0){
        if(number >= THOUSANDS){
            romanNumeral += "M";
            number -= THOUSANDS;
        } else if(number >= 900){
            romanNumeral += "CM";
            number -= 900;
        } else if(number >= 500){
            romanNumeral += "D";
            number -= 500;
        } else if(number >= 400){
            romanNumeral += "CD";
            number -= 400;
        } else if(number >= HUNDREDS){
            romanNumeral += "C";
            number -= HUNDREDS;
        } else if(number >= 90){
            romanNumeral += "XC";
            number -= 90;
        } else if(number >= 50){
            romanNumeral += "L";
            number -= 50;
        } else if(number >= 40){
            romanNumeral += "XL";
            number -= 40;
        } else if(number >= TENS){
            romanNumeral += "X";
            number -= TENS;
        } else if(number == 9){
            romanNumeral += "IX";
            number -= 9;
        } else if(number >= 5){
            romanNumeral += "V";
            number -= 5;
        } else if(number == 4){
            romanNumeral += "IV";
            number -= 4;
        } else if(number >= 1){
            romanNumeral += "I";
            number -= 1;
        }
    }

    cout << romanNumeral << endl;

    return 0;
}