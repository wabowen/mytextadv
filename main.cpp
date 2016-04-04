#include"TA_header.h"

//prototpes
void showIntro();
void showMenu();
void initializePlayer(player& player1); //may take multipile parameter lists later
void initializeMap(room map[5][5]);//5x5 square at a time. todo: if reach "edge", load a new one 
//just have 5x5 grid areas, if go out of bounds, check to see if another map file to load from. (world is broken into 5x5 pieces)

int main()
{
char input = 'z';
showIntro();
//could put in another class/header files for reusability?
showMenu();//depending on what loads from here, where initialize and such might be called
//creat a player object in this scope to be initialized
player player1;
initializePlayer(player1);//send it to the initialize function
//------ load this shit from file at some point
room map[5][5];//array of rooms made in this scope
//todo: break intializeMap into another file
initializeMap(map);//send array to initialization function
//the main loop
do
{       //if haven't been visited yet, show long description of place
        if (!map[player1.getPosX()][player1.getPosY()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()].setVisited(true);//been visited now
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
        player1.goNorth(map[player1.getPosX()][player1.getPosY()+1]);//"where" you would like to move
        //if doesn't exist/outside of bounds, continue in same room
        //testing purposes, shows grid position
        cout << player1.getPosX() << "   " << player1.getPosY() << endl;
        //if haven't been visited yet, show long description of place
        if (!map[player1.getPosX()][player1.getPosY()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()].setVisited(true);//been visited now
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()].showShortDesc() << endl;
        }
      break;
      case 's':
      case 'S': 
        player1.goSouth(map[player1.getPosX()][player1.getPosY()-1]);
        cout << player1.getPosX() << "   " << player1.getPosY() << endl;
        if (!map[player1.getPosX()][player1.getPosY()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()].setVisited(true);
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()].showShortDesc() << endl;
        }
      break;
      case 'd':
      case 'D':
        player1.goEast(map[player1.getPosX()+1][player1.getPosY()]);
        cout << player1.getPosX() << "   " << player1.getPosY() << endl;
        if (!map[player1.getPosX()][player1.getPosY()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()].setVisited(true);
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()].showShortDesc() << endl;
        }
      break;
      case 'a':
      case 'A':
        player1.goWest(map[player1.getPosX()-1][player1.getPosY()]);
        cout << player1.getPosX() << "   " << player1.getPosY() << endl;
        if (!map[player1.getPosX()][player1.getPosY()].beenVisited())
        {
        cout << map[player1.getPosX()][player1.getPosY()].showLongDesc() << endl;
        map[player1.getPosX()][player1.getPosY()].setVisited(true);
        }
        else
        {
        cout << map[player1.getPosX()][player1.getPosY()].showShortDesc() << endl;
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
    player1.setPos(0,0);//set player starting position
    player1.setHealth(100);
    player1.setLevel(1);
    player1.setXP(0);
    cout << "initialize player ran" << endl;
    //any other initialization as needed
}

