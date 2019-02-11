#include <iostream>

int ray(int i, int V){
  int myData[10];
  for(int i=0; i < 10; i++){
    myData[i] = 1;
  }
  std::cout << myData << std::endl;
  if(i>=0 || i<=10){
    myData[i] = V;
  }
  for(int i=0; i < 10; i++){
    std::cout << myData[i] << " ";
  }
}

int main(){
  int i;
  int V;
  std::cout << "Input index: ";
  std::cin >> i;
  std::cout << "Input value: ";
  std::cin >> V;

  if (ray(i,V) == 0){
    std::cout << "Index out of range. Exit" << std::endl;
  }
  else {
  std::cout << ray(i,V) << std::endl;
  }
  return 0;
}
