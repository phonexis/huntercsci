#include <iostream>

std::string middle(std::string s){
  if(s.length()%2==0){
    return s.substr((s.length()-1)/2,2);
  }
  else{
    return s.substr(s.length()/2,1);
  }
}

int main(){
  std::cout << middle("cat") << std::endl;
  std::cout << middle("fish") << std::endl;
  return 0;
}
