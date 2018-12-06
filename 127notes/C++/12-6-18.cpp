#include <iostream>

#include <cstdlib>
#include <ctime>

int main(){
  int x = 1; 
  //int i; //declaration for while loop
  for (int i = 1; i<5; i++) {
    x = x * i;
    //factorial
  }
  
  int i = 1;
  while (i<5){
    //you can put a declaration into a for loop but not a while loop
    //the declaration needs to be outsude the while loop
    x = x*i;
    i++;
  }
  std::cout << x << "\n";

  int r;
  for (r = rand()%100; r!=20; r = rand()%100){
    std::cout << r << " ";
  }
  std::cout << r << "\n";
  return 0;
}


//There are different versions of C++ just as there is python3
/*
print "hello" vs print("Hello")
-std=c++14
*/

