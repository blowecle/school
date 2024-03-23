#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<sstream>
using namespace std;

//function prototypes
void getInput(int &spoolsOrdered, int &spoolsInStock, float &specialShippingCharge);
void displayOrderInfo(int spoolsOrdered, int spoolsInStock, float specialShippingCharge);
bool isInStock(int spoolsOrdered, int spoolsInStock);
float roundToNearestCent(float value);
int getInt(int min, string prompt);

//constant definitions
const int SHIPPING_CHARGE = 10;
const int SPOOL_COST = 100;
const int LEFT_WIDTH = 20;
const int RIGHT_WIDTH = 10;

int main(){
    //clear previous output
    system("clear");

    //var declaration
    int spoolsOrdered,
        spoolsInStock;
    float specialShippingCharge;

    //function calls
    getInput(spoolsOrdered, spoolsInStock, specialShippingCharge);
    displayOrderInfo(spoolsOrdered, spoolsInStock, specialShippingCharge);

    return 0;
}

//function definitions
void getInput(int &spoolsOrdered, int &spoolsInStock, float &specialShippingCharge){
    
    cout << "Welcome to the Spool Order Calculator.\n\n";
    cout << "Please enter the following information:";

    spoolsOrdered = getInt(1, "\nHow many spools are being ordered?\n");
    spoolsInStock = getInt(0, "\nHow many spools are in stock?\n");

    cout << "\nAre there any special shipping charges? (Enter 0 if there are none):\n";
    cin >> specialShippingCharge;

    while(specialShippingCharge < 0){
        cout << "\nPlease enter a positive number:\n";
        cin >> specialShippingCharge;
    }
}

void displayOrderInfo(int spoolsOrdered,int spoolsInStock ,float specialShippingCharge){

    cout << "\n\n*******************************\n\n";
    cout << left << setw(LEFT_WIDTH) << "Spools ordered:" << right << setw(RIGHT_WIDTH) << spoolsOrdered << endl;
    cout << left << setw(LEFT_WIDTH) << "Spools in stock:" << right << setw(RIGHT_WIDTH) << spoolsInStock << endl;

    int backOrder = isInStock(spoolsOrdered, spoolsInStock) ? 0 : spoolsOrdered - spoolsInStock;
    cout << left << setw(LEFT_WIDTH) << "Spools on backorder:" << right << setw(RIGHT_WIDTH) << backOrder << endl;

    float subtotal = isInStock(spoolsOrdered, spoolsInStock) ? spoolsOrdered * SPOOL_COST : spoolsInStock * SPOOL_COST;
    cout << left << setw(LEFT_WIDTH) << "Subtotal:" << "$" << right << setw(RIGHT_WIDTH - 1) << fixed << setprecision(2) << subtotal << endl;

    float shippingCost = (isInStock(spoolsOrdered, spoolsInStock) ? SHIPPING_CHARGE * spoolsOrdered : SHIPPING_CHARGE * spoolsInStock) + specialShippingCharge;
    cout << left << setw(LEFT_WIDTH) << "Shipping:" << "$" << right << setw(RIGHT_WIDTH - 1) << fixed << setprecision(2) << shippingCost << endl;

    float total = subtotal + shippingCost;
    cout << left << setw(LEFT_WIDTH) << "Total:" << "$" << right << setw(RIGHT_WIDTH - 1) << fixed << setprecision(2) << total << "\n\n";
}

bool isInStock(int spoolsOrdered, int spoolsInStock){
    return spoolsOrdered <= spoolsInStock;
}

float roundToNearestCent(float value) {
    return round(value * 100) / 100;
}

int getInt(int min, string prompt){
    
    int returnVal;
    string stringNum;
    bool inputNotValidated = true;

    while(inputNotValidated){
        
        cout << prompt;
        getline(cin, stringNum);
        stringstream convert(stringNum);

        if(convert >> returnVal && !(convert >> stringNum) && returnVal >= min){
            inputNotValidated = false;
        }

        if(inputNotValidated){
        
            cin.clear();
            cerr << "Invalid input. Please enter an integer greater than or equal to " << min << ".\n";
        
        }

    }

    return returnVal;
}