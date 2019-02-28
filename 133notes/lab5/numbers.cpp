#include <iostream>

bool isDivisible(int n, int d){
  if (n%d==0){
    return true;
  }
  else {
    return false;
  }
}

int main(){
  int a, b;
  std::cout << "First number: ";
  std::cin >> a;
  std::cout << "Second number: ";
  std::cin >> b;
  std::cout << isDivisible(a,b) << std::endl;
  return 0;
}
