/*
Emily Fang
CSCI 235
Project 3
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

void Animal::display(){
  //displays an Animal as a statement
  if(isDomestic()==true && isPredator()==true){
    std::cout << getName() << " is domestic and it is a predator" << std::endl;
  }
  if(isDomestic()==false && isPredator()==false){
    std::cout << getName() << " is not domestic and is not a predator" << std::endl;
  }
  if(isDomestic()==true && isPredator()==false){
    std::cout << getName() << " is domestic and is not a predator" << std::endl;
  }
  if(isDomestic()==false && isPredator()==true){
    std::cout << getName() << " is not domestic and it is a predator" << std::endl;
  }

}

bool operator==(const Animal& animalobj, const Animal& animalobj1){
  //if exactly the same
  if(animalobj.getName()==animalobj1.getName() && animalobj.isDomestic()==animalobj1.isDomestic() && animalobj.isPredator()==animalobj1.isPredator()){
    return true; //return true
  }
  return false;
}
/*
int main(){
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
  beaver.display();
  return 0;
  }*/
