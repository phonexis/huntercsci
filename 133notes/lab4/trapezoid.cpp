#include <iostream>

std::string trapezoid(int width, int height){
  std::string box;
  int left = 0, right = width-1;
  if ((height*2)-1 > width){
    return "Impossible shape";
  }
  else {
    for (int rows=0;rows<height;rows++){
      if (rows == 0){
	for (int i = 0; i<width;i++){
	  box += "*";
	}
	box+= "\n";
      }
      else{
	for (int i = 0; i<width; i++){
	  if (i <= left){
	    box += " ";
	  }
	  else if (i >= right){
	    box += " ";
	  }
	  else {
	    box += "*";
	  }
	}
	box += "\n";
	left += 1;
	right -= 1;
      }
    }
  }
  return box;
}

int main(){
  int width, height;
  std::cout << "Input trapezoid width: " << std::endl;
  std::cin >> width;
  std::cout << "Input trapezoid height: " << std::endl;
  std::cin >> height;

  std::cout << trapezoid(width,height);
  return 0;
}
