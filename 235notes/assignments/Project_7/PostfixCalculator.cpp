#include "PostfixCalculator.hpp"
#include <fstream>

PostfixCalculator::PostfixCalculator(){
  //constructor here
}

bool PostfixCalculator::isOperator(char c){
  if( c == '*' || c == '-' || c == '+' || c == '/'){
    return true;
  }
  return false;
}

int PostfixCalculator::precedence(char c){
  if(c == '*' || c == '/'){
    return 5;
  }
  else if(c == '+' || c == '-'){
    return 6;
  }
  return 0;
}

bool PostfixCalculator::balanced(std::string s){
  int parenthesis=0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '('){
      parenthesis += 1;
    }
    if(s[i] == ')'){
      parenthesis -= 1;
    }
  }
  if(parenthesis != 0){
    return false;
  }
  return true;
}


std::string PostfixCalculator::convertToPostfix(std::string infix_expression){
  if(!balanced(infix_expression)){
    return "Precondition Violated Exception: Unbalanced parenthesis";
  }
  std::string postfix="";
  for(int i = 0; i < infix_expression.length(); i++){
    char c = infix_expression[i];
    //OPERAND
    if(isdigit(c)){
      if(!(i != 0 && isdigit(infix_expression[i-1]))){
	postfix += " ";
      }
      postfix += c;
    }
    if(c == '('){
      OperatorStack.push(c);
    }
    //OPERATORS
    if(isOperator(c)){
      while(!OperatorStack.empty() && OperatorStack.top() != '(' && precedence(c) <= precedence(OperatorStack.top())){
	postfix += " ";
	postfix += OperatorStack.top();
	OperatorStack.pop();
      }
      OperatorStack.push(c);
    }
    //CLOSE PARENTHESIS
    if(c == ')'){
      while(OperatorStack.top() != '('){
	postfix += " ";
	postfix += OperatorStack.top();
	OperatorStack.pop();
      }
      OperatorStack.pop();
    }
    if( i == infix_expression.length()-2 && !isOperator(c)){
      if(infix_expression.substr(infix_expression.length()-2, 2) == "\n"){
	//PRECONDVIOLATEDEXCEPTION HERE!!!!!!
	return "Precondition Violated Exception: Unknown operator";
      }
    }
  }
  

  while(!OperatorStack.empty()){
    postfix += " ";
    postfix += OperatorStack.top();
    OperatorStack.pop();
  }
  if(isspace(postfix[0])){
    postfix = postfix.substr(1, postfix.length() - 1);
    postfix += " ";
  }
  return postfix;
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression){
  double solution = 0.0;
  std::string num = "";
  double first, second = 0.0;
  for(int i = 0; i < postfix_expression.length(); i++){
    if(isdigit(postfix_expression[i])){
      //std::cout << "char: " << postfix_expression[i] << std::endl;
      num += postfix_expression[i];
      std::cout << num << std::endl;
      if(isspace(postfix_expression[i+1])){
	OperandStack.push(num);
	//std::cout << num << std::endl;
	num = "";
      }
    }
    if(isOperator(postfix_expression[i])){
      first = std::stoi(OperandStack.top());
      std::cout << "first: " << first << std::endl;
      OperandStack.pop();
      second = std::stoi(OperandStack.top());
      std::cout << "second: " << second << std::endl;
      OperandStack.pop();
      if(postfix_expression[i] == '+'){
	first += second;
	std::cout << "PLUS first: " << first << std::endl;
      }
      if(postfix_expression[i] == '-'){
	first -= second;
	std::cout << "MINUS first: " << first << std::endl;
      }
      if(postfix_expression[i] == '*'){
	first *= second;
	std::cout << "MULTIPLY first: " << first << std::endl;
      }
      if(postfix_expression[i] == '/'){
	first /= second;
	std::cout << "DIVIDE first: " << first << std::endl;
      }
      OperandStack.push(std::to_string(first));
    }
  }
  solution = std::stoi(OperandStack.top());
  OperandStack.pop();
  return solution;

}

void PostfixCalculator::testCalculator(std::string input_file_name){
  //std::cout << convertToPostfix("(2*3)+4");
  /*
  //writes into results text file
  out_file.open(input_file_name);
  ou_file << 0 << std::endl;

  out_file.close();*/
}
