#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float OCEAN_LEVEL_RISE = 3.1;
    int years = 25;
    int startYear = 2024;
    float oceanLevel = 0;

    cout << "Year" << setw(20) << "Ocean Level" << endl;
    cout << "-----------------------------" << endl;
    for(int i = 1; i <= years; i++){
        oceanLevel += OCEAN_LEVEL_RISE;
        cout << startYear + i << setw(20) << oceanLevel << endl;
    }

    return 0;
}