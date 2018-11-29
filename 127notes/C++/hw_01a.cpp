#include <iostream>

/*Ask the user to input an integer between0 and 99 inclusive
Use a while loop to guess the user's answer and then adjust up or down until it guesses correctly.
For each guess, the cmputer will print the guess and ask the user if the number is higher(1), 
lower(-1), or correct(0)*/

int main() {
  int input;
  int smol = 0;
  int big = 99;
  int eval;
  int guess;
  
  std::cout << "Please enter a number from 0-99. ";
  std::cin >> input;
  std::cout << "Higher? = 1 Lower? = -1 Correct? = 0: ";
  std::cin >> eval;
 
  while (eval != 0){
    guess = (big+smol) / 2;
    if (eval == 1){
      big = guess;
    }
    else {
      smol = guess;
    }
    std::cout << "New guess=" << guess << std::endl;
    std::cout << "Higher? = 1 Lower? = -1 Correct = 0: ";
    std::cin >> eval;
  }
  std::cout << "CONGRATS!" << guess << std::endl;
  return 0;
}
