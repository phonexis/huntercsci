/*
EMILY FANG
CSCI 235
PROJECT 3
*/
#include "Animal.hpp"
#include "List.hpp"


class ZooRecord:public List<Animal>{
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
  ZooRecord(std::string input_file_name);
  void display(); //displays all the Animal objects within the Array bag (calls the display function from Animal)
};

