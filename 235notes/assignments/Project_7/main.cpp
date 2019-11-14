#include "PostfixCalculator.hpp"
#include <iostream>

int main(){
  PostfixCalculator a;
  //  std::cout << a.convertToPostfix("(10*3)+4");
  std::cout << a.convertToPostfix("( 12 + 3 ) * ( 9 – 74 ) + 34 / ( ( 85 – 93 ) + ( 3 + 5 ) * 3 ) - 5");
  return 0;
}
