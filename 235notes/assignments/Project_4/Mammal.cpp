#include "Mammal.hpp"
/*
Name: Emily Fang
CSCI 235
Project_2
*/

//Constructor functions
Mammal::Mammal(){
  hair_=false;
  airborne_=false;
  aquatic_=false;
  toothed_=false;
  fins_=false;
  tail_=false;
  legs_=0;
}
Mammal::Mammal(std::string name, bool domestic, bool predator){
  setName(name);
  if(isDomestic()!=domestic){//if domestic status!=desired parameter change
    setDomestic();//change it
    //otherwise, it stays the same
  }
  else if(isPredator()!=predator){//if predator status!=desired parameter change
    setPredator();//change it
    //otherwise, it stays the same
  }
  hair_=false;
  airborne_=false;
  aquatic_=false;
  toothed_=false;
  fins_=false;
  tail_=false;
  legs_=0;
}

//Functions that access private members
bool Mammal::hasHair() const{
  return hair_;
}
bool Mammal::isAirborne() const{
  return airborne_;
}
bool Mammal::isAquatic() const{
  return aquatic_;
}
bool Mammal::isToothed() const{
  return toothed_;
}
bool Mammal::hasFins() const{
  return fins_;
}
bool Mammal::hasTail() const{
  return tail_;
}
int Mammal::legs() const{
  return legs_;
}

//Mutator functions
void Mammal::setHair(){
  if(hair_==true){
    hair_=false;
  }
  else{
    hair_=true;
  }
}
void Mammal::setAirborne(){
  if(airborne_==true){
    airborne_=false;
  }
  else{
    airborne_=true;
  }
}
void Mammal::setAquatic(){
  if(aquatic_==true){
    aquatic_=false;
  }
  else{
    aquatic_=true;
  }
}
void Mammal::setToothed(){
  if(toothed_==true){
    toothed_=false;
  }
  else{
    toothed_=true;
  }
}
void Mammal::setFins(){
  if(fins_==true){
    fins_=false;
  }
  else{
    fins_=true;
  }
}
void Mammal::setTail(){
  if(tail_==true){
    tail_=false;
  }
  else{
    tail_=true;
  }
}
void Mammal::setLegs(int legs){
  legs_=legs;
}

void Mammal::display(){ // not displaying correctly
  std::cout << getName() << " is ";
  if(isDomestic()){
    std::cout << "domestic and ";
    if(isPredator()){
      std::cout << "it is a predator,\n";
      if(isAirborne()){
	std::cout << "it is airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
      else{
	std::cout << "it is not airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
    }
    else{
      std::cout << "is not a predator,\n";
      if(isAirborne()){
	std::cout << "it is airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
      else{
	std::cout << "it is not airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else{
    std::cout << "not domestic and ";
        if(isPredator()){
      std::cout << "it is a predator,\n";
      if(isAirborne()){
	std::cout << "it is airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
      else{
	std::cout << "it is not airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
    }
    else{
      std::cout << "is not a predator,\n";
      if(isAirborne()){
	std::cout << "it is airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
      else{
	std::cout << "it is not airborne and it is ";
	if(isAquatic()){
	  std::cout << "aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
	else{
	  std::cout << "not aquatic,\n";
	  if(hasHair()){
	    std::cout <<"it has hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	  else{
	    std::cout << "it has no hair, ";
	    if(isToothed()){
	      std::cout << "teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	    else{
	      std::cout << "no teeth, ";
	      if(hasFins()){
		std::cout << "fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	      else{
		std::cout << "no fins, ";
		if(hasTail()){
		  std::cout << "tail and " << legs() << " legs.\n\n";
		}
		else{
		  std::cout << "no tail and " << legs() << " legs.\n\n";
		}
	      }
	    }
	  }
	}
      }
    }
  }
}
