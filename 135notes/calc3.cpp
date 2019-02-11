/*
Name: Emily Fang
Instructor: Mike Zamansky
*/

#include <iostream>

int main(){
  int num, total, squared; //num is an int class
  char sign; // + and - are of char class
  std::cin >> num >> sign; //the first number input is assigned to total
  if(sign =='^'){ //if minus sign
    total = num*num; //subtract
  }
  
  while (std::cin >> sign >> num) //takes in the two inputs
    {
      squared = num*num;
      if(sign =='+'){ //if plus sign
	total += num; //add
      }
      else if(sign =='-'){ //if minus sign
	total -= num; //subtract
      }
      else if(sign == '^'){
	total += num*num;
      }
      else if(sign == ';'){ //if semicolon
	std::cout << total << std::endl; //print total
	total = num; //reset to new first number after the semicolon
      }
    }
  std::cout << total << std::endl; //print the last line
  return 0;
}