void initializeMap(room map[5][5])//takes array of room objects
{
  cout << "beginning of initialize room" << endl;
    //makes "grid" of room objects. (5x5)
    //todo:
    //load new 5x5 grid (if available/is how big the map is/etc) from file and load it
    //maybe change the strings and variables, just read those in. that might work
    //------------MAP DESIGN--------------------
    //
    map[0][0].setLongDesc("You are in a graveyard. It is dirty and gross");
    map[0][0].setShortDesc("Graveyard");
    map[0][0].setVisited(false);
    map[0][0].setExists(true);

    map[1][0].setLongDesc("You are in the back alley, it is narrow.");
    map[1][0].setShortDesc("back alley");
    map[1][0].setVisited(false);
    map[1][0].setExists(true);

    map[2][0].setLongDesc("You are in the chicken ladys backyard. it is big");
    map[2][0].setShortDesc("Chicken ladys backyard"); 
    map[2][0].setVisited(false);
    map[2][0].setExists(true);
    
    map[3][0].setLongDesc("You are in the chicken ladys house. it is big");
    map[3][0].setShortDesc("Chicken ladys house"); 
    map[3][0].setVisited(false);
    map[3][0].setExists(true);

    map[4][0].setLongDesc("You are in the chicken ladys bedroom (!?)");
    map[4][0].setShortDesc("Chicken Ladys Bedroom"); 
    map[4][0].setVisited(false);
    map[4][0].setExists(true);

    map[0][1].setLongDesc("You are in the north alley (1/2)");
    map[0][1].setShortDesc("down the alley"); 
    map[0][1].setVisited(false);
    map[0][1].setExists(true);

    map[1][1].setLongDesc("");
    map[1][1].setShortDesc("");
    map[1][1].setVisited(false);
    map[1][1].setExists(true);
    
    map[2][1].setLongDesc("");
    map[2][1].setShortDesc("");
    map[2][1].setVisited(false);
    map[2][1].setExists(true);
    
    map[3][1].setLongDesc("");
    map[3][1].setShortDesc("");
    map[3][1].setVisited(false);
    map[3][1].setExists(true);
    
    map[4][1].setLongDesc("");
    map[4][1].setShortDesc("");
    map[4][1].setVisited(false);
    map[4][1].setExists(true);

    map[0][2].setLongDesc("You have gone way up the alley(long) 2/2");
    map[0][2].setShortDesc("further up the north alley (short)");
    map[0][2].setVisited(false);
    map[0][2].setExists(true);
    
    map[1][2].setLongDesc("");
    map[1][2].setShortDesc("");
    map[1][2].setVisited(false);
    map[1][2].setExists(true);
    
    map[2][2].setLongDesc("You are down by the docks opposite Front Street");
    map[2][2].setShortDesc("The Docks");
    map[2][2].setVisited(false);
    map[2][2].setExists(true);
    
    map[3][2].setLongDesc("");
    map[3][2].setShortDesc("");
    map[3][2].setVisited(false);
    map[3][2].setExists(true);
    
    map[4][2].setLongDesc("");
    map[4][2].setShortDesc("");
    map[4][2].setVisited(false);
    map[4][2].setExists(true);

    map[0][3].setLongDesc("you are in the town center, it is bustly and full of people");
    map[0][3].setShortDesc("Town Center");
    map[0][3].setVisited(false);
    map[0][3].setExists(true);
    
    map[1][3].setLongDesc("");
    map[1][3].setShortDesc("");
    map[1][3].setVisited(false);
    map[1][3].setExists(true);
    
    map[2][3].setLongDesc("You are out on Front Street, by the river.");
    map[2][3].setShortDesc("On Front Street");
    map[2][3].setVisited(false);
    map[2][3].setExists(true);
    
    map[3][3].setLongDesc("");
    map[3][3].setShortDesc("");
    map[3][3].setVisited(false);
    map[3][3].setExists(true);
    
    map[4][3].setLongDesc("");
    map[4][3].setShortDesc("");
    map[4][3].setVisited(false);
    map[4][3].setExists(true);

    map[0][4].setLongDesc("The entrance to the castle looms ahead here");
    map[0][4].setShortDesc("In Front of Castle Bowen");
    map[0][4].setVisited(false);
    map[0][4].setExists(true);
    
    map[1][4].setLongDesc("You are in Saltys Bar, a crappy hole in the wall bar.");
    map[1][4].setShortDesc("Inside Saltys Bar");
    map[1][4].setVisited(false);
    map[1][4].setExists(true);
   
    map[2][4].setLongDesc("You are in the alley behind Saltys Bar");
    map[2][4].setShortDesc("Behind Saltys");
    map[2][4].setVisited(false);
    map[2][4].setExists(true);
    
    map[3][4].setLongDesc("");
    map[3][4].setShortDesc("");
    map[3][4].setVisited(false);
    map[3][4].setExists(false);
    
    map[4][4].setLongDesc("");
    map[4][4].setShortDesc("");
    map[4][4].setVisited(false);
    map[4][4].setExists(true);
cout << "this is the end of map initialize" << endl; 
}
