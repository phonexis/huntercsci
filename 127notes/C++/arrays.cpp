#include <iostream>
int main(){
  int a;
  int b[4];
  int c;

  a = 20;
  for(i = 0; i<4;++i){
    b[i]=10*i;
  }

  for(i = 0;i<4;++i){
    std::cout << b[i] << " ";
  }
  return 0;
}
// b[i] isn'treferring to the i th index. it's referring to i bytes away
//we can treat an array as a list
//vector is a much more like a python list. inside of it is an array. it internally move things around. when something is taken from the middle, everything is moved up
