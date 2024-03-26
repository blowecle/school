#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//function prototypes
void displayMenu();
void getChoice(int &choice);
void calcAverage();
int calcMinimum();
void calcMaximum();
void writeFile(string fileName);
void readFile();

//main function
int main(){
    int choice;

    //display menu
    displayMenu();
    while(choice != 6){

        //get the user choice and run the switch statement.
        //input validation is handled within getChoice
        getChoice(choice);
        
        //once validated, run the switch statement depending on the user's choice
        switch(choice){
            case 1:{
                calcAverage();
                break;
            }
            case 2:{
                int min = calcMinimum();
                cout << "The minimum was " << min << ".\n\n";
                break;
            }
            case 3:{
                calcMaximum();
                break;
            }
            case 4:{
                string fileName;
                cout << "Enter the name of the file you would like to write to: ";
                cin >> fileName;
                writeFile(fileName);
                break;
            }
            case 5:{
                readFile();
                break;
            }
            case 6:{
                cout << "\n\nGoodbye.\n\n";
                return 0;
                //if the user selects 6, the program will exit
            }
        }

        //display the menu again
        displayMenu();
    }

    return 0;
};

//function definitions
void displayMenu(){
    cout << "Please select an option from the menu below: \n\n";
    cout << "1. Calculate Average\n";
    cout << "2. Calculate Minimum\n";
    cout << "3. Calculate Maximum\n";
    cout << "4. Write Data to a File\n";
    cout << "5. Read Data from a File\n";
    cout << "6. Exit\n\n";
};

//function to get the user's choice and assign
//the value to the reference variable choice
void getChoice(int &choice){

    cin >> choice;

    //input validation
    while(choice < 1 || choice > 6){
        cout << "Invalid choice. Please enter an integer between 1 and 6:\n";
        cin >> choice;
    }
};

//function to calculate the average of a set of integers
//the number of which is specified by the user
void calcAverage(){
    int count;
    int sum = 0;
    int number;

    cout << "How many integers would we like to average?\n";
    cin >> count;

    //input validation
    while(count <= 0){
        cout << "Please enter an integer greater than zero:\n";
        cin >> count;
    }

    //loop count times, adding each number to the sum
    for(int i = 0; i < count; i++){
        cout << "Enter an integer:\n";
        cin >> number;
        
        sum += number;
    }

    //output the average
    cout << "The average of the numbers entered is " << static_cast<double>(sum) / count << ".\n\n";
};

//accepts at least 1 number as user input and returns the minimum
int calcMinimum(){
    int min;
    int number;
    int sentinel = -99;

    cout << "Enter an integer:\n";
    cin >> number;

    //validate that at least 1 number is inputted
    while(number == sentinel){
        cout << "You must enter at least one number before quitting.\n";
        cin >> number;
    }

    min = number;

    //loop until the sentinel value is entered
    while(number != sentinel){
        cout << "Enter an integer (-99 to quit):\n";
        cin >> number;

        if(number < min && number != sentinel){
            min = number;
        }
    }

    //return the minimum value
    return min;
};

//accepts user input and returns the maximum value
void calcMaximum(){
    int number;
    int sentinel = 99;
    int max;

    do{
        cout << "Enter an integer (99 to quit):\n";
        cin >> number;

        if(number > max && number != sentinel){
            max = number;
        }

    }while(number != sentinel);

    cout << "The maximum number entered was " << max << ".\n\n";
};

//opens a file with a name specified by the user,
//writes user input to the file, and closes the file
void writeFile(string fileName){

    string inputLine;

    ofstream outputFile(fileName);

    while(!outputFile){
        cout << "Error opening file.  Please enter a valid file name:\n";
        cin >> fileName;
        outputFile.open(fileName);
    }

    cout << "Enter strings to write to a file.  Type 'exit' to quit:\n";
    getline(cin, inputLine);

    while(inputLine != "exit"){
        outputFile << inputLine << endl;
        getline(cin, inputLine);
    }

    outputFile.close();
};

//opens a file with a name specified by the user,
//reads the contents, and closes the file
void readFile(){
    string fileName;
    string line;

    cout << "Enter the name of the file you would like to read from:\n";
    cin >> fileName;

    ifstream inputFile(fileName);

    while(!inputFile){
        cout << "Error opening file.  Please enter a valid file name:\n";
        cin >> fileName;
        inputFile.open(fileName);
    }

    cout << "File opened successfully.\n\n" << "Contents of file:\n";

    while(getline(inputFile, line)){
        cout << line << endl;
    }

    cout << endl;

    inputFile.close();
};