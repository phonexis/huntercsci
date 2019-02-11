#include <iostream>
#include <fstream>
using namespace std;

int main(){
  std::string s = "Hello, World!";
  std::fstream in_file;
  
  ofstream out_file;
  out_file.open("hello.txt");
  out_file << s << std::endl;
  return 0;
}
