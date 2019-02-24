#include <iostream>
#include <string>

std::string cross(int size){
  std::string box;
  int left = 0, right = size-1;
  for (int row = 0; row < size; row++){
    for (int i=0;i<size;i++){ //in each column
      if (i == left || i== right){
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
  return box;
}

int main(){
  int size;
  std::cout << "Input size: " << std::endl;
  std::cin >> size;

  std::cout << cross(size);
  return 0;
}
