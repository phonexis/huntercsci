#include <iostream>
#include <cctype>

std::string removeLeadingSpaces(std::string line){
  bool found=true;
  std::string newline;
  for(int i=0;i<line.length();i++){
    if(isspace(line[i])){
      continue;
    }
    else {
      newline+=line[i];
    }
  }
  return newline;
}

int main(){
  std::cout << removeLeadingSpaces("       int x = 1;  ");
  return 0;
}
