#include <iostream>

void printRange(int left, int right){
  if(right>=left){
    std::cout << left << " ";
    printRange(left+1,right);
  }
  else{
    std::cout << "\n";
  }
}


int sumRange(int left, int right){
  int sum=0;
  if(right>=left){
    sum+=left;
    sumRange(left+1,right);
  }
  return sum;
}

int sumArray(int *arr, int size){
  return 0;
}

int main(){
  printRange(-2,10);
  std::cout << sumRange(1,3) << " " << sumRange(-2,10);
  return 0;
}
