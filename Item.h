#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;


class Item: public Object
{
private:
    int health,attack,defense,hungry,thirsty,poison1,poison2,use;//use=0 erase
public:
    Item();
    Item(string, int, int, int,int,int,int,int,int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    int triggerEvent();

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int gethungry();
    int getthirsty();
    int getpoison1();
    int getpoison2();
    int getuse();

    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void sethungry(int);
    void setthirsty(int);
    void setpoison1(int);
    void setpoison2(int);
};

extern Item a[12];



#endif // ITEM_H_INCLUDED
