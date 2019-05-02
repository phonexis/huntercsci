#include <iostream>
#include <vector>

std::vector<int> goodVibes(std::vector<int> v){
  std::vector<int> good;
  for(int i=0;i<v.size();i++){
    if(v[i]>=0){
      good.push_back(v[i]);
    }
  }
  return good;
}

int main(){
  std::vector<int> v{1,2,-1,3,4,-1,6};
  std::vector<int> answer=goodVibes(v);
  for(int i=0;i<answer.size();i++){
    std::cout << answer[i] << " ";
  }
  return 0;
}
