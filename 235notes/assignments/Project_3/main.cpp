#include <iostream>
#include "ZooRecord.hpp"

int main(){
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
  return 0;
}
