#include <iostream>

int main(){
  int a,b,c;
  while(std::cin >> a >> b >> c){
    if (a<b && a<c){
      if (b>a && b<c) {
	std::cout << "increasing" << std::endl;
      }
      else {
	std::cout << "neither" << std::endl;
      }
    }
    else if (a>b && a>c){
      if (b<a && b>c){
	std::cout << "decreasing" << std::endl;
      }
      else {
	std::cout << "neither" << std::endl;
      }
    }
    else {
      std::cout << "neither" << std::endl;
    }
  }

  return 0;
}
