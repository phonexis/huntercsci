#include <iostream>
#include <string>

std::string cross(int size){
  std::string box;
  int left = 0, right = size-1;
  for (int row = 0; row < size/2; row++){
    for (int i=0;i<size;i++){ //in each column
      if (i == left){
	box += "*";
      }
      else if (i == right){
	box += "*";
      }
      else {
	box += " ";
      }
    }
    box += "\n";
    left += 1;
    right -= 1;
  }
  for (int row = 0; row < size/2; row++){
    left -= 1;
    right += 1;
    for (int i=0;i<size;i++){ //in each column
      if (i == left){
	box += "*";
      }
      else if (i == right){
	box += "*";
      }
      else {
	box += " ";
      }
    }
    box += "\n";
  }
  return box;  
}

int main(){
  int size;
  std::cout << "Input size: ";
  std::cin >> size;

  std::cout << cross(size);
  return 0;
}
