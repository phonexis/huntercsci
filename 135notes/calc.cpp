/*
Name: Emily Fang
Instructor: Mike Zamansky
*/

#include <iostream>

int main(){
  int num; //num is an int class
  char sign; // + and - are of char class
  int total; //total starts at 0

  std::cin >> total; //the first number input is assigned to total
  
  while (std::cin >> sign >> num) //takes in the two inputs
    {
      if(sign =='+'){ //if plus sign
	total += num; //add
      }
      else if(sign =='-'){ //if minus sign
	total -= num; //subtract
      }
      else if(sign == ';'){ //if semicolon
	std::cout << total << std::endl; //print total
	total = num; //reset to new first number after the semicolon
      }
    }
  std::cout << total << std::endl; //print the last line
  return 0;
}
