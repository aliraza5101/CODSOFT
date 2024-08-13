#include<iostream>
#include<ctime>
using namespace std;

int main(){
	
	srand(time(0));
	
	int targetNumber = rand() % 100 + 1;
	
	int userGuess = 0;
	
	cout<<"   HI! WELCOME TO THE NUMBER GUESSING GAME POWERED BY CODSOFT !\n\n";
	cout<<"Try to guess the number between 1 and 100: ";
	cin>>userGuess;
	
	while (userGuess != targetNumber)
	{
		if (userGuess < targetNumber)
		{
			cout<<"Too low! Please try again."<<endl;
		}
		else
		{
			cout<<"Too high! Please try again."<<endl;
		}
		cout<<"Enter another guess: ";
		cin>>userGuess;
	}	
	
		cout<<"Well done! You've guessed the number correctly!"<<endl;
		
		return 0;
}
