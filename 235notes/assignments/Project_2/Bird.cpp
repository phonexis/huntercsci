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
//TESTING STUB---------------------------------------------------------------
/*int main(){
  Bird eagle;
  //Bird eagle("bird",false,false);
  eagle.setName("Eagle");
  eagle.setDomestic();
  std::cout << eagle.getName() << " " << eagle.isDomestic() << std::endl;
  eagle.setDomestic();
  std::cout << eagle.isDomestic() << std::endl;
  return 0;
  }*/
