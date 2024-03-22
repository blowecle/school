#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//function prototypes
void getInput(int &spoolsOrdered, int &spoolsInStock, float &specialShippingCharge);
void displayOrderInfo(int spoolsOrdered, int spoolsInStock, float specialShippingCharge);

//constant definitions
const int SHIPPING_CHARGE = 10;
const int SPOOL_COST = 100;

int main(){
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
    
    cout << "How many spools are being ordered?" << endl;
    cin >> spoolsOrdered;

    while(spoolsOrdered < 1){
        cout << "Please enter a number greater than zero." << endl;
        cin >> spoolsOrdered;
    }

    cout << "How many spools are in stock?" << endl;
    cin >> spoolsInStock;

    while(spoolsInStock < 0){
        cout << "Please enter a number greater than or equal to zero." << endl;
        cin >> spoolsInStock;
    }

    cout << "Are there any special shipping charges? (Enter 0 if there are none)" << endl;
    cin >> specialShippingCharge;

    while(specialShippingCharge < 0){
        cout << "Please enter a number greater than or equal to zero." << endl;
        cin >> specialShippingCharge;
    }
}

void displayOrderInfo(int spoolsOrdered,int spoolsInStock ,float specialShippingCharge){
    cout << "Spools ready to ship: " << spoolsOrdered << endl;
    cout << "Spools in stock: " << spoolsInStock << endl;
    
    if(spoolsOrdered > spoolsInStock){
        cout << "Spools on backorder: " << spoolsOrdered - spoolsInStock << endl;
    } else {
        cout << "Spools on backorder: 0" << endl;
    }

    if(spoolsInStock > spoolsOrdered){
        cout << "Subtotal: $" << spoolsOrdered * SPOOL_COST << endl;
    } else {
        cout << "Subtotal: $" << spoolsInStock * SPOOL_COST << endl;
    }
    
    if(specialShippingCharge > 0){
        cout << "Shipping: $" << (SHIPPING_CHARGE * spoolsOrdered) + specialShippingCharge << endl;
    } else {
        cout << "Shipping: $" << (SHIPPING_CHARGE * spoolsOrdered) << endl;
    }

    cout << "Total: $" << (spoolsOrdered * SPOOL_COST) + (SHIPPING_CHARGE * spoolsOrdered) + specialShippingCharge << endl;
}