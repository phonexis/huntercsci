#include <iostream>

std::string interval(int L, int U){
  std::string s;
  for(int i = L; i < U ; i++){
    s = s +std::to_string(i) + " ";
  }
  return s;
}

int main(){
  int L;
  int U;
  std::cout << "Please enter L: ";
  std::cin >> L;
  std::cout << "Please enter U: ";
  std::cin >> U;

  std::cout << interval(L,U) << std::endl;
  return 0;
}
