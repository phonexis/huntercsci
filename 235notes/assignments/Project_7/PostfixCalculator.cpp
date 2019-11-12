#include "PostfixCalculator.hpp"
#include <fstream>

PostfixCalculator::PostfixCalculator(){
  //constructor here
}

std::string PostfixCalculator::PostfixCalculator(std::string infix_expression){
  for(int i = 0; i < infix_expression; i++){
    char c = infix_expression[i];
    switch (c){
    case operand:
      break;
    case '(':
      break;
    case operator:
      break;
    case ')':
      break;
    }
  }
  while(!PostfixStack.isEmpty()){

  }
}

double PostfixCalculator::calculatorPostfix(std::string postfix_expression){

}

void PostfixCalculator::testCalculator(std::string input_file_name){


  //writes into results text file
  out_file.open(input_file_name);
  ou_file << 0 << std::endl;

  out_file.close();
}
