/*
Includes the definition of all the available characters!
*/

#include "Characters.h"
#include "HelperClass.h"
#include <iostream>
using namespace std;

#define ANDRO_SPECIAL_DAMAGE 200
#define JEN_SPECIAL_HEAL 200
#define CASE_SPECIAL_DAMAGE 250

Andro::Andro(char _player) {
  randomCount = 0;
  health = 500;
  fullhealth = 500;
  baseDamage = 80;
  maxDamage = 60;
  minDamage = 40;
  maxHeal = 50;
  minHeal = 30;
  currentPlayer = _player;
  oppositePlayer = HelperClass::CurrentOppositionPlayer(currentPlayer);

  cout << "\nPlayer " << currentPlayer << " is an Andro!\n"
       << "Health is: " << fullhealth << endl;
}

int Andro::DoDamage() {
  int damage =
      HelperClass::RandomDamageGenerator(baseDamage, maxDamage, minDamage);
  randomCount = HelperClass::RandomNumberGenerator(8);
  if (randomCount >= 7) {
    randomCount = 0;
    cout << "Andro's ACCURSED ARM has been activated!\n"
         << "Player " << currentPlayer
         << " lands critical blow of 200 damage.\n";
    return ANDRO_SPECIAL_DAMAGE;
  } else {
    cout << "Player " << currentPlayer << " dealt " << damage << " damage."
         << endl;
    return damage;
  }
}

Jen::Jen(char _player) {
  randomCount = 0;
  health = 700;
  fullhealth = 700;
  baseDamage = 50;
  maxDamage = 50;
  minDamage = 30;
  maxHeal = 70;
  minHeal = 50;
  currentPlayer = _player;
  oppositePlayer = HelperClass::CurrentOppositionPlayer(currentPlayer);

  cout << "Player " << currentPlayer << " is a Jen!\n"
       << "Health is: " << fullhealth << endl;
}

int Jen::DoDamage() {
  int damage =
      HelperClass::RandomDamageGenerator(baseDamage, maxDamage, minDamage);
  cout << "Player " << currentPlayer << " dealt " << damage << " damage."
       << endl;
  return damage;
}

void Jen::Heal() {
  int heal = HelperClass::RandomHealingGenerator(maxHeal, minHeal);
  if (health == fullhealth) {
    cout << "Healing cancelled!\nPlayer " << currentPlayer
         << "'s Health is already full.\n";
    return;
  }
  randomCount = HelperClass::RandomNumberGenerator(6);
  if (randomCount <= 4) {
    health += heal;
    if (health >= fullhealth) {
      health = fullhealth;
    }
    cout << "Player " << currentPlayer << " received " << heal << " healing!\n"
         << "Player's updated health is " << health << endl;
  } else {
    randomCount = 0;
    cout << "Jen's ASTRAL SPACE has been activated!\n"
         << "Player " << currentPlayer
         << "'s health restored by a large extent.\n";
    health += JEN_SPECIAL_HEAL;
    if (health >= fullhealth) {
      health = fullhealth;
    }
    cout << "Player's updated health is " << health << endl;
  }
}

Case::Case(char _player) {
  randomCount = 0;
  health = 600;
  fullhealth = 600;
  baseDamage = 90;
  maxDamage = 70;
  minDamage = 50;
  maxHeal = 30;
  minHeal = 10;
  currentPlayer = _player;
  oppositePlayer = HelperClass::CurrentOppositionPlayer(currentPlayer);

  cout << "\nPlayer " << currentPlayer << " is a Case!\n"
       << "Health is: " << fullhealth << endl;
}

int Case::DoDamage() {
  int damage =
      HelperClass::RandomDamageGenerator(baseDamage, maxDamage, minDamage);
  randomCount = HelperClass::RandomNumberGenerator(9);
  if (randomCount >= 7) {
    randomCount = 0;
    cout << "Case's BLAST SHOT has been activated!\n"
         << "Player " << currentPlayer
         << " lands critical blow of 250 damage.\n";
    return CASE_SPECIAL_DAMAGE;
  } else {
    cout << "Player " << currentPlayer << " dealt " << damage << " damage."
         << endl;
    return damage;
  }
}