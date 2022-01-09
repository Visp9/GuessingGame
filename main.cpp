#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <limits>

using namespace std;

int random;

int StartGame();

void Finished(int tries, int guess)
{
	string restart;
	cout << "Congrats, number " << random << " is correct! It took you " << tries << " tries to complete." << endl;
	cout << "you wanna start again? (yes/no)";
	cin >> restart;
	if (restart == "yes" || restart == "y")
	{
		StartGame();
	}
	else
	{
		cout << "Thank you for playing!" << endl;
	}
}

int StartGame()
{
	int guess, tries = 0, minnumber, maxnumber;

	srand(time(NULL));
	minnumber = 1;
	maxnumber = 100000;
	random = rand() % maxnumber + minnumber;

	while (true)
	{

		if (tries < 1) {
			cout << "Guess: ";
		}

		cin >> guess;
		tries += 1;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You can only use numbers! Game will be restared." << endl;
			StartGame();
		}

		if (guess > maxnumber || guess < minnumber)
		{
			cout << "You cant use numbers out of range! Game will be restarted." << endl;
			StartGame();
		}

		if (guess == random)
		{
			Finished(tries, guess);
		}
		else if (guess < random)
		{
			cout << guess << " To low!\nTry again: ";
		}
		else if (guess > random)
		{
			cout << guess << " To high!\nTry again: ";
		}
	}
}

int main()
{

	int minnumber, maxnumber;
	minnumber = 1;
	maxnumber = 100000;

	cout << R"(
	 _ __   _____      __  _   _  ___  __ _ _ __
	| '_ \ / _ \ \ /\ / / | | | |/ _ \/ _` | '__|
	| | | | __ /\ V  V /  | |_| |  __/ (_| | |
	|_| |_|\___ |\_/\_/    \__, |\___|\__,_|_|
			       |___/
	)" << endl;

	cout << "Welcome to Guessing Game 1.0!\n";
	cout << "Guess the number (" << minnumber << " - " << maxnumber << ")" << endl;
	StartGame();
	return 0;
}
