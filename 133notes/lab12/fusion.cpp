#include <iostream>
#include <vector>

void gogeta(std::vector<int> &goku, std::vector<int> &vegeta){
  for(int i=0;i<vegeta.size();i++){
    goku.push_back(vegeta[i]);
  }
  vegeta.clear();
}

int main(){
  std::vector<int> v1{1,2,3};
  std::vector<int> v2{4,5};
  gogeta(v1,v2);
  for(int i=0;i<v1.size();i++){
    std::cout << v1[i] << " ";
  }
  std::cout << "\n";
  for(int i=0;i<v2.size();i++){
    std::cout << v2[i] << " ";
  }
  return 0;
}
