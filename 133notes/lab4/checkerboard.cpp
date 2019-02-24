#include <iostream>

std::string checker(int width,int height){
  bool alt = true;
  std::string box;

  for (int row=0; row<height; row++){
    for (int col=0; col < width; col++){
      if (alt == true){
	box += "*";
	alt = false;
      }
      else {
	box += " ";
	alt = true;
      }
    }
    if (row%2 ==1){
      alt = true;
    }
    else {
      alt = false;
    }
    box += "\n";
  }
  return box;
}

int main(){
  int width, height;
  std::cout << "Input width: ";
  std::cin >> width;
  std::cout << "Input height: ";
  std::cin >> height;

  std::cout << "Shape: \n" << checker(width,height) << std::endl;
  return 0;
}
