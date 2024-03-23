#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

//function prototypes
void getInput(int &spoolsOrdered, int &spoolsInStock, float &specialShippingCharge);
void displayOrderInfo(int spoolsOrdered, int spoolsInStock, float specialShippingCharge);
bool isValidOrder(int input);
bool isInStock(int spoolsOrdered, int spoolsInStock);

//constant definitions
const int SHIPPING_CHARGE = 10;
const int SPOOL_COST = 100;

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
    
    cout << "How many spools are being ordered?" << endl;
    cin >> spoolsOrdered;

    while(!isValidOrder(spoolsOrdered)){
        cout << "Please enter a number greater than zero." << endl;
        cin >> spoolsOrdered;
    }

    cout << "How many spools are in stock?" << endl;
    cin >> spoolsInStock;

    while(spoolsInStock < 0){
        cout << "Please enter a number greater than or equal to zero." << endl;
        cin >> spoolsInStock;
    }

    cout << "Are there any special shipping charges? (Enter 0 if there are none):" << endl;
    cin >> specialShippingCharge;

    while(specialShippingCharge < 0){
        cout << "Please enter a number greater than or equal to zero." << endl;
        cin >> specialShippingCharge;
    }
}

void displayOrderInfo(int spoolsOrdered,int spoolsInStock ,float specialShippingCharge){
    cout << "Spools ordered: " << spoolsOrdered << endl;
    cout << "Spools in stock: " << spoolsInStock << endl;
    
    if(!isInStock(spoolsOrdered, spoolsInStock)){
        cout << "Spools on backorder: " << spoolsOrdered - spoolsInStock << endl;
    } else {
        cout << "Spools on backorder: 0" << endl;
    }

    if(isInStock(spoolsOrdered, spoolsInStock)){
        cout << "Subtotal: $" << spoolsOrdered * SPOOL_COST << endl;
    } else {
        cout << "Subtotal: $" << spoolsInStock * SPOOL_COST << endl;
    }
    
    if(specialShippingCharge > 0){
        if(isInStock(spoolsOrdered, spoolsInStock)){
            cout << "Shipping: $" << (SHIPPING_CHARGE * spoolsOrdered) + specialShippingCharge << endl;
            } else {
            cout << "Shipping: $" << (SHIPPING_CHARGE * spoolsInStock) + specialShippingCharge << endl;
            }
    } else {
        if(isInStock(spoolsOrdered, spoolsInStock)){
            cout << "Shipping: $" << (SHIPPING_CHARGE * spoolsOrdered) << endl;
        } else {
            cout << "Shipping: $" << (SHIPPING_CHARGE * spoolsInStock) << endl;
        }
    }

    if(isInStock(spoolsOrdered, spoolsInStock)){
        cout << "Total: $" << (spoolsOrdered * SPOOL_COST) + (SHIPPING_CHARGE * spoolsOrdered) + specialShippingCharge << endl;
    } else {
        cout << "Total: $" << (spoolsInStock * SPOOL_COST) + (SHIPPING_CHARGE * spoolsInStock) + specialShippingCharge << endl;
    }
}

bool isValidOrder(int input){
    return input > 0;
}

bool isInStock(int spoolsOrdered, int spoolsInStock){
    return spoolsOrdered <= spoolsInStock;
}