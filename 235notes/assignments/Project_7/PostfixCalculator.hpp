#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "PrecondViolatedExcep.hpp"

class PostfixCalculator{
public:
  //CONSTRUCTOR
  PostfixCalculator();

  //HELPER FUNCTIONS
  int precedence(char c); //checks precedence
  bool isOperator(char c); //checks if operator

  //MEMBER FUNCTIONS
  /*
    Takes a string representation of the infix expression, parses it into the
    corresponding postfix expression and returns the postfix expression as a string. */
  std::string convertToPostfix(std::string infix_expression);

  
  /*
    takes a string representation of the postfix expression, calculates the result and returns it. It assumes that the postfix expression is well formed
  */
  double calculatePostfix(std::string postfix_expression);

  
  /*
    Read every infix expression from the input file and:
    • Convert it to postfix (don’t forget to do this in a try-catch block,
    convertToPostfix may throw an exception!)
    • Write the corresponding postfix expression into postfix.txt, but if
    convertToPostfix throws and exception, write the error message
    instead
    • Evaluate the postfix expression if wellformed and write the result in
    results.txt, otherwise write the error message there too 
  */
  void testCalculator(std::string input_file_name);
  
private:
  //STACK FOR POSTFIX CONVERSION
  std::stack<char> OperatorStack;

  //STACK FOR CALCULATING POSTFIX
  std::stack<std::string> OperandStack;  
};

