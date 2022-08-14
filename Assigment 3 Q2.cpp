#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//	Nick Timaskovs - K00260158
//	Assigment 3 - Q2

int main()
{
	int num, guess, tries = 0;
	srand(time(0)); // random number generator
	num = rand() % 1000 + 1; // random number between 1 and 1000
	cout << "===== Guess The Number Game =====\n\n";
	cout << "How to play: \n\n";
	cout << "1. The program generates a random number from 1 - 1000 \n";
	cout << "2. Your job is to guess the number in 10 or less tries! \n\n";

	do
	{
		cout << "Enter a number between (1 and 1000): ";
		tries++;
		//this bit of code throws an error message IF a input is a string/char
		while (!(cin >> guess) || guess>1000 || guess<1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!  Try again: \n";		
		}

		if (guess > num)
		{
			cout << "Too high, Try Again!\n\n";
		}
		else if (guess < num)
		{
			cout << "Too low, Try Again!\n\n";
		}
		else
		{
			cout << "\nEither you know the secret or you got lucky! (tries = "<<tries<<")" << endl;
			break;
		}
				
	} while (tries != 10);// Keep playing until you run out of 10 tries

	if (tries == 10 && guess == num)
		cout << "You know the secret!	(tries = "<<tries<<")" << endl;
	else if(tries == 10)
		cout << "You should be able to do better! The number was:"<< num << endl;
	return 0;
}

