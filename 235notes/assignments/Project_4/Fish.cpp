#include "Fish.hpp"
/*
Name: Emily Fang
CSCI 235
Project_2
*/

//Constructor fucntions
Fish::Fish(){
  venomous_=false;
}
Fish::Fish(std::string name, bool domestic, bool predator){
  setName(name); 
  if(isDomestic()!=domestic){//if domestic status != parameter of desired change
    setDomestic(); //change it
    //otherwise, no chnages are made
  }
  else if(isPredator()!=predator){//if predator status != parameter of desired change
    setPredator(); //change it
    //otherwise, no changes are made
  }
  venomous_=false;
}

//Functions that return private members
bool Fish::isVenomous() const{
  return venomous_;
}

//Mutator functions
void Fish::setVenomous(){
  if(venomous_==true){
    venomous_=false;
  }
  else{
    venomous_=true;
  }
}

void Fish::display(){
  std::cout << getName() << " is ";
  if(isDomestic()){
    std::cout << "domestic, ";
    if(isPredator()){
      std::cout << "it is a predator\n";
      if(isVenomous()){
	std::cout << "and it is venomous.\n\n";
      }
      else{
	std::cout << "and it is not venomous.\n\n";
      }
    }
    else{
	std::cout << "it is not a predator\n";
	if(isVenomous()){
	  std::cout << "and it is venomous.\n\n";
	}
	else{
	  std::cout << "and it is not venomous.\n\n";
	}      
      }
  }
  else{
    std::cout << "not domestic, ";
    if(isPredator()){
      std::cout << "it is a predator\n";
      if(isVenomous()){
	std::cout << "and it is venomous.\n\n";
      }
      else{
	std::cout << "and it is not venomous.\n\n";
      }
    }
    else{
	std::cout << "it is not a predator\n";
	if(isVenomous()){
	  std::cout << "and it is venomous.\n\n";
	}
	else{
	  std::cout << "and it is not venomous.\n\n";
	}      
    }
  }
}
