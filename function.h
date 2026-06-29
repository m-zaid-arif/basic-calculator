#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;

    // Global variables for main menue
    const int OP_ADD = 1;
    const int OP_SUB = 2;
    const int OP_MUL = 3;
    const int OP_DIV = 4;
    const int OP_HIS = 5;



double Addition(double x, double y);        // For addition
double Subtraction(double x, double y);     // For Subtraction
double Multiplication(double x, double y);      // For Multiplication
double Division(double x, double y);        // For Division
void historyTraker(double arr[], int &historyCount, int result);    // function for traking history


// This is the function that takes valid inputs and prevents invalid inputs like from another data type

template <typename T>
void getValidInput(T &num){
    
    while(true){
        cin >> num;
        if (cin.fail()){
            cout << "Invalid Input! Please enter the valid input " << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        }
        else 
            return;
    }
}




#endif