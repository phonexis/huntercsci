/*
EMILY FANG
CSCI 235
PROJECT 3
*/
#include <iostream>
#include "Animal.hpp"
#include "List.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"

class ZooRecord:public List<Animal*>{ //Animal pointers [be aware of the * placement]
public:
  ZooRecord(); //default constuctor
  /**parameterized constructor
 @pre the input file is expected to be in CSV
 (comma separated value) format as:
 "animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,
 backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
 @param input_file_name the name of the input file
 @post adds Animal objects to record as per the data in the input file
 **/
  ZooRecord(std::string input_file_name); //parameterized constructor

  ~ZooRecord();

  void clear() override; //override causes an error b/c it's already overriding

  bool remove(size_t position) override; //override causes an error b/c it's already overriding
  
  void display(); //displays all the Animal pointers to derived objects within List
};

