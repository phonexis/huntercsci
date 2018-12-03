#include <iostream>

int main() {
  int response;
  int num;
  int lower = 0;
  int upper = 99;
  int guess = (lower + upper) / 2;
  std::cout << "Input a Number 0-99: ";
  std::cin >> num;

  std::cout << "Is " << guess << " the number? Respond with -1, 0, or 1. ";
  std::cin >> response;
  
  while (response != 0) {
    if (response == 1) {
      upper = guess;
    }
    else {
      lower = guess;
    }
    guess = (lower + upper)/2;

    std::cout << "Is " << guess << " the number? Respond with -1, 0, or 1. ";
    std::cin >> response;
  }
  std::cout << "I got it!" << std::endl;
  return 0;
}
