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
  int counter=0;
  for(int i=0;i<line.length();i++){
    char thing=line[i];
    if((int)thing==(int)c){
      counter+=1;
    }
  }
  return counter;
}


std::string indent(std::string line){
  std::string indented;
  static int tab=0;
  int open = countChar(line,'{');
  int close = countChar(line,'}');

  if(line[0]=='}' && open==1){
    tab-=1;
  }
  else if(close >= 1 && close>open){
    tab-=(close-open);
  }
  for(int i=0;i<tab;i++){
    indented+="\t";
  }
  if(line[0]=='}' && open==1){
    tab+=1;
  }
  else if(open>=1 && open>close){
    tab+=(open-close);
  }
  indented+=line;
  return indented;
}

//std::cout << countChar(lines,'}');

int main(){
  std::string lines;
  std::string indented;
  while(getline(std::cin,lines)){
    std::cout << indent(removeLeadingSpaces(lines)) << std::endl;
  }
  return 0;
}
