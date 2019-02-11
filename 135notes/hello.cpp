#include <iostream>
#include <fstream>

int main() 
{
  std::string inputStr;
  std::string outputStr;
  std::fstream currentFile;

  currentFile.open("hello.txt");
  currentFile<<"Hello, World!";
  currentFile.close();

  currentFile.open("hello.txt");
  for(int i=0;i<2;i++)
    {
      currentFile>>inputStr;
      if(i%2==0)
	  outputStr+=inputStr+" ";
      else
	outputStr+=inputStr;
    }
   std::cout<<outputStr;
   currentFile.close();

  return 0;
}
