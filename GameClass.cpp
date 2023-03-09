/*
This performs the actions related to current player's turn. 
*/

#include "GameClass.h"
#include "HelperClass.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool GameClass::PlayerAction(Player* p1, Player* p2)
{
    char userInput;
    bool unableToTakeDamage;
    
    int inputCounter = 0;
    bool inputValid = false;
    do
    {
        if (inputCounter > 0 && !inputValid)
            cout << "Invalid Input ..\n\n";

        cout << "Press A to Attack OR Press H to Heal:\n";
        cin >> userInput;
        HelperClass::ClearBadBits();
        cout << endl;
        if (userInput == 'A' || userInput == 'a') 
        {
            unableToTakeDamage = p2->TakeDamage(p1->DoDamage());
            return unableToTakeDamage;
            inputValid = true;
        }
        else if (userInput == 'H' || userInput == 'h') 
        {
            p1->Heal();
            return false;
            inputValid = true;
        }
        else
        {
            inputValid = false;
        }
        inputCounter++;
    } while(!inputValid);
}

void GameClass::GamePlay(Player* p1, Player* p2)
{
    do {
        bool unableToTakeDamage;

        // Player 1 Turn
        cout << "\nPlayer 1: It's your turn!" << '\n';
        unableToTakeDamage = PlayerAction(p1, p2);
        if (unableToTakeDamage == true) {
            break;
        } // Player has died. Thus, stop and break the game play!

        // Player 2 Turn
        cout << "\nPlayer 2: It's your turn!" << '\n';
        unableToTakeDamage = PlayerAction(p2, p1);
        if (unableToTakeDamage == true) {
            break;
        } // Player has died. Thus, stop and break the game play!

    } while (p1->GetHealth() > 0 && p2->GetHealth() > 0);
}

void GameClass::GameTitle() {
    cout << '!' << setfill('+') << setw(90) << '!' << endl;
    cout << '+' << setfill(' ') << setw(90) << '+' << endl;
    cout << '+' << setfill(' ') << setw(90) << '+' << endl;
    /*
      Used ANSI code for color coding.
      For reference, i am adding a link here:
      https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797.
    */
    cout << '+' << setfill(' ') << "\033[32m" << string(30, ' ') << setw(59)
        << left << "Two Player Battle Adventure"
        << "\033[0m" << '+' << endl;
    cout << '+' << setfill(' ') << setw(90) << right << '+' << endl;
    cout << '+' << setfill(' ') << setw(90) << '+' << endl;
    cout << '!' << setfill('+') << setw(90) << '!' << endl;
    //--------------------------------------------------------------------------------------------
}

void GameClass::Instructions() {
    cout << "\033[34m"
        << "\n\nABOUT THE GAME\n\n"
        << "\033[0m";

    cout << "1. Players are capable of damaging and healing.\n"
        << "2. Players have special ability which randomly gets called into an "
        "action.\n\n";

    cout << "\033[34m"
        << "GAME CHARACTERS\n\n"
        << "\033[0m"
        << "\033[35m"
        << "\"Andro\":"
        << "\033[0m"
        << " A legendary Assassin who commands the darkness.\n Special Damage "
        "Ability - \"ACCURSED ARM: It deals 200 damage in one shot.\"\n"
        << "\033[35m"
        << "\"Jen\":"
        << "\033[0m"
        << " An Ascended god who commands the life energies.\n Special Healing "
        "Ability - \"ASTRAL SPACE: It can restore the health by 200.\"\n"
        << "\033[35m"
        << "\"Case\":"
        << "\033[0m"
        << " The hunter's daughter also known as forest shadow.\n Special "
        "Damage Ability - \"BLAST SHOT: It deals 250 damage at once.\"\n\n";
    HelperClass::DisplayGreenLine();
}