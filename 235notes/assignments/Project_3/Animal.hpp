/*Emily Fang
CSCI 235
Project 1
*/

#include <iostream>

class Animal{
private: //contains data hidden from users
  std::string name_;
  bool domestic_;
  bool predator_;
public: //contains functions accessible to users
  //constructors
  Animal();
  Animal(std::string name, bool domestic=false, bool predator=false);
  //const is a safety precaution such that accidental chanegs are avoided
  //accessors
  std::string getName() const;
  bool isDomestic() const; //domestic status
  bool isPredator() const; //predator status
  //mutators
  void setName(std::string name); //changes the name
  void setDomestic(); //changes domestic_
  void setPredator(); //changes predator_
  void display(); //displays the name and domestic and predator status
  friend bool operator==(const Animal& animalobj, const Animal& animalobj1); //overloads the == operator to compare two Animal objects to test if they are the samex
};
