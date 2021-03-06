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
    else{
      newline+=line[i];
    }
  }
  return newline;
}

int countChar(std::string line, char c){
  int opened=0;
  int closed=0;
  for(int i=0;i<line.length();i++){
    char c=line[i];
    if((int)c==123){
      opened+=1;
    }
    else if((int)c==125){
      opened-=1;
    }
  }
}

int main(){
  std::cout << "       int x = 1;  " << std::endl;
  std::cout << removeLeadingSpaces("       int x = 1;  ");
  return 0;
}
