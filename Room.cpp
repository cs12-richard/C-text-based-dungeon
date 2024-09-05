#include "Room.h"

Monster m[51][51];
NPC n[51][51];
Room r[51][51];



Room Desert("==Desert==",5,20,0,0,0);
Room DesertStorm("==Desert:Sandstrom==",50,50,0,0,5);
Room DesertOasis("==Desert:Oasis==",5,-50,0,0,-10);
Room Swamp("==Swamp==",15,15,1,0,20);
Room Forest("==forest==",20,5,0,0,0);
Room ForestLake("==Forest:Lake==",20,-50,0,0,-10);
Room Trap("==Trap==",0,0,0,0,10000);
Room GasChamber("==GasChamp==",5,5,0,1,10);

Room::Room(){
}

Room::Room(string name,int hungry,int thirsty,int poison1,int poison2,int damage){
    this->name=name;
    this->hungry=hungry;
    this->thirsty=thirsty;
    this->poison1=poison1;
    this->poison2=poison2;
    this->damage=damage;
}
//generate
void Room::generatemap(){
    //roombackroud
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            int x=rand()%16;

            if(x>=0&&x<=2){
                r[i][j]=Desert;
            }
            else if(x==3){
                r[i][j]=DesertStorm;
            }
            else if(x==4){
                r[i][j]=DesertOasis;
            }
            else if(x>=5&&x<=7){
                r[i][j]=Swamp;
            }
            else if(x>=8&&x<=10){
                r[i][j]=Forest;
            }
            else if(x==11){
                r[i][j]=ForestLake;
            }
            else if(x>=12&&x<=14){
                r[i][j]=Trap;
            }
            else if(x==15){
                r[i][j]=GasChamber;
            }
        }
    }
}
void Room::generateinside(){
    //roominside
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            int x=rand()%2;

            if(x==1){//NPC
                m[i][j].setAttack(69);
                int y=rand()%5;

                if(y==4){
                    n[i][j]=getcha;
                }
                else if(y==3 || y==2){
                    n[i][j]=Trader;
                }
                else{
                    n[i][j]=WanderingTrader;
                }
            }
            else{//monster
                n[i][j].setAttack(69);
                int y=rand()%6;

                if(y==0){
                    m[i][j]=TreeSentinel;
                }
                else if(y==5){
                    m[i][j]=Die;
                }
                else if(y==3 || y==4){
                    m[i][j]=Freekill;
                }
                else{
                    m[i][j]=JP;
                }
            }
        }
    }

}


//get
string Room::getName(){
    return this->name;
}
int Room::gethungry(){
    return this->hungry;
}
int Room::getthirsty(){
    return this->thirsty;
}
int Room::getpoison1(){
    return this->poison1;
}
int Room::getpoison2(){
    return this->poison2;
}
int Room::getdamage(){
    return this->damage;
}
