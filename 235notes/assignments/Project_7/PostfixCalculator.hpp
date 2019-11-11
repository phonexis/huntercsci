#pragma once
#include <iostream>
#include <stack>
#include <string>

class PostfixCalculator{
public:
  PostfixCalculator();
  std::string convertToPostfix(std::string infix_expression);
  double calculatorPostfix(std::string postfix_expression);
  void testCalculator(std::string input_file_name);
private:
  std::stack<std::string> PostfixStack;
  std::tack<std::string> OperatorStack;
};

