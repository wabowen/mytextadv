//Player class member functions
#include"player.h"

//Gets:-------------------------------------------------------------------------
string player::getName()
{
  return name;
}

bool player::isAlive()
{
  return alive;
}

int player::getHealth()
{
  return health;
}

int player::getPosX()
{
  return player::posX;
}

int player::getPosY()
{
  return player::posY;
}

int player::getPosZ()
{
return player::posZ;
}

int player::getLevel()
{
  return level;
}

int player::getXP()
{
  return xp;
}

//Sets:-------------------------------------------------------------------------
void player::setName(string nameSet)
{
  name = nameSet;
}

void player::setHealth(int healthSet)
{
  health = healthSet;
}

void player::changeHealth(int healthChange)
{
  health += healthChange;
}

void player::die()
{
  alive = false;
}

void player::setPos(int x, int y, int z)
{
  posX = x;
  posY = y;
  posZ = z;
}

void player::setLevel(int levelSet)
{
  level = levelSet;
}


void player::changeLevel(int levelChange)
{
  level += levelChange;
}

void player::setXP(int xpSet)
{
  xp = xpSet;
}

void player::changeXP(int xpChange)
{
  xp += xpChange;
}

//movement
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

void player::goUp(room& aRoom)
{
}

void player::goDown(room& aRoom)
{
}
