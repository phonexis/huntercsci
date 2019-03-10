#include <iostream>

std::string upper(int length){
  int count = 1;
  int rows = length;
  std::string triangle;
  while (count < length+1){
    for (int i = 0; i < count;i++){
      triangle += " ";
    }
    for (int i = 0; i < rows;i++){
      triangle += "*";
    }
    triangle += "\n";
    count += 1;
    rows -= 1;
  }
  return triangle;
}

int main(){
  int length;
  std::cout << "Input side length: ";
  std::cin >> length;

  std::cout << "Shape: \n" << upper(length);
  return 0;
}
