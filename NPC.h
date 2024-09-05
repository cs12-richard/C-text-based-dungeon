#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    int cost;
    int show;
public:
    vector<Item> commodity;

    NPC();
    NPC(string, string, vector<Item>,int,int);
    Item listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    int triggerEvent();

    /* Set & Get function*/
    void setScript(string);
    //void setCommodity(vector<Item>);
    void setcost(int);

    string getScript();
    //vector<Item> getCommodity();
    int getcost();
    int getshow();
};

extern vector<Item> wandering;
extern vector<Item> gotcha;

extern NPC WanderingTrader;
extern NPC Trader;
extern NPC getcha;


#endif // NPC_H_INCLUDED
