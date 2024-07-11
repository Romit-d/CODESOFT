#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    cout<<"\n----- Guess the Number Challange -----"<<endl;cout<<endl;
    cout<<"          -: Instruction :-     "<<endl;cout<<endl;
    cout<<"# Get feedback:- Too high, too low, or correct."<<endl;
    cout<<"# Guess the number:- Pick a number between 1 and 100."<<endl;
    cout<<"# Repeat until correct:- Continue guessing until you win."<<endl;
    cout<<endl;

    srand(time(0));
    int anynumber = rand() % 100 + 1;
    int guess;

    do
    {
        cout<<"Guess the number - ";
        cin>>guess;
        if(guess > anynumber){
            cout<<"Too High! Try again. "<<endl<<endl;
        }
        else if(guess < anynumber){
            cout<<"Too Low! Try again. "<<endl<<endl;;
        }
        else{
            cout<<"Congratulations! You guess the right number. "<<endl;
            cout<<"Thank you for playing. "<<endl<<endl;;
        }
    } while (guess != anynumber);
    
    return 0;
}

