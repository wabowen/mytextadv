//this defines the player object; the player character in game
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
#include"room.h"
using namespace std;

class player{
  private:
    string name;
    int health;//possibly float later?
    bool alive;
    int posX;
    int posY;
    int posZ;
    int level;
    int xp;

  public:
    //Gets:
    string getName();
    bool isAlive();
    int getHealth();
    int getPosX();
    int getPosY();
    int getPosZ();
    int getLevel();
    int getXP();

    //Sets:
    void setName(string nameSet);
    void setHealth(int healthSet);//set to arbitrary amount
    void changeHealth(int healthChange);//change by relative amount
    void die();
    void setPos(int x, int y, int z);
    void setLevel(int levelSet);//set to arbitrary amount
    void changeLevel(int levelChange);//change by relative amount
    void setXP(int xpSet);//set to arbitrary amount
    void changeXP(int xpChange);//change by relative amount

    //movement
    void goNorth(room& aRoom);
    void goSouth(room& aRoom);
    void goEast(room& aRoom);
    void goWest(room& aRoom);
    void goUp(room& aRoom);
    void goDown(room& aRoom);
};
#endif
