#include "PostfixCalculator.hpp"
#include <iostream>

int main(){
  PostfixCalculator a;
  //  std::cout << a.convertToPostfix("(10*3)+4");
  //std::cout << a.convertToPostfix("( 12 + 3 ) * ( 9 - 74 ) + 34 / ( ( 85 - 93 ) + ( 3 + 5 ) * 3 ) - 5") << std::endl;
  /*std::cout << a.convertToPostfix("( 15 - 4 ) / ( 100 - 70 ) - 34 + ( ( 105 - 93 ) - ( 6 + 4 ) / 2 ) - 15\n") << std::endl;
  std::cout << a.calculatePostfix("( 15 - 4 ) / ( 100 - 70 ) - 34 + ( ( 105 - 93 ) - ( 6 + 4 ) / 2 ) - 15\n") << std::endl;
  std::cout << a.convertToPostfix("( 85 - ( 93 + ( 32 + 15 ) ) + ( 3 + 5 ) * 3 ) + 5\n") << std::endl;
  std::cout << a.calculatePostfix("( 85 - ( 93 + ( 32 + 15 ) ) + ( 3 + 5 ) * 3 ) + 5\n") << std::endl;*/
  a.testCalculator("input.txt");
  //std::cout << a.calculatePostfix("12 3 + 9 74 - * 34 85 93 - 3 5 + 3 * + / + 5 - ");
  return 0;
}
