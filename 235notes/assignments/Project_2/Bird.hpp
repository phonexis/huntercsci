#pragma once
#include <iostream>
#include "Animal.hpp"
/*
Name: Emily Fang
CSCI 235
Project_2
*/

class Bird: public Animal{ //inherits public members of Animal class
public:
  //Constructors
  Bird();
  Bird(std::string name, bool domestic = false, bool predator = false);
  //Accessors
  bool isAirborne() const;
  bool isAquatic() const;
  //Mutators
  void setAirborne();
  void setAquatic();
private: //private members
  bool airborne_;
  bool aquatic_;
};
