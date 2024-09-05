#include "NPC.h"

vector<Item> wandering={a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10]};
vector<Item> gotcha={a[11]};

NPC WanderingTrader("Santa","HoHoHo!Wanna get an item?",wandering,0,1);//0,1
NPC Trader("Elon Ma","Hello everyone.WOW!Buy things with Dogecoin.WOW! Everything things Costs Only 20 Dogecions",wandering,20,1);//2,3
NPC getcha("LootBox","One Roll Only 10 Dollars",gotcha,20,0);//4

NPC::NPC(){
}

NPC::NPC(string name,string script,vector<Item> sale,int cost,int show) :GameCharacter(name,100,100,100){
    this->script=script;
    this->commodity=sale;
    this->cost=cost;
    this->show=show;
}

int NPC::triggerEvent(){
    cout<<"A.buy"<<endl<<"B.pass"<<endl;
    string a;
    cin>>a;
    int temp=2;
    if(a.compare("A")==0){
        return temp-1;
    }
    else if(a.compare("B")==0){
        return temp;
    }
}

Item NPC::listCommodity(){
    for(int i=0;i<wandering.size();i++){
        cout<<i<<". "<<a[i].getName()<<"   ";
    }
    cout<<endl;
    int s;
    cin >> s ;
    for(int i=0;i<11;i++){
        if(s==i){
            return a[i];
        }
    }
}

 void NPC::setScript(string script){
    this->script=script;
 }
 void NPC::setcost(int cost){
    this->cost=cost;
 }

 string NPC::getScript(){
    return this->script;
 }
 int NPC::getcost(){
    return this->cost;
 }
 int NPC::getshow(){
    return this->show;
 }
