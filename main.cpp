/*
                                                      BATTLE ADVENTURE
CHARACTERS:

Andro  : Low health     (500) , Average damage 80(Base damage) + (40-60), Average healing  (30-50), Special ability - 200 damage in one go.
Jen    : High health    (700) , Low damage     50(Base damage) + (30-50), High healing     (50-70), Special ability - 200 healing in one go.
Case   : Average Health (600) , High damage    90(Base damage) + (50-70), Low healing      (10-30), Special ability - 250 damage in one go.

*/

#include "HelperClass.h"
#include "GameClass.h"
#include "Characters.h"

#include <iostream>
#include <limits>
using namespace std;

int main() {
    srand(time(0));
    GameClass::GameTitle();
    GameClass::Instructions();

    char input;

    do {
        // Game Starts Here!
        cout << "Press P to play the game or press any key to exit..." << endl;
        cin >> input;
        HelperClass::ClearBadBits();
        if (input == 'P' || input == 'p') {
            char player1, player2;
            Player* first = NULL, * second = NULL;

            // Character Selection Part!
            int inputCounter = 0;
            bool inputValid = false;
            do
            {
                if (inputCounter > 0 && !inputValid)
                    cout << "\nInvalid Input: Please enter valid input!\n";

                cout << "\nPlayer 1: Choose your character\n"
                    << "\n1: Andro \n2: Jen \n3: Case" << endl;
                cin >> player1;
                HelperClass::ClearBadBits();
                switch (player1) 
                {
                case '1':
                    first = new Andro('1'); inputValid = true;
                    break;
                case '2':
                    first = new Jen('1'); inputValid = true;
                    break;
                case '3':
                    first = new Case('1'); inputValid = true;
                    break;
                default:
                    inputValid = false;
                }
                inputCounter++;
            } while (!inputValid);

            inputCounter = 0;
            inputValid = false;

            do
            {
                if (inputCounter > 0 && !inputValid)
                    cout << "\nInvalid Input: Please enter valid input!\n";

                cout << "\nPlayer 2: Choose your character\n"
                    << "\n1: Andro \n2: Jen \n3: Case" << endl;
                cin >> player2;
                HelperClass::ClearBadBits();
                switch (player2)
                {
                case '1':
                    second = new Andro('2'); inputValid = true;
                    break;
                case '2':
                    second = new Jen('2'); inputValid = true;
                    break;
                case '3':
                    second = new Case('2'); inputValid = true;
                    break;
                default:
                    inputValid = false;
                }
                inputCounter++;
            } while (!inputValid);

            HelperClass::DisplayGreenLine();

            GameClass::GamePlay(first, second); // Game Play Starts Here!

            delete first;
            delete second;

        }
        else {
            cout << "\nThanks for playing!\nCome Back Soon!!!";
        }

    } while (input == 'P' || input == 'p');

    return 0;
}