#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"

int main(){
  
  LinkedList<int> test;
    
  for(int i=0;i<6;i++)
    {
      test.insert(i,(i));
    }
    
  for(int i=0;i<test.getLength();i++)
    {
      std::cout<<test.getEntry(i)<<",";
    }
  std::cout<<std::endl;
  /*test.invert();
  for(int i=0;i<test.getLength();i++)
    {
      std::cout<<test.getEntry(i)<<",";
    }
  */
  std::cout<<std::endl;

  
  test.rotate(2);
  for(int i=0;i<test.getLength();i++)
    {
      std::cout<<test.getEntry(i) << ",";
    }
    
  return 0;
}
