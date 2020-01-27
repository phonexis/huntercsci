#include "PostfixCalculator.hpp"
#include <fstream>

PostfixCalculator::PostfixCalculator(){
  //constructor here
}

//CHECKS IF CHAR IS AN OPERATOR: -, +, /, *
bool PostfixCalculator::isOperator(char c){
  if( c == '*' || c == '-' || c == '+' || c == '/'){
    return true;
  }
  return false;
}

//CHECKS FOR PRECEDENCE based on the precedence table
int PostfixCalculator::precedence(char c){
  if(c == '*' || c == '/'){
    return 5; //higher precedence
  }
  else if(c == '+' || c == '-'){
    return 6; //lower precendence
  }
  return 0;
}

std::string PostfixCalculator::convertToPostfix(std::string infix_expression){
  std::string postfix="";
  for(int i = 0; i < infix_expression.length(); i++){
    char c = infix_expression[i];

    //UNKNOWN OPERATOR THROW
    if(!isOperator(c) && !isdigit(c) && !isspace(c) && c != '(' && c !=')'){
      throw (PrecondViolatedExcep("Unknown operator"));
    }
    
    //OPERAND
    else if(isdigit(c)){
      
      if(!(i != 0 && isdigit(infix_expression[i-1]))){
	postfix += " "; //!(if not the first and the next char is a number)
      }
      
      postfix += c; //Append all numbers 
    }
    
    //OPEN PARENTHESIS
    else if(c == '('){
      OperatorStack.push(c); //Append all open parenthesis 
    }
    
    //OPERATORS
    else if(isOperator(c)){ // if -, +, /, *
      
      while(!OperatorStack.empty() && OperatorStack.top() != '(' && precedence(c) >= precedence(OperatorStack.top())){
	postfix += " ";
	postfix += OperatorStack.top();
	OperatorStack.pop();
      }
      
      OperatorStack.push(c);
      
    }
    
    //CLOSE PARENTHESIS
    else if(c == ')'){
      
      if(OperatorStack.empty()){ // if no '(' to match then unbalanced
	throw (PrecondViolatedExcep("Unbalanced parenthesis"));
      }
      
      while(OperatorStack.top() != '('){ //if there is '(' then they have been matched
	postfix += " ";
	postfix += OperatorStack.top();
	OperatorStack.pop();
	
	if(OperatorStack.empty()){ // if no '(' to match then unbalanced
	  throw (PrecondViolatedExcep("Unbalanced parenthesis"));
	}
	
      }
      
      OperatorStack.pop();
    }
  }
  
  while(!OperatorStack.empty()){
    
    if(OperatorStack.top() == '('){ //if there is extra '(' tehn unbalanced
      throw (PrecondViolatedExcep("Unbalanced parenthesis"));
    }

    //add everything else with spaces in between
    postfix += " ";
    postfix += OperatorStack.top();
    OperatorStack.pop(); //removes items as well
    
  }
  
  if(isspace(postfix[0])){ //in case the postfix has whitespace at the start
    postfix = postfix.substr(1, postfix.length() - 1);
    postfix += " ";
  }
  
  return postfix;
  
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression){
  double solution, A, B = 0.0;
  std::string num = "";
  
  for(int i = 0; i < postfix_expression.length(); i++){
    
    if(isOperator(postfix_expression[i])){ //if  an operator
      A = std::stod(OperandStack.top()); //first item
      OperandStack.pop();
      B = std::stod(OperandStack.top()); //second item
      OperandStack.pop();
      
      if(postfix_expression[i] == '+'){ //ADD
	solution = B + A;
	OperandStack.push(std::to_string(solution));
      }
      
      else if(postfix_expression[i] == '-'){ //SUBTRACT
	solution = B - A;
	OperandStack.push(std::to_string(solution));
      }
      
      else if(postfix_expression[i] == '*'){ //MULTIPLY
	solution = B * A;
	OperandStack.push(std::to_string(solution));
      }
      
      else if(postfix_expression[i] == '/'){ //DIVIDE
	solution = B / A;
	OperandStack.push(std::to_string(solution));
      }

      //AT THE END, APPEND EACH SOLUTION
    }
    
    else if(isdigit(postfix_expression[i])){ //NUMBERS
      num += postfix_expression[i]; //collect digits for the full number

      if(!isdigit(postfix_expression[i+1])){
	OperandStack.push(num); //APPEND NUMBER TO STACK
	num = "";
      }
      
    }
  }
  solution = std::stod(OperandStack.top()); //SOLUTION POPPED FROM THE TOP
  OperandStack.pop();
  return solution;
}

void PostfixCalculator::testCalculator(std::string input_file_name){
  std::string s; //INPUT STRINGS
  std::string postfix_expression; //POSTFIX CONVERTED STRING

  //READS FILE
  std::ifstream infix;
  infix.open(input_file_name.c_str());

  //POSTFIX FILE - TO BE WRITTEN
  std::ofstream postfix("postfix.txt");
  //RESULTS FILE - TO BE WRITTEN
  std::ofstream results("results.txt");

  //IF CAN'T OPEN THE INFIX FILE
  if (infix.fail()){
    std::cerr << "Error opening file. Exiting." << std::endl;
    exit(1);
  }
  
  while(getline(infix,s)){ //READ LINES OF FILE

    //IN CASE THE STACKS HAVE RESIDUAL DATA
    while(!OperatorStack.empty()){
      OperatorStack.pop();
    }
    
    while(!OperandStack.empty()){
      OperandStack.pop();
    }

    
    //TRY TO WRITE INTO FILE
    try {
      postfix_expression = convertToPostfix(s);
      postfix << postfix_expression << "\n";
      results << calculatePostfix(postfix_expression) << "\n";
    }

    //CATCH EXCEPTIONS
    catch (PrecondViolatedExcep& e) {
      //WRITES THE EXCEPTION INTO THE FILE
      postfix << e.what() << "\n";
      results << e.what() << "\n";
    }
    
  }

  //CLOSE FILES
  postfix.close();
  results.close();

}
