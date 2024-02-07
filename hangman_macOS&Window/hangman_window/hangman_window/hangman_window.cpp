//hangman_window.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Student ID & Name: T0278591, Leasther Anak Peter
//C++ Project (Hangman Game)
//Deadline: 24 April 2022
//In this C ++ Project (Hangman Game), you are given to guess the word and I use superhero characters from Marvel Studio
//You are given 8 lives, if you guess wrong, you will lose that life (one life) and if you guess the same word,
//program tell you to guess another word
//There are problem with this program when transfer to window (Visual Studio). The line 117, "}" is error but when the macbook, it's work out!!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

string thewords;
int wrong;
string soLetter;
string used;
string player1;


bool match(char letter, string words);
char askGuess(string usedLettersStr);
bool playAgain();

int main()
{
	srand(time(NULL));

	vector<string> superhero; // list the guess word
	superhero.push_back("THONAS");
	superhero.push_back("SPIDER MAN");
	superhero.push_back("CAPTAIN AMERICA");
	superhero.push_back("BLACK WIDOW");
	superhero.push_back("DOCTOR STRANGER");
	superhero.push_back("DEADPOOL");
	superhero.push_back("VISION");

	cout << "-------------------------------------\n";
	cout << "Welcome to Hangman. Good luck!\n";
	cout << "Please type in your name:\n";
	cin >> player1;
	cout << "------------------------------\n";
	cout << "Hi," << player1 << ", Welcome to Hangman! " << "Let's start with the game!" << endl;

	{
		const int MAX_WRONG = 8;  // maximum number of lives

		random_shuffle(superhero.begin(), superhero.end());
		thewords = superhero[(0)]; // word guess

		soLetter = string(thewords.size(), '-');
		used = ""; // previously guessed letters

		// loop for current word
		while ((wrong < MAX_WRONG) && (soLetter != thewords))
		{
			cout << "\n\nYou currently have " << (MAX_WRONG - wrong) << " lives!\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nThe guess word is:\n" << soLetter << endl;

			used += askGuess(used);

		} // end of while ((wrong < MAX_WRONG) && (soLetter != thewords))

		// shut down program
		if (wrong == MAX_WRONG) {
			cout << "\nSorry, you've been hanged!";

		}
		cout << "\nThe word was " << thewords << endl;

	} while (playAgain());

	return 0;
}

inline bool match(char letter, string word)
{
	return (word.find(letter) != string::npos);
}

char askGuess(string usedLettersStr)
{
	char guess;
	cout << "\n\nPlease enter your guess word: ";
	cin >> guess;
	guess = toupper(guess); //create uppercase since the secret word is in uppercase
//        while (used.find(guess) != string::npos)
	while (match(guess, used))
	{
		cout << "\nYou already guessed this letter" << guess << endl;
		cout << "Please enter another word: ";
		cin >> guess;
		guess = toupper(guess);
	}

	if (match(guess, thewords))
	{
		cout << "That's right! " << guess << " is in the word.\n";

		// update soLetter to include newly guessed letter
		for (int i = 0; i < thewords.length(); ++i)
			if (thewords[i] == guess)
				soLetter[i] = guess;
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		cout << "Please try again!\n";
		++wrong;
	}
}

bool playAgain()
{
	char again;
	cout << "\n\nDo you like to play again? <Y/N>: ";
	cin >> again;

	cin.clear();
	cin.ignore();

	again = toupper(again);

	system("cls");

	return (again == 'Y');
}