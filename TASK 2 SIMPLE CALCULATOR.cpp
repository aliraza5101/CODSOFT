#include <iostream>
using namespace std;

int main()
{
    char operation; 
    int firstNumber, secondNumber; 
 
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    switch (operation)
    {
        case '+':
            cout<<"The result of "<<firstNumber<<" + "<<secondNumber<<" is "<<(firstNumber + secondNumber)<<endl;
            break;

        case '-':
            cout<<"The result of "<<firstNumber<<" - "<<secondNumber<<" is "<<(firstNumber - secondNumber)<<endl;
            break;

        case '*':
            cout<<"The result of "<<firstNumber<<" * "<<secondNumber<<" is "<<(firstNumber * secondNumber)<<endl;
            break;

        case '/':
            if (secondNumber != 0)
                cout<<"The result of "<<firstNumber<<" + "<<secondNumber<<" is "<<(firstNumber + secondNumber)<<endl;
            else
                cout <<"Error: Division by zero is not allowed."<<endl;
            break;

        default:
            cout<<"Error: Invalid operator entered."<<endl;
            break;
    }
	    return 0;
}
