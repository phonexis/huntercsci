#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
  //establish the computers number
  srand(time(NULL));
  int answer = rand()%100;
  //int guess;
  /*
  std::cout << answer << "\n";
  answer = rand()%100;
  std::cout << answer << "\n";
  */
  //repeat until the answer is guess
  // get a guess from the user
  // see if the guess is too low/high/just right
  int guesses = 0;
  int guess = 50;
  int isCorrect;
  while(isCorrect == -1){
   //std::cout << answer << "\n";
  //std::cout << "Please enter a guess: ";
  //std::cin >> guess;
    if (isCorrect == -1){
      guess = guess + (100-guess)/2;
	//std::cout << "You guess too high";
    }
    else if (guess < answer){
      guess = guess-(guess/2);
	//std::cout << "You guessed too low";
    }
    std::cout << "I'm guessing: " << guess << "\n";
    std::cout << "0=right, -1=too low, 1=too high\n";
    std::cin >> isCorrect;
    //std::cout << "Please enter a guess: ";
    //std:: cin >> guess;
      guesses++;
      /*
In C++, there is a ++ before(pre increment) and ++ after(post increment) operands [same for --]
When used in a line but iteself: --i and i-- kind of like i = i-1
Example:
i = 0
if(++i) will work because will add 1 before checking
if (i++) will not work because will add 1 after checking      
there's i+=3 -> i = i+
-=
*=
/=
*/
  }

  std::cout << "Congratulations, you guess the number!!!\n";
  std::cout << "It took you " << guesses << " guesses!\n";
  return 0;
}
/*pseudorandom- appears to be random so it has an aspect of fairness

 */
