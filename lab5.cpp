#include<iostream>
#include<string>
#include<fstream>
using namespace std;

float calculateAverageRainfall(float rainfall, int months);

int main(){
    
    //var declaration
    float rainfall, 
    totalRainfall = 0;

    int months = 0;

    string startMonth, endMonth, month;

    //open file
    ifstream inputFile("rainfall.txt");

    //verify file exists and read from file
    if(inputFile){
        
        //read in the start and ending months from the inputFile
        inputFile >> month;
        startMonth = month;

        inputFile >> month;
        endMonth = month;

        //while there is still rainfall data to read, add the rainfall to totalRainfall and increment months
        while(inputFile >> rainfall){
            
            //if it fainfall value is greater than zero, add it to the total
            if(rainfall >= 0){

            totalRainfall += rainfall;
            months++;
            
            } else {
                //if a rainfall value is negative, the data is invalid.  Display error and close the file
                cout << "Error: Negative rainfall value: , " << rainfall << " encountered in file.";
                inputFile.close();
            }
        }
    } else {

        //if file does not exist display error
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

        //output
        cout << "The total rainfall for " << startMonth << " - " << endMonth << " is " << totalRainfall << " inches." << endl;
        cout << "And the average monthly rainfall is " << calculateAverageRainfall(totalRainfall, months) << " inches." << endl;

        return 0;
    }
}

//calculateAverageRainfall takes in the total rainfall as a float and the number of months as an int
//it will return a float for the value of the average rainfall per month
float calculateAverageRainfall(float rainfall, int months){
    
    float averageRainfall = rainfall / months;
    return averageRainfall;
}