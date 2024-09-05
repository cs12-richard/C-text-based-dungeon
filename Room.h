#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Object.h"
#include "Monster.h"
#include "NPC.h"

using namespace std;

class Room
{
private:
    string name;
    int hungry;
    int thirsty;
    int poison1;
    int poison2;
    int damage;
public:
    Room();
    Room(string, int, int,int,int,int);
    void generatemap();
    void generateinside();
    /* Set & Get function*/

    string getName();
    int gethungry();
    int getthirsty();
    int getpoison1();
    int getpoison2();
    int getdamage();

};

extern Monster m[51][51];
extern NPC n[51][51];
extern Room r[51][51];


extern Room Desert;
extern Room DesertStorm;
extern Room DesertOasis;
extern Room Swamp;
extern Room Forest;
extern Room ForestLake;
extern Room Trap;
extern Room GasChamber;

#endif // ROOM_H_INCLUDED
