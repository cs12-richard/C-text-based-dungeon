#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Item.h"


using namespace std;

class Player: public GameCharacter
{
private:
    int X;
    int Y;
    int hungry;
    int thirsty;
    int poison1;
    int poison2;
    int kill;
    vector<Item> inventory;
public:
    Player();
    Player(string,int,int,int,int,int,int,int,int,int,int);
    void addItem(Item);
    void setX(int);
    void setY(int);
    void sethungry(int);
    void setthirsty(int);
    void setpoison1(int);
    void setpoison2(int);
    void setKill(int);

    int getX();
    int getY();
    int gethungey();
    int getthirsty();
    int getpoison1();
    int getpoison2();
    int getKill();
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    int triggerEvent();

    /* Set & Get function*/

    void setInventory(vector<Item>);
    vector<Item> getInventory();
};

#endif // PLAYER_H_INCLUDED
