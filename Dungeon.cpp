#include "Dungeon.h"


int gameend=0;

Dungeon::Dungeon(){
}

string myname;
Player me(myname,200,20,10,25,25,150,150,0,0,0);

void Dungeon::createPlayer(){
    cout<<"====Welcome to Cursed Dungeon Story===="<<endl<<endl<<"==Here we use our blood as currency=="<<endl;
    cout<<"==You need to kill 5 monsters to win the dungeon=="<<endl;
    cout<<"==You will meet many NPCs and monsters here=="<<endl<<endl<<"==Please take care of yourself and enjoy creator's \"Goodwill\" =="<<endl<<endl;
    cout<<"====Let's get start!!!===="<<endl<<endl<<"==Please enter your name=="<<endl;
    string Playername;
    cin >> Playername ;
    me.setname(Playername);
}


void Dungeon::createMap(){
    Room o;
    o.generatemap();
    o.generateinside();
}

void Dungeon::startGame(){
    while(gameend==0){
        cout<<endl<<endl<<"==Select what you want to do=="<<endl<<"A. Move"<<endl<<"B. Check your status"<<endl;
        string todo;
        cin>>todo;
        if(todo.compare("A")==0){
            cout<<"A. Go Up"<<endl<<"B. Go Down"<<endl<<"C. Go Right"<<endl<<"D. Go Left"<<endl;
            string movemoent;
            cin>> movemoent ;
            //movement
            int movestep;
            if(movemoent.compare("A")==0){//1
                me.setY(1);
                //cout<<me.getX()<<me.getY()<<endl;

                movestep=1;
            }
            else if(movemoent.compare("B")==0){//2
                me.setY(-1);
                //cout<<me.getX()<<me.getY()<<endl;

                movestep=2;
            }
            else if(movemoent.compare("C")==0){//3
                me.setX(1);
                //cout<<me.getX()<<me.getY()<<endl;

                movestep=3;
            }
            else if(movemoent.compare("D")==0){//4
                me.setX(-1);
                //cout<<me.getX()<<me.getY()<<endl;

                movestep=4;
            }
            //room effect
            cout<<endl<<r[me.getX()][me.getY()].getName()<<endl;
            me.sethungry(me.gethungey()-r[me.getX()][me.getY()].gethungry());
            me.setthirsty(me.getthirsty()-r[me.getX()][me.getY()].getthirsty());
            me.setpoison1(r[me.getX()][me.getY()].getpoison1());
            me.setpoison2(r[me.getX()][me.getY()].getpoison2());
            me.setHealth(me.getHealth()-r[me.getX()][me.getY()].getdamage());
            //die or not
            if(me.getHealth()<=0){
                gameend=1;
                cout<<endl<<"====You Suck===="<<endl<<endl<<"====Game Over===="<<endl;
                return;
            }
            //things inside room

            //monster
            if(n[me.getX()][me.getY()].getAttack() == 69){
                cout<<"==Meet "<<m[me.getX()][me.getY()].getname()<<"=="<<endl;
                //monster retreat or fight

                    //retreat
                    int refi=m[me.getX()][me.getY()].triggerEvent();
                    if(refi==2){
                        if (movestep==1){
                            me.setY(-1);
                        }
                        else if (movestep==2){
                            me.setY(1);
                        }
                        else if (movestep==3){
                            me.setX(-1);
                        }
                        else if (movestep==4){
                            me.setX(1);
                        }
                        continue;
                    }
                    //fight

                    if(refi==1){
                        while(me.getHealth()>0 && m[me.getX()][me.getY()].getHealth()>0){

                            m[me.getX()][me.getY()].setHealth(m[me.getX()][me.getY()].getHealth()-me.getAttack()+m[me.getX()][me.getY()].getDefense());

                            if(m[me.getX()][me.getY()].getHealth()<=0){
                                me.setKill(1);
                                cout<<"You kill "<<m[me.getX()][me.getY()].getname()<<endl;
                                continue;
                            }
                            me.setHealth(me.getHealth()-m[me.getX()][me.getY()].getAttack()+me.getDefense());
                            if(me.getHealth()<=0){
                                gameend=1;
                                cout<<endl<<"====You Suck===="<<endl<<endl<<"====Game Over===="<<endl;
                                return;
                            }
                        }
                    }
            }



              //npc
              else{
                cout<<"==Encounter "<<n[me.getX()][me.getY()].getname()<<"=="<<endl<<endl;
                cout<<n[me.getX()][me.getY()].getScript()<<endl;
                //no buy
                int buy=n[me.getX()][me.getY()].triggerEvent();
                if(buy==2){
                    continue;
                }
                //buy
                else{
                    if(n[me.getX()][me.getY()].getshow()==1){
                    Item thingsbuy=n[me.getX()][me.getY()].listCommodity();
                    cout<<"You get "<<thingsbuy.getName()<<"!"<<endl;
                    me.setHealth(me.getHealth()+thingsbuy.getHealth()-n[me.getX()][me.getY()].getcost());
                    me.setAttack(me.getAttack()+thingsbuy.getAttack());
                    me.setDefense(me.getDefense()+thingsbuy.getDefense());
                    me.sethungry(me.gethungey()+thingsbuy.gethungry());
                    me.setthirsty(me.getthirsty()+thingsbuy.getthirsty());
                    me.setpoison1(thingsbuy.getpoison1());
                    me.setpoison2(thingsbuy.getpoison2());
                        if(thingsbuy.getuse()==1){
                        me.addItem(thingsbuy);
                        }
                    continue;
                    }
                    else{
                        me.setHealth(me.getHealth()-20);
                        cout<<"You get nothig! Try next time!"<<endl;
                        continue;
                    }
                }
                }


              //check hun thir
              if(me.gethungey()<0){
                me.setHealth(me.getHealth()-10);
              }
              if(me.getthirsty()<0){
                me.setHealth(me.getHealth()-20);
              }

              //check poison
              if(me.getpoison1()==1){
                me.setHealth(me.getHealth()-5);
              }
              if(me.getpoison2()==1){
                me.setHealth(me.getHealth()-25);
                me.setAttack(me.getAttack()/2);
              }
              //check win or die
              if(me.getKill()>=5){
                gameend=1;
                cout<<"====You Win!   Congratulation!====";
                return;
              }
              else if (me.getHealth()<=0){
                gameend=1;
                cout<<"====You Suck===="<<endl<<endl<<"====Game Over===="<<endl;
                return;
              }

        }

        //check status
        else if(todo.compare("B")==0){
            if(me.triggerEvent()==1){
                cout<<endl<<"Player's Name:"<<me.getname()<<endl;
                cout<<"Health: "<<me.getHealth()<<endl;
                cout<<"Attack: "<<me.getAttack()<<endl;
                cout<<"Defense: "<<me.getDefense()<<endl;
                cout<<"Hungry: "<<me.gethungey()<<endl;
                cout<<"Thirsty: "<<me.getthirsty()<<endl;
                cout<<"Kill: "<<me.getKill()<<endl;
                vector<Item> itep=me.getInventory();
                cout<<"Items: ";
                for(int i=0;i<itep.size();i++){
                    cout<<itep[i].getName()<<"  ";
                }
                cout<<endl<<"State: ";
                if(me.getpoison1()==1){
                    cout<<"Food Poisoning ( Health-5 every move ) ";
                }
                if(me.getpoison2()==1){
                    cout<<"Sarin ( Health-20 Attack/2 every move )";
                }
            }
        }
}
    }




