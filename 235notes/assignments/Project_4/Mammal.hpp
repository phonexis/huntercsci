#pragma once
#include <iostream>
#include "Animal.hpp"
/*
Name: Emily Fang
CSCI 235
Project_2
*/
class Mammal: public Animal{ //inherits public members of Animal class
public:
  //Constructors
  Mammal();
  Mammal(std::string name, bool domestic = false, bool predator = false);
  //Accessors
  bool hasHair() const;
  bool isAirborne() const;
  bool isAquatic() const;
  bool isToothed() const;
  bool hasFins() const;
  bool hasTail() const;
  int legs() const;
  //Mutators
  void setHair();
  void setAirborne();
  void setAquatic();
  void setToothed();
  void setFins();
  void setTail();
  void setLegs(int legs);
  virtual void display() const override; //overrides base class's function
  //virtual b/c the base class was pure virtual
private: //private members
  bool hair_;
  bool airborne_;
  bool aquatic_;
  bool toothed_;
  bool fins_;
  bool tail_;
  int legs_;
};
