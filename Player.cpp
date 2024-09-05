#include "Player.h"

Player::Player(){
}

Player::Player(string name,int health,int attack,int defense,int X,int Y,int hungry,int thirsty,int poison1,int poison2,int kill) :GameCharacter(name,health,attack,defense){
    this->X=X;
    this->Y=Y;
    this->hungry=hungry;
    this->thirsty=thirsty;
    this->poison1=poison1;
    this->poison2=poison2;
    this->kill=kill;
}

int Player::triggerEvent(){//°ÝÃD
        return 1;
}

void Player::addItem(Item pick){
    inventory.push_back(pick);
}
void Player::setX(int X){
    this->X+=X;
}
void Player::setY(int Y){
    this->Y+=Y;
}
void Player::sethungry(int hungry){
    this->hungry=hungry;
}
void Player::setthirsty(int thirsty){
    this->thirsty=thirsty;
}
void Player::setpoison1(int poison1){
    this->poison1=poison1;
}
void Player::setpoison2(int poison2){
    this->poison2=poison2;
}
void Player::setKill(int kill){
    this->kill+=kill;
}

int Player::getX(){
    return this->X;
}
int Player::getY(){
    return this->Y;
}
int Player::gethungey(){
    return this->hungry;
}
int Player::getthirsty(){
    return this->thirsty;
}
int Player::getpoison1(){
    return this->poison1;
}
int Player::getpoison2(){
    return this->poison2;
}
int Player::getKill(){
    return this->kill;
}
vector<Item> Player::getInventory(){
    return this->inventory;
}

