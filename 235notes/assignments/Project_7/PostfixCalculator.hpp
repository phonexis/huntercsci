#pragma once
#include <iostream>
#include <stack>
#include <string>

class PostfixCalculator{
public:
  //CONSTRUCTOR
  PostfixCalculator();

  //HELPER FUNCTIONS
  int precedence(char c);
  bool isOperator(char c);
  bool balanced(std::string s);

  //MEMBER FUNCTIONS
  std::string convertToPostfix(std::string infix_expression);
  double calculatePostfix(std::string postfix_expression);
  void testCalculator(std::string input_file_name);
  
private:
  std::stack<char> OperatorStack;
  std::stack<std::string> OperandStack;  
};

