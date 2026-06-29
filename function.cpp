#include "function.h"

// For addition
double Addition(double x, double y){                 
    return x+y;
}

// For Subtraction
double Subtraction(double x, double y){              
    return x-y;
}

// For Multiplication
double Multiplication(double x, double y){
    return x*y;
}

// For Division
double Division(double x, double y){
    if (y==0){
        return 0;
    }
    else 
        return x/y;
}

// history traker
void historyTraker(double arr[], int &historyCount, const double &result)
        {
            if (historyCount < 5)
                {
                    arr[historyCount] = result;
                    historyCount++;
                }
                else{
                    for(int z=0; z<4; z++){
                arr[z] = arr[z+1];
            }
            arr[4] = result;
            }
        }