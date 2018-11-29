#include <iostream>
#include <cstdlib>

/*Ask the user to input an integer between0 and 99 inclusive
Use a while loop to guess the user's answer and then adjust up or down until it guesses correctly.
For each guess, the cmputer will print the guess and ask the user if the number is higher(1), 
lower(-1), or correct(0)*/

int main(){
  int i;
  int guess;
  int eval;
  
  std::cout << "Please enter a number from 0-99";
  std::cout >> i;
  
  std::cout << (rand()%100) << std::endl;
  std::cout >>guess
    
  std::cout << "Higher? = 1 Lower? = -1 COrrect? = 0";
  std::cout >> eval;
 
  while (eval != 0){
    if (eval == 1){
      guess = guess + 1;
      }
    else if (eval == -1){
      guess = guess -1;
      }
    std::cout << "Higher? = 1 Lower? = -1 Correct = 0";
    std::cout >> eval;
  }
  return 0;
}
