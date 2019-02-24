#include <iostream>

std::string columns(int width){
  bool alt = true;
  std::string row1, row2;
  int count=0;
  for (int col=0; col < width; col++){
    if (count < 3){
      if (alt == true) {
	box += "*";
	count += 1;
      }
      else {
	box += " ";
	count += 1;
      }
    }
    else if (count >= 3) {
      if (alt == false){
	count = 1;
	box += "*";
	alt = true;
      }
      else {
	count = 1;
	box += " ";
	alt = false;
      }
    }
  }
  box += "\n";
}


std::string checker3x3(int width,int height){
  bool alt = true;
  bool 
  std::string box;
  int count;
  for (int row=0; row<height; row++){
    count = 0;
    for (int col=0; col < width; col++){
      if (count < 3){
	if (alt == true) {
	  box += "*";
	  count += 1;
	}
	else {
	  box += " ";
	  count += 1;
	}
      }
      else if (count >= 3) {
	if (alt == false){
	  count = 1;
	  box += "*";
	  alt = true;
	}
	else {
	  count = 1;
	  box += " ";
	  alt = false;
	}
      }
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

  std::cout << "Shape: \n" << checker3x3(width,height) << std::endl;
  return 0;
}
