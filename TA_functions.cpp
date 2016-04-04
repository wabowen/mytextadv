#include"TA_header.h"
//PLAYER member functions

void player::setName(string nameSet)
{
  name = nameSet;
}

string player::getName()
{
  return name;
}

void player::setHealth(int healthSet)
{
  health = healthSet;
}

int player::getHealth()
{
  return health;
}

void player::changeHealth(int healthChange)
{
  health += healthChange;
}

void player::die()
{
  alive = false;
}

bool player::isAlive()
{
  return alive;
}

void player::setPos(int x, int y)
{
  posX = x;
  posY = y;
}

int player::getPosX()
{
  return player::posX;
}

int player::getPosY()
{
  return player::posY;
}

void player::goNorth(room& aRoom)
{
  if(posY == 4)//check bounds, array
  {
    //call to check for new map load/etc/
  }
  else if (aRoom.testIfExists())
  {
  posY += 1;
  }
  else
    cout << "You can't go that way." << endl;
}

void player::goSouth(room& aRoom)
{
  if (posY == 0)//its in an array, so no negative
  {
    //call to check for new map load/etc
  }
  else if (aRoom.testIfExists())
  {
  posY -= 1;
  }
  else
    cout << "You can't go that way." << endl;
}

void player::goEast(room& aRoom)
{
  if(posX == 4)//check bounds, array
  {
    //check load map etc
  }
  else if (aRoom.testIfExists())
  {
  posX += 1;
  }
  else
    cout << "You can't go that way." << endl;
}

void player::goWest(room& aRoom)
{
  if(posX == 0)
  {
    //check load map etc
  }
  else if (aRoom.testIfExists())
  {
  posX -= 1;
  }
  else
    cout << "You can't go that way." << endl;
}

void player::setLevel(int levelSet)
{
  level = levelSet;
}

int player::getLevel()
{
  return level;
}

void player::changeLevel(int levelChange)
{
  level += levelChange;
}

void player::setXP(int xpSet)
{
  xp = xpSet;
}

int player::getXP()
{
  return xp;
}

void player::changeXP(int xpChange)
{
  xp += xpChange;
}

//ROOM member functions

string room::showLongDesc()
{
  return longDesc;
}

string room::showShortDesc()
{
  return shortDesc;
}

void room::setLongDesc(string longDescChange)
{
 longDesc = longDescChange;
}

void room::setShortDesc(string shortDescChange)
{
  shortDesc = shortDescChange;
}

bool room::beenVisited()
{
  return visited;
}

void room::setVisited(bool visitSet)
{
  visited = visitSet;
}

bool room::testIfExists()
{
  return exists;
}

bool room::testIfExists(room& roomToTest)
{
  return roomToTest.exists;
}

void room::setExists(bool existsSet)
{
  exists = existsSet;  
}
