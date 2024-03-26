#include<iostream>
using namespace std;

//prototypes
void getInpatientData(int &daysSpent, float &dailyRate, float &medicationCharges, float &servicesCharges);
void getOutpatientData(float &medicationCharges, float &servicesCharges);
bool isNegative(float value);
float calculateCharges(int daysSpent, float dailyRate, float medicationCharges, float servicesCharges);
float calculateCharges(float medicationCharges, float servicesCharges);
void displayCharges(float charges);

int main(){
    int daysSpent, choice;
    float dailyRate, medicationCharges, servicesCharges;

    cout << "Please enter 1 for inpatient or 2 for outpatient: \n";
    cin >> choice;

    while(choice != 1 && choice != 2){
        cout << "Please enter 1 for inpatient or 2 for outpatient: \n";
        cin >> choice;
    }

    switch(choice){
        case 1:
            getInpatientData(daysSpent, dailyRate, medicationCharges, servicesCharges);
            displayCharges(calculateCharges(daysSpent, dailyRate, medicationCharges, servicesCharges));
            break;
        case 2:
            getOutpatientData(medicationCharges, servicesCharges);
            displayCharges(calculateCharges(medicationCharges, servicesCharges));
            break;
    }

    return 0;
}

void getInpatientData(int &daysSpent, float &dailyRate, float &medicationCharges, float &servicesCharges){
    cout << "Please enter the number of days spent in the hospital: ";
    cin >> daysSpent;

    while(isNegative(daysSpent)){
        cout << "Please enter a positive number: ";
        cin >> daysSpent;
    }

    cout << "Please enter the daily rate: ";
    cin >> dailyRate;
    while(isNegative(dailyRate)){
        cout << "Please enter a positive number: ";
        cin >> dailyRate;
    }

    cout << "Please enter the medication charges: ";
    cin >> medicationCharges;
    while(isNegative(medicationCharges)){
        cout << "Please enter a positive number: ";
        cin >> medicationCharges;
    }

    cout << "Please enter the services charges: ";
    cin >> servicesCharges;
    while(isNegative(servicesCharges)){
        cout << "Please enter a positive number: ";
        cin >> servicesCharges;
    }
}

void getOutpatientData(float &medicationCharges, float &servicesCharges){
    cout << "Please enter the medication charges: ";
    cin >> medicationCharges;
    while(isNegative(medicationCharges)){
        cout << "Please enter a positive number: ";
        cin >> medicationCharges;
    }

    cout << "Please enter the services charges: ";
    cin >> servicesCharges;
    while(isNegative(servicesCharges)){
        cout << "Please enter a positive number: ";
        cin >> servicesCharges;
    }
}

bool isNegative(float value){
    return value < 0;
}

float calculateCharges(int daysSpent, float dailyRate, float medicationCharges, float servicesCharges){
    return (daysSpent * dailyRate) + medicationCharges + servicesCharges;
}

float calculateCharges(float medicationCharges, float servicesCharges){
    return medicationCharges + servicesCharges;
}

void displayCharges(float charges){
    cout << "The total charges are: $" << charges << endl;
}