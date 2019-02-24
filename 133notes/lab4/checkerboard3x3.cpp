#include <iostream>

std::string build1(int width){
  std::string placehold;
  bool alt = true;
  int count = 0;
  for (int col=0; col < width; col++){
    if (count < 3){
      if (alt == true) {
	placehold += "*";
	count += 1;
      }
      else {
	placehold += " ";
	count += 1;
      }
    }
    else if (count >= 3) {
      if (alt == false){
	count = 1;
	placehold += "*";
	alt = true;
      }
      else {
	count = 1;
	placehold += " ";
	alt = false;
      }
    }
  }
  return placehold;
}

std::string build2(int width){
  std::string placehold;
  bool alt = false;
  int count = 0;
  for (int col=0; col < width; col++){
    if (count < 3){
      if (alt == true) {
	placehold += "*";
	count += 1;
      }
      else {
	placehold += " ";
	count += 1;
      }
    }
    else if (count >= 3) {
      if (alt == false){
	count = 1;
	placehold += "*";
	alt = true;
      }
      else {
	count = 1;
	placehold += " ";
	alt = false;
      }
    }
  }
  return placehold;
}

std::string checker3x3(int width,int height){
  bool alt = true;
  std::string box;
  std::string one = build1(width);
  std::string two = build2(width);
  int count = 0;
  for (int row=0; row<height; row++){
    if (alt == true && count <3){
      box += one;
      box += "\n";
      count += 1;
    }
    else if (alt == false && count <3){
      box += two;
      box += "\n";
      count += 1;
    }
    else {
      if (alt ==true){
	count = 1;
	box += two;
	box += "\n";
	alt = false;
      }
      else {
	count = 1;
	box += one;
	box += "\n";
	alt = true;
      }
    }
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
