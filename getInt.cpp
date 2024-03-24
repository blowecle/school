#include <iostream>
#include <limits>
using namespace std;

int main() {
    int userInput;
    while (true) {
        cout << "Please enter an integer: ";
        if (cin >> userInput) {
            // Input is successfully read and is an integer.
            break;
        } else {
            // Input failed, clear the error flag.
            cin.clear();
            // Ignore the rest of the input line to avoid infinite loops.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        }
    }

    cout << "You entered: " << userInput << endl;
    return 0;
}