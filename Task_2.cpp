#include<iostream>
using namespace std;
int main()
{
    double num1, num2;
    char ch;
    cout<<"                     Basic Arithmetic Calculator"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                         -: Instruction :-"<<endl;
    cout <<"# This program performs basic arithmetic operations."<<endl;
    cout <<"# You can enter two numbers and choose an operator to calculate."<<endl;
    cout <<"# Supported operations: Addition (+), Subtraction (-), Multiplication (*), Division (/)."<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;

    cout<<"\nEnter the 1st number - ";
    cin>>num1;
    cout<<"\nEnter the 2nd number - ";
    cin>>num2;
    cout<<"\nEnter the Operator : ";
    cin>>ch;
    cout<<"\nSolution -: ";

    switch (ch)
    {
    case '+':
        cout<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
        break;
    
    case '-':
        cout<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
        break;

    case '*':
        cout<<num1<<" * "<<num2<<" = "<<num1*num2<<endl;
        break;

    case '/':
        if(num2 != 0){
            cout<<num1<<" / "<<num2<<" = "<<num1/num2<<endl;  
        }
        else{
            cout << "Error: Division by zero is not allowed." << endl;
        }
        break;

    default:
        cout<<"Error: Invalid operator " << ch << " Please use '+', '-', '*', or '/'" << endl;
        break;
    }
    return 0;
}