#ifndef GAMECLASS_H
#define GAMECLASS_H

#include "Player.h"

class GameClass
{
public:
    static bool PlayerAction(Player* p1, Player* p2);
    static void GamePlay(Player* p1, Player* p2);
    static void Instructions();
    static void GameTitle();
};

#endif // GAMECLASS_H