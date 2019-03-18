#include <iostream>

int main(){
  int side;
  bool flip=true;
  std::cout << "Enter side length: ";
  std::cin >> side;
  if(side>0){
    for(int row=0;row<side;row++){
      for(int i=0;i<side;i++){
	if(flip==true){
	  std::cout << "o";
	}
	else{
	  std::cout << "x";
	}
      }
      if(flip==true){
	std::cout<<"\n";
	flip=false;
      }
      else{
	std::cout<<"\n";
	flip=true;
      }
    }
  }
  else{
  std::cout << "Enter side length: ";
  std::cin >> side;
  }    
  return 0;
}
