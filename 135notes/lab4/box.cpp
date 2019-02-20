#include <iostream>

int main(){
  int x = 0;
  int width, height;
  std::string row;
  
  std::cout << "Input width: ";
  std::cin >> width;
  std::cout << "Input height: ";
  std::cin >> height;

  for(int i=0; i<width; i++){
    row += "*";
  }
  while (x < height){
    std::cout << row << std::endl;
    x += 1;
  }
  
  return 0;
}
