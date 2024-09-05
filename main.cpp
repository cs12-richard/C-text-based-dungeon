#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include "Room.h"


using namespace std;

int main(){
    srand(time(NULL));
    Dungeon d;
    d.createPlayer();
    d.createMap();
    //cout<< me.getHealth() <<endl;//<< m[4][4].getname() << n[4][4].getname() <<endl<< m[0][0].getname() << n[0][0].getname() <<endl;
    d.startGame();
    return 0;
}
