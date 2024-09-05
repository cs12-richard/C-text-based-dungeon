#include "GameCharacter.h"

GameCharacter::GameCharacter(){
}

GameCharacter::GameCharacter(string name,int Health,int attack,int defense) {
    this->name=name;
    this->Health=Health;
    this->attack=attack;
    this->defense=defense;
}



void GameCharacter::setHealth(int health){
    this->Health=health;
}
void GameCharacter::setAttack(int attack){
    this->attack=attack;
}
void GameCharacter::setDefense(int defense){
    this->defense=defense;
}
void GameCharacter::setname(string name){
    this->name=name;
}

string GameCharacter::getname(){
    return this->name;
}
int GameCharacter::getHealth(){
    return this->Health;
}
int GameCharacter::getAttack(){
    return this->attack;
}
int GameCharacter::getDefense(){
    return this->defense;
}

int GameCharacter::checkIsDead(){
    if(Health>0){
        return 1;
    }
    else{
        return 0;
    }
}

void GameCharacter::takeDamage(int damege){
    this->Health-=damege;
}
