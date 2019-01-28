#include <iostream>

/*using namespace std; 
this imports everything from standard into namespace
by doing this you run the risk of creating a conflict with a function you write with something in std
 you ever want to include a full name space

it's better to do:
using std::abs;
such that you are specifically specifying what under std you are using rather than importing everything under std. */

int main ()
{
  //you must declare the class beforehand for variables
  int a = 20;
  std::string s = "good morning";
  //0==false & 1==true in boolean
  std::cout << "hello\n" << a << "\n" << s << std::endl;
  //std::endl; ends onto the next line
  return 0;
}

//g++ -o name file or g++ file (this one will need ./a.out to run)
//g++ -c = turns the file into an object file
