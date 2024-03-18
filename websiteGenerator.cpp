#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    string name,
        job;
    int age;
    float experience;

    ofstream outputFile("html.txt");

    if(outputFile){
        
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your age: ";
        cin >> age;

        // Ignore the newline left in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter your job title:";
        getline(cin, job);

        cout << "How many years of experience do you have? ";
        cin >> experience;

        while(experience <= 0){
            cout << "Experience must be a positive value.  Please enter how many years of experience you have: ";
            cin >> experience;
        }

        outputFile << "<div>\n\t<h1>" << name << "</h1>\n";
        outputFile << "\t<div>I am " << age << " years old.</div>\n";
        outputFile << "\t<div>I am a " << job << " with " << experience << " year(s) of experience.</div>\n</div>";

        return 0;
    }
}