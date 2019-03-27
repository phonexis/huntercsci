#include <iostream>
#include <cctype>

std::string removeLeadingSpaces(std::string line){
  std::string newline;
  bool cleaned=false;
  for(int i=0;i<line.length();i++){
    char c=line[i];
    if(isspace(c) && cleaned==false){
      continue;
    }
    else if(!isspace(c)){
      cleaned=true;
      newline+=line[i];
    }
    else if(cleaned==true){
      newline+=line[i];
    }
  }
  newline+="\n";
  return newline;
}

int countChar(std::string line, char c){
  int counter=0;
  for(int i=0;i<line.length();i++){
    char thing=line[i];
    if((int)thing==int(c)){
      counter+=1;
    }
  }
  return counter;
}

int main(){
  std::string lines;
  while(getline(std::cin,lines)){
    std::cout << removeLeadingSpaces(lines);
  }
  return 0;
}
