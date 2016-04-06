//This defines a room object; the various locations in game.
#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include<string>
using namespace std;

const int MAP_MAX_X = 5;
const int MAP_MAX_Y = 5;
const int MAP_MAX_Z = 2;

class room{
  private:
    string longDesc;
    string shortDesc;
    int posX;
    int posY;
    int posZ;
    bool exists;
    bool visited;

  public:
    //Constructor/Destructor:
    room();
    //~room();

    //Gets:
    string showLongDesc();
    string showShortDesc();
    bool beenVisited();
    bool testIfExists();
    bool testIfExists(room& aRoom);//not sure if needed atm

    //Sets
    void setLongDesc(string longDescChange);
    void setShortDesc(string shortDescChange);
    void setVisited(bool visitSet);
    void setExists(bool existsSet);
};
#endif
