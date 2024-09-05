#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    string name;
    int Health;
    int attack;
    int defense;
public:
    GameCharacter();
    GameCharacter(string,int,int,int);
    int checkIsDead();
    void takeDamage(int);

    /* Set & Get function*/
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setname(string);
    string getname();
    int getHealth();
    int getAttack();
    int getDefense();
    virtual int triggerEvent()=0;
};
#endif // GAMECHARACTER_H_INCLUDED
