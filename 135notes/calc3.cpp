#include <iostream>

using namespace std;

int main() {
  int num, squared;
  char sign;
  bool truthval = true;
  int total;
  
  std::cin >> total;

  while(std::cin >> sign)
    {
      if(sign = '^') {
	squared = num*num;
	if (truthval == true){
	  total -= num;
	  total += squared;
	}
	else {
	  total +=num;
	  total -= squared;
	}
      }
      else if (sign == '+')
        {
	  truthval = true; // positive
	  std::cin >> num;
	  total = total + num;
        }
      else if(sign == '-')
        {
	  truthval = false; // negative
	  std::cin >> num;
	  total -= num;
        }
      else if(sign == ';')
	{
	  std::cout << total << endl;
	  std::cin >> num; //first number in each line 
	  total = num;
	  truthval = true;
        }
    }
  return 0;   
}
