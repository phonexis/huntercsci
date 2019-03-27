#include <iostream>
#include <cmath>

int main(){
  double initial,inrate, years, A;
  std::cout << "Initial Given Balance: ";
  std::cin >> initial;
  std::cout << "Interest rate compunded yearly: ";
  std::cin >> inrate;
  std::cout << "Years: ";
  std::cin >> years;

  A = initial*pow(1+inrate,years);
  std::cout << "$" << A << std::endl;
  return 0;
}
