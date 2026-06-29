#include "function.h"


int main(){
    double a, b, result = 0;
    int x = 0;
    int historyCount = 0;
    double arr[5];
    
    do {
        cout << "Select which operation do you want to perform \n"
    << "1 for Addition \n"
    << "2 for Subtraction \n"
    << "3 for Multiplication \n"
    << "4 for Division\n" 
    << "5 for Checking History\n" 
    << "0 for Exit"<< endl;

        getValidInput(x); 
        
        if (x>=1 && x<=4)
        {
            cout << "Enter two numbers: ";
            getValidInput(a);
            getValidInput(b);
            
        }
        switch(x){
            case OP_ADD:    // Addition
            result = Addition(a,b);
            cout << "Addition is " << result << endl;
            break;

            case OP_SUB:       // Subtraction
            result = Subtraction(a,b);
            cout << "Subtraction is " << result << endl;
            break;

            case OP_MUL:    // Multiplication
            result = Multiplication(a,b);
            cout << "Multiplication is " << result << endl;
            break;

            case OP_DIV:        // Division
            result = Division(a,b);
            if (b==0){
                cout << "[Warning] Division by 0 is undefined!" << endl;
            }
            cout << "Division is " << result << endl;
            break;

            case OP_HIS:        // History
            cout << "History upto 5 operatins" << endl;
            if (historyCount == 0){
                cout << "No history recorded yet" << endl;
            }
                for (int j = historyCount-1; j >= 0; j--){
                    cout << arr[j] << endl;
                }
            break;

            default:        // invalid input entered
            if (x!=0)
            {cout << "Invalid input! " << endl;}
            break;
        }
        
        if (x >= 1 && x <= 4)
        {
            historyTraker(arr, historyCount, result);
        }
        
        
       
    }
    while (x!=0);
    
    return 0;
}

