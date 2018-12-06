/*
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
print "hello" vs print("Hello")
-std=c++14
you dont need {} for one lie for and while loops
*/

#include <iostream>

int add2(int a, int b){
  int c;
  c = a + b;
  return c;
}

int main(){
  int a = 10, b =20;
  int x = add2(a,b);
  std::cout << x << "\n";
  x = add2(100,500);
  std::cout << x << "\n";
  return 0;
}
//(return type)-> ___  name(parameter,sts::string) {}
//main is the function that runs. echo $? is a special shell function that returns the function
