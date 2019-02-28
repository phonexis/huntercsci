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

int nextPrime(int n){
  int num = n;
  while(isPrime(num+1)==0){
    num+=1;
  }
  return num+1;
}

//TASK D
int countPrimes(int a, int b){
  int counter=0;
  for(a;a<=b;a++){
    if(isPrime(a)==0){
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
    else if(left==1 && right==1){
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
  int num = n;
  while(isTwinPrime(num+1)==0){
    num+=1;
  }
  return num+1;
}

//TASK G
int largestTwinPrime(int a, int b){
  int largest;
  for(a;a<=b;a++){
    if(isPrime(a)==1){
      largest=a;
    }
  }
  return largest;
}

int main(){
  std::cout << isDivisible(6,2) << std::endl;
  std::cout << isPrime(5) << std::endl;
  std::cout << isPrime(49) << std::endl;
  std::cout << nextPrime(17) << std::endl;
  std::cout << countPrimes(1,10) << std::endl;
  std::cout << isTwinPrime(6) << std::endl;
  std::cout << nextTwinPrime(38) << std::endl;
  std::cout << largestTwinPrime(1,10) << std::endl;

  return 0;
}
