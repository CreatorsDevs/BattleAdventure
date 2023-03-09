#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Player.h"

class Andro : public Player 
{
public:
    Andro(char _player);
    int DoDamage() override;
};

class Jen : public Player 
{
public:
    Jen(char _player);
    int DoDamage() override;
    void Heal() override;
};

class Case : public Player 
{
public:
    Case(char _player);
    int DoDamage() override;
};

#endif // !CHARACTERS_H
