#ifndef PLAYER_H
#define PLAYER_H

class Player
{
protected:
    int randomCount;
    int health, fullhealth;
    int baseDamage, addonDamage;
    int maxDamage, minDamage;
    int maxHeal, minHeal;
    char currentPlayer, oppositePlayer;

public:
    // Getter function
    int GetHealth() { return health; }
    // Virtual functions
    virtual int DoDamage(){ return 0;}
    virtual bool TakeDamage(int dmg);
    virtual void Heal();
};

#endif //!PLAYER_H