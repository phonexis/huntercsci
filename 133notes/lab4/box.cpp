#include <iostream>

std::string box(int width, int height){
  std::string row, box;
  for(int i = 0;i < width;i++){
    row += "*";
  }
  for(int i = 0;i < height;i++){
    box = box + row + "\n";
  }
  return box;
}

int main(){
  int width, height;
  std::cout << "Input width: ";
  std::cin >> width;
  std::cout << "Input height: ";
  std::cin >> height;

  std::cout << "Shape: \n" << box(width,height) << std::endl;
  
  return 0;
}
