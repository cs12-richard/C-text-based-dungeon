#include "Monster.h"

Monster TreeSentinel("Tree Sentinel",50,20,9);//0
Monster JP("JP",30,30,0);//1,2
Monster Freekill("Freekill",1,0,0);//3,4
Monster Die("Creator's EX",1,10000,10000);//5

Monster::Monster(){
}

Monster::Monster(string name,int health,int attack,int defense) :GameCharacter(name,health,attack,defense){

}
int Monster::triggerEvent(){//°ÝÃD
    cout <<"A.fight"<<endl<<"B.retreat"<<endl;
    string choose;
    cin >> choose ;
    if(choose.compare("A")==0){
        return 1;
    }
    else{
        return 2;
    }

}
