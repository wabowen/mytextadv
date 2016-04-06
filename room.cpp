//Room class member functions
#include"room.h"

//Constructor/Destructor:-------------------------------------------------------
room::room()
{
longDesc = "Default Long Description";
shortDesc = "Default Short Description";
exists = true;
visited = false;
}

//room::~room()
//{
//haven't needed yet
//}

//Gets:-------------------------------------------------------------------------
string room::showLongDesc()
{
return longDesc;
}

string room::showShortDesc()
{
  return shortDesc;
}

bool room::beenVisited()
{
  return visited;
}

bool room::testIfExists()
{
  return exists;
}

bool room::testIfExists(room& roomToTest)
{
  return roomToTest.exists;
}

//Sets:-------------------------------------------------------------------------
void room::setLongDesc(string longDescChange)
{
 longDesc = longDescChange;
}

void room::setShortDesc(string shortDescChange)
{
  shortDesc = shortDescChange;
}

void room::setVisited(bool visitSet)
{
  visited = visitSet;
}

void room::setExists(bool existsSet)
{
  exists = existsSet;  
}
