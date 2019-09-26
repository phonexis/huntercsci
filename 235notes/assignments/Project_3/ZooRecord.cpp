/*
EMILY FANG
CSCI 235
PROJECT 3
*/
#include "ZooRecord.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

ZooRecord::ZooRecord(){
  item_count_=0; //by default, there are 0 items
  //ArrayBag();
}

ZooRecord::ZooRecord(std::string input_file_name){
  std::string input,junk; //the name of the lines being taken in by getline()
  
  std::ifstream fin(input_file_name.c_str()); //streams the file with the name fin
  if(fin.fail()){ //in the case that the file doesn't open properly
    std::cerr << "File cannot be opened for reading" << std::endl;
    exit(1);
  }
  
  getline(fin,junk); //take the first row, which are the column titles
  while(getline(fin,input)){ //for each row
    std::stringstream strstream(input); //read each line as a stringstream called strstream
    std::string str_name,dom,pre; //the columns that have these stored values to take

    //FOR THE ANIMAL OBJECT CONSTRUCTION
    std::string name; //stores animal name
    bool domestic=false; //stores domestic status
    bool predator=false; //stores predator status

    //NAME LINES
    getline(strstream, str_name,','); //takes the delimiter ',' to show the animal name
    name=str_name; //animal name is stored

    //JUNK LINES
    for(int i=0;i<6;i++){
      getline(strstream,junk,',');
    }

    //PREDATOR LINES
    getline(strstream,pre,',');
    if(pre=="1"){
      predator=true;
    }
    /*    if(pre=="0"){
      predator=false;
      }*/

    //JUNK LINES
    for(int i=0;i<7;i++){
      getline(strstream,junk,',');
    }

    //DOMESTIC LINES
    getline(strstream,dom,',');
    if(dom=="1"){
      domestic=true;
    }
    /*if(dom=="0"){
      domestic=false;
      }*/

    //FINAL JUNK LINES
    getline(strstream, junk, ',');

    //CREATE THE ANIMAL OBJECT TO BE ADDED TO THE ARRAYBAG
    Animal object(name,domestic,predator);
    add(object);
  }
  fin.close(); //close the stream
}

void ZooRecord::display(){ 
  for(int i=0;i<item_count_;i++){ //for items in the record
    items_[i].display(); //display each Animal object using the display function from the Animal class
  }
}
