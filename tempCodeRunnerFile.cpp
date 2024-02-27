#include <iostream>
using namespace std;

int main() {
    cout << "What is the width?";
    
    float width;
    
    cin >> width;

    cout << "What is the length?";

    float length;

    cin >> length;

    float area = width * length;

    cout << "The area of the rectangle is " << area << endl;
}