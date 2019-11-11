#include "SortingComparison.hpp"

int main(){
  SortingComparison test10 = SortingComparison(100);
  std::cout << "INCREASING -----------------------------" << std::endl;
  test10.runComparison(INCREASING);
  std::cout << "DECREASING -----------------------------" << std::endl;
  test10.runComparison(DECREASING);
  std::cout << "RANDOM -----------------------------" << std::endl;
  test10.runComparison(RANDOM);

  return 0;
}
