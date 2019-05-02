#include <iostream>
#include <vector>

std::vector<int>makeVector(int n){
  std::vector<int> newv(n);
  for(int i=0;i<n;i++){
    newv[i]=i;
  }
  return newv;
}

int main(){
  std::vector<int> vect=makeVector(20);
  for(int i=0;i<vect.size();i++){
    std::cout << vect[i] << " ";
  }
  return 0;
}
