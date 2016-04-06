#include"room.h"
#include"player.h"
using namespace std;

//prototpes
void showIntro();
void showMenu();
void initializePlayer(player& player1); //may take multipile parameter lists later
void initializeMap(room map[MAP_MAX_X][MAP_MAX_Y][MAP_MAX_Z]);//5x5x2 square at a time. todo: if reach "edge", load a new one 
//just have 5x5x2 grid areas, if go out of bounds, check to see if another map file to load from. (world is broken into 5x5x2 sized pieces)

int main()
{
char input = 'z';//so it has a value, but nothing meaningful

showIntro();
//could put in another class/header files for reusability?
showMenu();//depending on what loads from here, where initialize and such might be called
//creat a player object in this scope to be initialized
player player1;
initializePlayer(player1);//send it to the initialize function
//------ load this shit from file at some point
room map[MAP_MAX_X][MAP_MAX_Y][MAP_MAX_Z];//array of rooms made in this scope
//todo: break intializeMap into another file
initializeMap(map);//send array to initialization function
//the main loop
do
{       //if haven't been visited yet, show long description of place
        if (!map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].setVisited(true);//been visited now
        }
    cin >> input;
    switch(input)
    {
      //this will be the main driver, just call function
      //all of the "direction" functions follow the same logic:
      //call move, check if exists, display description, long if not visited
      //short if visited
      case 'w':
      case 'W':
        //moves north
        player1.goNorth(map[player1.getPosX()][player1.getPosY()+1][player1.getPosZ()]);//"where" you would like to move
        //if doesn't exist/outside of bounds, continue in same room
        //testing purposes, shows grid position
        cout << player1.getPosX() << "   " << player1.getPosY() << "    " << player1.getPosZ() << endl;
        //if haven't been visited yet, show long description of place
        if (!map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].setVisited(true);//been visited now
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showShortDesc() << endl;
        }
      break;

      case 's':
      case 'S': 
        player1.goSouth(map[player1.getPosX()][player1.getPosY()-1][player1.getPosZ()]);
        cout << player1.getPosX() << "   " << player1.getPosY() << "    " << player1.getPosZ() << endl;
        if (!map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].setVisited(true);
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showShortDesc() << endl;
        }
      break;
      case 'd':
      case 'D':
        player1.goEast(map[player1.getPosX()+1][player1.getPosY()][player1.getPosZ()]);
        cout << player1.getPosX() << "   " << player1.getPosY() << "    " << player1.getPosZ() << endl;
        if (!map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].setVisited(true);
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showShortDesc() << endl;
        }
      break;
      case 'a':
      case 'A':
        player1.goWest(map[player1.getPosX()-1][player1.getPosY()][player1.getPosZ()]);
        cout << player1.getPosX() << "   " << player1.getPosY() << "    " << player1.getPosZ() << endl;
        if (!map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].setVisited(true);
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()][player1.getPosZ()].showShortDesc() << endl;
        }
      break;
      case 'q':
      case 'Q':
      break;
      default:
      cout << "invalid" << endl;
      break;
    }
}while(input != 'q');
//some stuff for when quit. maybe call menu, etc.
//or have it as a function from the case statement?
return 0;
}

void showIntro()
{
  cout << "THIS WOULD BE THE INTRO/ASCII ART/WHATEVER" << endl;
}

void showMenu()
{
  cout << "THIS WOULD BE THE MENU (load/save/new/etc)" << endl;
}

void initializePlayer(player& player1)
{
  //initialize. might want to load from a file or other stuff
  //as of now its all just static 
    player1.setPos(0,0,0);//set player starting position
    player1.setHealth(100);
    player1.setLevel(1);
    player1.setXP(0);
    cout << "initialize player ran" << endl;
    //any other initialization as needed
}

