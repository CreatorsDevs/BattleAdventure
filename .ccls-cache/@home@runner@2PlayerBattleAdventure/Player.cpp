/*
Includes the definition of player class member function.
*/

#include "Player.h"
#include "HelperClass.h"
#include <iostream>
using namespace std;

bool Player::TakeDamage(int dmg)
{
    bool unableToTakeDamage = false;
    health -= dmg;
    if (health <= 0) {
        unableToTakeDamage = true;
        cout << "Very unfortunate! Player " << currentPlayer << " has died.\n"
            << "Player " << oppositePlayer << " has won the game!\n\n";
        HelperClass::DisplayGreenLine();
        return unableToTakeDamage;
    }
    else {
        unableToTakeDamage = false;
        cout << "Player " << currentPlayer << "'s deteriorated health is "
            << health << endl;
        return unableToTakeDamage;
    }
}

void Player::Heal()
{
    int heal = HelperClass::RandomHealingGenerator(maxHeal, minHeal);
    if (health == fullhealth) {
        cout << "Healing cancelled!\nPlayer " << currentPlayer
            << "'s Health is already full.\n";
        return;
    }
    health += heal;
    if (health >= fullhealth) {
        health = fullhealth;
    }
    cout << "Player " << currentPlayer << " received " << heal << " healing!\n"
        << "Player's updated health is " << health << endl;
}