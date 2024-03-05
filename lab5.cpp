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
        
        inputFile >> month;
        startMonth = month;

        inputFile >> month;
        endMonth = month;

        //while there is still rainfall data to read, add the rainfall to totalRainfall and increment months
        while(inputFile >> rainfall){
            totalRainfall += rainfall;
            months++;
        }
    } else {
        cout << "File not found." << endl;
        return 1;
    }

    //close file
    inputFile.close();

    //verify months is not 0
    if(months == 0){
        cout << "No data was read from the file." << endl;
        return 1;

        //if months is not 0 (data was read), calculate averageRainfall
    } else {

        averageRainfall = totalRainfall / months;

        //output
        cout << "The total rainfall for " << startMonth << " - " << endMonth << " is " << totalRainfall << " inches." << endl;
        cout << "And the average monthly rainfall is " << averageRainfall << " inches." << endl;

        return 0;
    }
}