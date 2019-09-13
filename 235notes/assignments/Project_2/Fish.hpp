#pragma once
#include <iostream>
#include "Animal.hpp"
/*
Name: Emily Fang
CSCI 235
Project_2
*/

class Fish: public Animal{ //inherits public members for Animal class
public:
  //Constructors
  Fish();
  Fish(std::string name, bool domestic = false, bool predator = false);
  //Accessors
  bool isVenomous() const;
  //Mutators
  void setVenomous();
private: //private members
  bool venomous_;
};
