#ifndef TA_HEADER_H
#define TA_HEADER_H
#include<iostream>
#include<string>
using namespace std;

class room{
  private:
    string longDesc;
    string shortDesc;
    int posX;
    int posY;
    bool exists;
    bool visited;
  public:
    string showLongDesc();
    string showShortDesc();
    void setLongDesc(string longDescChange);
    void setShortDesc(string shortDescChange);
    bool beenVisited();
    void setVisited(bool visitSet);
    bool testIfExists(room& aRoom);
    bool testIfExists();
    void setExists(bool existsSet);
};

class player{
  private:
    string name;
    int health;//possibly float later?
    bool alive;
    int posX;
    int posY;
    int level;
    int xp;
    //whatever else I want
  public:
    void setName(string nameSet);
    string getName();
    void setHealth(int healthSet);
    void changeHealth(int healthChange);
    int getHealth();
    void die();
    bool isAlive();
    void setPos(int x, int y);
    int getPosX();
    int getPosY();
    void goNorth(room& aRoom);
    void goSouth(room& aRoom);
    void goEast(room& aRoom);
    void goWest(room& aRoom);
    void setLevel(int levelSet);
    int getLevel();
    void changeLevel(int levelChange);
    void setXP(int xpSet);
    int getXP();
    void changeXP(int xpChange);
};

#endif
