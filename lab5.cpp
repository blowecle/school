#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    
    //var declaration
    float rainfall, 
        totalRainfall = 0, 
        averageRainfall;

    int months = 0;

    string startMonth, endMonth, month;

    //open file
    ifstream inputFile("rainfall.txt");

    //verify file exists and read from file
    if(inputFile){
        //reading start month
        inputFile >> month;
        startMonth = month;

        //reading end month
        inputFile >> month;
        endMonth = month;

        //while there is still rainfall data to read, add the rainfall to totalRainfall and increment months
        while(inputFile >> rainfall){
            totalRainfall += rainfall;
            months++;
        }
    }

    //close file
    inputFile.close();

    averageRainfall = totalRainfall / months;

    //output
    cout << "The total rainfall for " << startMonth << " - " << endMonth << " is " << totalRainfall << " inches." << endl;
    cout << "And the average monthly rainfall is " << averageRainfall << " inches." << endl;

    return 0;
}