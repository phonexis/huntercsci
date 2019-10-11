//#include "Fish.hpp"
//#include "Mammal.hpp"
//#include "Bird.hpp"
#include "ZooRecord.hpp"
int main(){
  /* FISH DISPLAY TESTING: PASSED
  Fish salmon("salmon", true, true);
  salmon.setVenomous();
  salmon.display();
  */
  /*MAMMAL DISPLAY TESTING: PASSED
  Mammal sloth("sloth",false,true);
  sloth.display();
  */
  /*BIRD DISPLAY TESTING:PASSED
  Bird crane("crane", false, true);
  crane.display();
  */
  /* ArrayBag<int> first_array;
  ArrayBag<int> second_array;
  first_array.add(3);
  second_array.add(5);
  first_array.add(4);
  second_array.add(3);
  first_array.display();
  first_array-=second_array;
  first_array.display();
  second_array.display();
  */
  ZooRecord first("zoo.csv");
  first.display();
  std::cout << first.remove(0) << "===========================================";
  first.display();
  first.clear();
  std::cout << "cleared";
  first.display();
  return 0;
}
