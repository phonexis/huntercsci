#include <iostream>

//TASK A
bool isDivisible(int n, int d){
  if (n%d==0){
    return true;
  }
  else {
    return false;
  }
}

//TASK B
bool isPrime(int n){
  int count=0;
  for(int i=2;i<n;i++){
    if(count==1){
      return false;
    }
    else if(n%i==0){
      count+=1;
    }
  }
  return true;
}

//TASK C
/*
int nextPrime(int n){
  int next = n+1;
  if(isPrime(next)==0){
    next+=1;
  }
  else {
    return next;
  }
}
*/

//TASK D
int countPrimes(int a, int b){

}

//TASK E
bool isTwinPrime(int n){

}

int main(){
  std::cout << isDivisible(6,2) << std::endl;
  std::cout << isPrime(5) << std::endl;
  std::cout << isPrime(49) << std::endl;
  //  std::cout << nextPrime(14) << std::endl;
  return 0;
}
