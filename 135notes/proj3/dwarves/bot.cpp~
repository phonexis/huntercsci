
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;

/* onStart: 
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do 
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

bool isNextToATree(Dwarf & dwarf, int r, int c){
  
  Place left=dwarf.look(r, c-1);
  Place right=dwarf.look(r, c+1);
  Place down=dwarf.look(r-1, c);
  Place up=dwarf.look(r+1, c);
    
  if(left == PINE_TREE/* || left == APPLE_TREE*/){ //tree left and right
    return true;
  }
  else if(right == PINE_TREE/* || right == APPLE_TREE*/){ //tree left and right
    return true;
  }
  else if(down == PINE_TREE/* || down == APPLE_TREE*/){ //tree left and right
    return true;
  }
  else if(up == PINE_TREE/* || up == APPLE_TREE*/){ //tree left and right
    return true;
  }
  else {
    return false;
  }  
}

/* onAction: 
A procedure called each time an idle dwarf is choosing 
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
    minutes: number of minutes (0-59)
    log:     a cout-like log  */

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();

  int newc=c;
  int newr=r;
  static bool reverse=false;
  
  // Look if there is a tree on the right from the dwarf
  if (dwarf.look(r, c+1) == PINE_TREE/* || dwarf.look(r, c+1) == APPLE_TREE*/) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop" << endl;
    dwarf.start_chop(EAST);
    return;
  }
  else if (dwarf.look(r, c-1) == PINE_TREE/* || dwarf.look(r, c-1) == APPLE_TREE*/) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop" << endl;
    dwarf.start_chop(WEST);
    return;
  }
  else if (dwarf.look(r+1, c) == PINE_TREE/* || dwarf.look(r+1, c) == APPLE_TREE*/) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop" << endl;
    dwarf.start_chop(SOUTH);
    return;
  }
  else if (dwarf.look(r-1, c) == PINE_TREE/* || dwarf.look(r-1, c) == APPLE_TREE*/) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop" << endl;
    dwarf.start_chop(NORTH);
    return;
  }
  //ORIGINAL STATEMENT TO MOVE
  /*else {
  // Otherwise, move to a random location
  int rr = rand() % ROWS;
  int cc = rand() % COLS;
  log << "Walk to " << rr << " " << cc << endl;
  dwarf.start_walk(rr, cc);
  return;
  }
  */
  else {
    /*
      int rr = rand() % ROWS;
      int cc = rand() % COLS;
      if(isNextToATree(dwarf,rr,cc)){
      log << "Walk to " << rr << " " << cc << endl;
      dwarf.start_walk(rr, cc);
      return;
      }
      while(!isNextToATree(dwarf,rr,cc)){ //makes new random numbers until next to a pine tree
      rr = rand() % ROWS;
      cc = rand() % COLS;
      }
    */
    while(!isNextToATree(dwarf,newr,newc)){
      while(dwarf.look(newr, newc-1) == APPLE_TREE || dwarf.look(newr, newc+1) == APPLE_TREE){
	newc+=1;
      }
      /*while(dwarf.look(newr+1, newc) == APPLE_TREE || dwarf.look(newr-1, newc) == APPLE_TREE) {
	newc+=1;
	}*/
      if (newr<=1 && (newc==MAX_COLS-1 || newc==1)){ //last row
	newr+=2;
	reverse=true;
      }
      else if(newc==MAX_COLS && reverse==false){
	newc=0;
	newr-=3;
      }
      else if(newc==0 && reverse==true){
	newc=MAX_COLS;
	newr+=3;
	//	reverse=false;
      }
      else if(reverse==false && newc<MAX_COLS){
	newc-=1;
      }
      else if(reverse==true && newc>0){
	newc+=1;
      }
    }

    if(isNextToATree(dwarf,newr,newc)){
      log << "Walk to " << newr << " " << newc << endl;
      dwarf.start_walk(newr, newc);
      return;
    }
  }
}
