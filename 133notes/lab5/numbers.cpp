#include <iostream>

//TASK A
bool isDivisibleBy(int n, int d){
  if (d==0){
    return false;
      }
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
  if(n<=1){
    return false;
  }
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

int nextPrime(int n){
  int num = n;
  int pos =2;
  if (n>0){
    while(isPrime(num+1)==0){
      num+=1;
    }
    return num+1;
  }
  else {
    return 2;
  }
}

//TASK D
int countPrimes(int a, int b){
  int counter=0;
  int start;
  if(a<0 || b<0){
    start = 0;
  }
  else {
    start=a;
  }
  for(start;start<=b;start++){
    if(isPrime(start)==1){
      counter+=1;
    }
    else{}
  }
  return counter;
}

//TASK E
bool isTwinPrime(int n){
  bool left=isPrime(n-2);
  bool right=isPrime(n+2);
  if(isPrime(n)==1){
    if(left==1 || right==1){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

//TASK F
int nextTwinPrime(int n){
  int num = n+1;
  while(isTwinPrime(num+1)==0){
    num+=1;
  }
  return num;
}

//TASK G
int largestTwinPrime(int a, int b){
  int largest=0;
  for(b;b>a;b--){
    if(isTwinPrime(b)==1){
      largest=b;
      return largest;
    }
  }
  if (largest==0){
    largest=-1;
  }
  return largest;
}

int main(){
  std::cout << isDivisibleBy(6,2) << std::endl;
  std::cout << isPrime(1) << std::endl;
  std::cout << isPrime(49) << std::endl;
  std::cout << nextPrime(-17) << std::endl;
  std::cout << countPrimes(1,20) << std::endl;
  std::cout << isTwinPrime(6) << std::endl;
  std::cout << nextTwinPrime(38) << std::endl;
  std::cout << largestTwinPrime(0,72) << std::endl;

  return 0;
}
