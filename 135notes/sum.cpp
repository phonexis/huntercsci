#include <iostream>
// include iostream

int main(){
  int s;
  //initialize inputs as int
  int sum = 0;
  //initialize sum and set equal to 0
  //used to keep track of the sum
  while (std::cin >> s){
    //while s is being inputted
    sum = sum + s;
    //sum reassigned
  }
  std::cout << sum;
  //print sum
  return 0;
}