void initializeMap(room map[MAP_MAX_X][MAP_MAX_Y][MAP_MAX_Z])//takes array of room objects
{
  cout << "beginning of initialize room" << endl;
    //makes map of room objects. (5x5x2)
    //todo:
    //load new 5x5x2 grid (if available/is how big the map is/etc) from file and load it
    //maybe change the strings and variables, just read those in. that might work
    //------------MAP DESIGN--------------------
    //
    map[0][0][0].setLongDesc("You are in a graveyard. It is dirty and gross");
    map[0][0][0].setShortDesc("Graveyard");
    map[0][0][0].setVisited(false);
    map[0][0][0].setExists(true);

    map[1][0][0].setLongDesc("You are in the back alley, it is narrow.");
    map[1][0][0].setShortDesc("back alley");
    map[1][0][0].setVisited(false);
    map[1][0][0].setExists(true);

    map[2][0][0].setLongDesc("You are in the chicken ladys backyard. it is big");
    map[2][0][0].setShortDesc("Chicken ladys backyard"); 
    map[2][0][0].setVisited(false);
    map[2][0][0].setExists(true);
    
    map[3][0][0].setLongDesc("You are in the chicken ladys house. it is big");
    map[3][0][0].setShortDesc("Chicken ladys house"); 
    map[3][0][0].setVisited(false);
    map[3][0][0].setExists(true);

    map[4][0][0].setLongDesc("You are in the chicken ladys bedroom (!?)");
    map[4][0][0].setShortDesc("Chicken Ladys Bedroom"); 
    map[4][0][0].setVisited(false);
    map[4][0][0].setExists(true);

    map[0][1][0].setLongDesc("You are in the north alley (1/2)");
    map[0][1][0].setShortDesc("down the alley"); 
    map[0][1][0].setVisited(false);
    map[0][1][0].setExists(true);

    map[1][1][0].setLongDesc("You are in an epic circus tent, the size of which you have never seen before");
    map[1][1][0].setShortDesc("Circus Tent");
    map[1][1][0].setVisited(false);
    map[1][1][0].setExists(true);
    
    map[2][1][0].setLongDesc("You are in the banana stand.");
    map[2][1][0].setShortDesc("Banana Stand");
    map[2][1][0].setVisited(false);
    map[2][1][0].setExists(true);
    
    map[3][1][0].setLongDesc("You are in the windmill.");
    map[3][1][0].setShortDesc("In the Windmill");
    map[3][1][0].setVisited(false);
    map[3][1][0].setExists(true);
    
    map[4][1][0].setLongDesc("");
    map[4][1][0].setShortDesc("");
    map[4][1][0].setVisited(false);
    map[4][1][0].setExists(false);

    map[0][2][0].setLongDesc("You have gone way up the alley(long) 2/2");
    map[0][2][0].setShortDesc("further up the north alley (short)");
    map[0][2][0].setVisited(false);
    map[0][2][0].setExists(true);
    
    map[1][2][0].setLongDesc("");
    map[1][2][0].setShortDesc("");
    map[1][2][0].setVisited(false);
    map[1][2][0].setExists(false);
    
    map[2][2][0].setLongDesc("You are down by the docks opposite Front Street");
    map[2][2][0].setShortDesc("The Docks");
    map[2][2][0].setVisited(false);
    map[2][2][0].setExists(true);
    
    map[3][2][0].setLongDesc("You are on 3rd street");
    map[3][2][0].setShortDesc("3rd street");
    map[3][2][0].setVisited(false);
    map[3][2][0].setExists(true);
    
    map[4][2][0].setLongDesc("You are behind the bushes");
    map[4][2][0].setShortDesc("Behind the Bushes");
    map[4][2][0].setVisited(false);
    map[4][2][0].setExists(true);

    map[0][3][0].setLongDesc("you are in the town center, it is bustly and full of people");
    map[0][3][0].setShortDesc("Town Center");
    map[0][3][0].setVisited(false);
    map[0][3][0].setExists(true);
    
    map[1][3][0].setLongDesc("You are in the park");
    map[1][3][0].setShortDesc("in the park");
    map[1][3][0].setVisited(false);
    map[1][3][0].setExists(true);
    
    map[2][3][0].setLongDesc("You are out on Front Street, by the river.");
    map[2][3][0].setShortDesc("On Front Street");
    map[2][3][0].setVisited(false);
    map[2][3][0].setExists(true);
    
    map[3][3][0].setLongDesc("");
    map[3][3][0].setShortDesc("");
    map[3][3][0].setVisited(false);
    map[3][3][0].setExists(false);
    
    map[4][3][0].setLongDesc("");
    map[4][3][0].setShortDesc("");
    map[4][3][0].setVisited(false);
    map[4][3][0].setExists(false);

    map[0][4][0].setLongDesc("The entrance to the castle looms ahead here");
    map[0][4][0].setShortDesc("In Front of Castle Bowen");
    map[0][4][0].setVisited(false);
    map[0][4][0].setExists(true);
    
    map[1][4][0].setLongDesc("You are in Saltys Bar, a crappy hole in the wall bar.");
    map[1][4][0].setShortDesc("Inside Saltys Bar");
    map[1][4][0].setVisited(false);
    map[1][4][0].setExists(true);
   
    map[2][4][0].setLongDesc("You are in the alley behind Saltys Bar");
    map[2][4][0].setShortDesc("Behind Saltys");
    map[2][4][0].setVisited(false);
    map[2][4][0].setExists(true);
    
    map[3][4][0].setLongDesc("");
    map[3][4][0].setShortDesc("");
    map[3][4][0].setVisited(false);
    map[3][4][0].setExists(false);
    
    map[4][4][0].setLongDesc("");
    map[4][4][0].setShortDesc("");
    map[4][4][0].setVisited(false);
    map[4][4][0].setExists(true);
cout << "this is the end of map initialize" << endl; 
}
