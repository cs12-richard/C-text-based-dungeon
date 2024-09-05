#include "Item.h"

Item a[12]={Item("Rust Sword",0,10,0,0,0,0,0,1),Item("Baguette,aka french bread",0,80,0,0,0,0,0,1),Item("Candy Cane",0,20,0,0,0,0,0,0),Item("ExCurryBruh",0,15,0,0,0,0,0,1), \
            Item("Rust Armor",0,0,20,0,0,0,0,1),Item("Plastic Bag",0,0,5,0,0,0,0,1),Item("King's New Cloth",0,0,80,0,0,0,0,1),Item("CM Wang's picture",5,0,0,5,5,0,0,0), \
            Item("Member-only Restaurant,Special Desert:Pudding",10,0,0,50,0,1,1,0),Item("Oyster mo Oyster,DuckEgg mo Duck Egg",50,0,0,50,0,0,0,0), \
            Item("milk",5,0,0,10,10,0,0,0),Item("nothing HAHA",0,0,0,0,0,0,0,0)};

//Item a[0]("Rust Sword",0,10,0,0,0,0,0);/
//Item a[1]("Baguette,aka french bread",0,80,0,0,0,0,0);/
//Item a[2]("Candy Cane",0,20,0,0,0,0,0);/
//Item a[3]("ExCurryBruh",0,15,0,0,0,0,0);

//Item a[4]("Rust Armor",0,0,20,0,0,0,0);
//Item a[5]("Plastic Bag",0,0,5,0,0,0,0);
//Item a[6]("King's New Cloth",0,0,80,0,0,0,0);

//Item a[7]("CM Wang's picture",5,0,0,5,5,0,0);
//Item a[8]("Member-only Restaurant,Special Desert:Pudding",10,0,0,50,0,1,1);
//item a[9]("Oyster mo Oyster,DuckEgg mo Duck Egg",50,0,0,50,0,0,0);

//Item a[10]("milk",5,0,0,10,10,0,0);
//item a[11](nothig)


Item::Item(){
}
Item::Item(string name,int health,int attack,int defense,int hungry,int thirsty,int poison1,int poison2,int use) :Object(name,"item"){
    this->health=health;
    this->attack=attack;
    this->defense=defense;
    this->hungry=hungry;
    this->thirsty=thirsty;
    this->poison1=poison1;
    this->poison2=poison2;
    this->use=use;
}

void Item::setHealth(int health){
    this->health=health;
}
void Item::setAttack(int attack){
    this->attack=attack;
}
void Item::setDefense(int defense){
    this->defense=defense;
}
void Item::sethungry(int hungry){
    this->hungry=hungry;
}
void Item::setthirsty(int thirsty){
    this->thirsty=thirsty;
}
void Item::setpoison1(int poison1){
    this->poison1=poison1;
}
void Item::setpoison2(int poison2){
    this->poison2=poison2;
}

int Item::getHealth(){
    return this->health;
}
int Item::getAttack(){
    return this->attack;
}
int Item::getDefense(){
    return this->defense;
}
int Item::gethungry(){
    return this->hungry;
}
int Item::getthirsty(){
    return this->thirsty;
}
int Item::getpoison1(){
    return this->poison1;
}
int Item::getpoison2(){
    return this->poison2;
}
int Item::getuse(){
    return this->use;
}

int Item::triggerEvent(){
    cout<<"A.pick up"<<endl<<"B.no"<<endl;
    string b;
    if(b.compare("A")==0){
        return 1;
    }
    else{
        return 2;
    }
}
