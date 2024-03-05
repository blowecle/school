#include <iostream>
#include<fstream>
using namespace std;

int main() {

    float width;
    float length;

    ofstream debugFile("debug.txt");

    cout << "What is the width?" << endl;
    
    cin >> width;

    while(width <= 0){
        cout << "Please enter a number greater than zero: ";
        cin >> width;
    }

    cout << "What is the length?" << endl;

    cin >> length;

    while(length <= 0){
        cout << "Please enter a number greater than zero: ";
        cin >> length;
    }

    float area = width * length;

    if(debugFile){
        debugFile << "The length is: " << length << ", the width is: " << width << " and the area is " << length << " * " << width << " = " << area;
    }

    cout << "The area of the rectangle is " << area << endl;

    debugFile.close();

    return 0;
}