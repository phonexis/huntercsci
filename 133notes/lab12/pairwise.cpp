#include <iostream>
#include <vector>

std::vector<int> sumPairWise(std::vector<int> &v1,std::vector<int> &v2){
  while(v1.size()>v2.size()){
    v2.push_back(0);
  }
  while(v2.size()>v1.size()){
    v1.push_back(0);
  }
  std::vector<int> newv;
  for(int i=0;i<v1.size();i++){
    newv.push_back(v1[i]+v2[i]);
  }
  return newv;
}

int main(){
  std::vector<int> v1{1,2,3};
  std::vector<int> v2{4,5};
  std::vector<int> answer=sumPairWise(v1,v2);
  for(int i=0;i<answer.size();i++){
    std::cout << answer[i] << " ";
  }
  return 0;
}
