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

int add2(int a, int b);//declaration of fnction add2(which is below the add4 function calling add2)
//you also don't need a and b. all you need to know is the types(int) not the names

int add4(int a, int b,  int c , int d){
  int x = add2(a,b);
  int y = add2(c,d);
  return add2(x,y);
}


int add2(int a, int b){ //test with double
  int c;
  c = a + b;
  return c;
}

std::string times(std::string s, int t){
  std::string result = "";
  for (int i = 0; i<t; ++i){
    result = result +s;
  }
  return result;
}

void printGreeting(std::string name){
  std::cout << "Hello " << name << "\n";
  return;
  // a voidfunction doesn't reutnr anything but you can include a return but it send back a value 
}

int main(){
  int a = 10, b =20;
  int x = add2(a,b);
  std::cout << x << "\n";
  x = add2(100,500);
  std::cout << x << "\n";

  std::cout << add2(100.5,300) << "\n"; //special test cases returns 400 under int and 400.5 under double
  std::cout << times("Hello_",5) << "\n"; //prints hello out 5 times

  printGreeting("Stan");

  std::cout << add4(1,2,10,20) << "\n";
  
  return 0;
}
//(return type)-> ___  name(parameter,sts::string) {}
//main is the function that runs. echo $? is a special shell function that returns the function
//C++ has the ability to override opperators
//recursion is when a function runs itself
