/*
Emily Fang
CSCI 235
Project 1
*/
#include <iostream>
#include "Animal.hpp" //header file inclusion

Animal::Animal(){ //constructor
  name_="";
  domestic_=false;
  predator_=false;
}

Animal::Animal(std::string name, bool domestic, bool predator){
  //takes parameters to set private variables
  name_=name;
  domestic_=domestic;
  predator_=predator;
}

//Functions to return private members (accessors)
std::string Animal::getName() const{ //returns name
  return name_;
}

bool Animal::isDomestic() const{ //returns domestic status
  return domestic_;
}

bool Animal::isPredator() const{ //returns predator status
  return predator_;
}

//Functions to change private member data (mutators)
void Animal::setName(std::string name){
  name_=name;
}

void Animal::setDomestic(){ //switches the domestic status to true
  if(domestic_==false){
    domestic_=true;
  }
  else{
    domestic_=false;
  }
}

void Animal::setPredator(){ //switches the predator status to false
  if(predator_==false){
    predator_=true;
  }
  else{
    predator_=false;
  }
}

/*int main(){
  //Test
  Animal beaver;
  std::cout << beaver.getName() << " " << beaver.isDomestic() << " " << beaver.isPredator() << std::endl;
  beaver.setName("Johnny");
  beaver.setDomestic();
  beaver.setPredator();
  std::cout << beaver.getName() << " " << beaver.isDomestic() << " " << beaver.isPredator() << " With the Name changes" << std::endl;
  beaver.setDomestic();
  beaver.setPredator();
  std::cout << beaver.getName() << " " << beaver.isDomestic() << " " << beaver.isPredator() << " Check the status changing functions" << std::endl;
  
  return 0;
}
*/
