#include "Bird.hpp"
/*
Name: Emily Fang
CSCI 235
Project_2
*/

//Constructor functions
Bird::Bird(){ 
  airborne_=false;
  aquatic_=false;
}
Bird::Bird(std::string name, bool domestic, bool predator){
  setName(name); 
  if(isDomestic()!=domestic){ //if the domestic status does not match parameter
    setDomestic(); //change it to the opposite
    //otherwise, no changes are made
  }
  else if(isPredator()!=predator){ //if predator status does not match parameter
    setPredator(); //change it
    //otherwise no changes are made
  }
  airborne_=false;
  aquatic_=false;
}

//Functions that return private members
bool Bird::isAirborne() const{
  return airborne_;
}
bool Bird::isAquatic() const{
  return aquatic_;
}

//Mutator functions
void Bird::setAirborne(){
  if(airborne_==true){
    airborne_=false;
  }
  else{
    airborne_=true;
  }
}
void Bird::setAquatic(){
  if(aquatic_==true){
    aquatic_=false;
  }
  else{
    aquatic_=true;
  }
}
void Bird::display() const{
  //NEGATIVE LANGUAGE
  std::string dom=" is not domestic";
  std::string pre="is not a predator";
  std::string air="it is not airborne";
  std::string aqua="it is not aquatic";

  //CHANGES FROM NEGATIVE TO POSITIVE
  if(isDomestic()){
    dom=" is domestic";
  }
  if(isPredator()){
    pre="it is a predator";
  }
  if(isAirborne()){
    air="it is airborne";
  }
  if(isAquatic()){
    aqua="it is aquatic";
  }

  //PRINT STATEMENTS
  std::cout << getName() << dom << " and " << pre << ",\n";
  std::cout << air << " and " << aqua << ".\n\n";
}
