#include <iostream>

std::string lower(int length){
  int count = 1;
  std::string triangle;
  while (count < length+1){
    for (int i = 0; i<count;i++){
      triangle += "*";
    }
    triangle += "\n";
    count += 1;
  }
  return triangle;
}

int main(){
  int length;
  std::cout << "Input side length: ";
  std::cin >> length;

  std::cout << "Shape: \n" << lower(length);
  return 0;
}
