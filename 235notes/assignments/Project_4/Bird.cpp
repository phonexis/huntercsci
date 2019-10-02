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
void Bird::display(){
  std::cout << getName() << " is ";
  if(isDomestic()){
    std::cout << "domestic and ";
    if(isPredator()){
      std::cout << "it is a predator,\n";
      if(isAirborne()){
	std::cout << "it is airborne and ";
	if(isAquatic()){
	  std::cout << "it is aquatic,\n\n";
	}
	std::cout << "it is not aquatic,\n\n";
      }
      std::cout << "it is not airborne and ";
    }
    std::cout << "is not a predator,\n";
  }
  else {
    std::cout << "not domestic and ";
    if(isPredator()){
      std::cout << "it is a predator,\n";
      if(isAirborne()){
	std::cout << "it is airborne and ";
	if(isAquatic()){
	  std::cout << "it is aquatic,\n\n";
	}
	std::cout << "it is not aquatic,\n\n";
      }
      std::cout << "it is not airborne and ";
    }
    std::cout << "is not a predator,\n";
  }
}
