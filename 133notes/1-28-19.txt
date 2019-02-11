#include <iostream>

/*
using namespace std; 
this imports everything from standard into namespace
by doing this you run the risk of creating a conflict with a function you write with something in std
 you ever want to include a full name space

it's better to do:
using std::abs;
such that you are specifically specifying what under std you are using rather than importing everything under std. 
*/

int add2(int a, int b){
  int result = a+b;
  return result;
}
std::string add2(std::string a, std::string b){
  //overloading a fucntion
  return a+b;
}

int main ()
{
  //you must declare the class beforehand for variables
  int a, i;
  a = 0;
  std::string s = "good morning";
  //0==false & 1==true in boolean
  std::cout << "hello\n" << a << " " << s << std::endl;
  //std::endl; ends onto the next line
  
  i = 14;
  std::cout << "global var:" << i << std::endl;
  
  for (int i=0; i<10; ++i){
    std::cout << i << std::endl;
  }  

  if (i>20){
    //do something
  }
  else if (i>10){
    //do something
  }
  else {
    //do something
  }
  // && instead of logical and
  // || instead of logical or
  // ! instead of logical not
  std::cout << add2("hi","dude") << std::endl;
  std::cout << add2(2,3) << std::endl;
  return 0;
  //any variable declaration exists within the curly brackets
}

/*
g++ -o name file or g++ file (this one will need ./a.out to run)
g++ -c = turns the file into an object file
g++ -Wall file (warnings all)
*/

