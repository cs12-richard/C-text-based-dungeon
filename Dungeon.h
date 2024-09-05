#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"

using namespace std;

extern  Player me;
extern int gameend;

class Dungeon{
private:
public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();


};


#endif // DUNGEON_H_INCLUDED
