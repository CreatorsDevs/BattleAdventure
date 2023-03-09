#ifndef HELPERCLASS_H
#define HELPERCLASS_H

class HelperClass
{
public:
    static char CurrentOppositionPlayer(char _player);
    static void DisplayGreenLine();
    static int RandomDamageGenerator(int base, int max, int min);
    static int RandomHealingGenerator(int max, int min);
    static int RandomNumberGenerator(int x);
    static void ClearBadBits();
};

#endif // !HELPERCLASS_H