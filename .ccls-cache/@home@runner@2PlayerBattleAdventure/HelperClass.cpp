/*
Includes the definition of all the helper class member fucntions.
*/

#include "HelperClass.h"
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

char HelperClass::CurrentOppositionPlayer(char _player)
{
	char _oppositePlayer = (_player == '1') ? '2' : '1';
	return _oppositePlayer;
}

void HelperClass::DisplayGreenLine()
{
	cout << "\033[32m" << '+' << setfill('+') << setw(90) << right << '+'
		<< "\033[0m" << endl
		<< endl;
}

int HelperClass::RandomDamageGenerator(int base, int max, int min)
{
	int randomNumber;
	randomNumber = base + (rand() % (max + 1 - min) + min);
	return randomNumber;
}

int HelperClass::RandomHealingGenerator(int max, int min)
{
	int randomNumber;
	randomNumber = (rand() % (max + 1 - min) + min);
	return randomNumber;
}

int HelperClass::RandomNumberGenerator(int x)
{
	int randomNumber;
	randomNumber = rand() % x;
	return randomNumber;
}

void HelperClass::ClearBadBits()
{
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
