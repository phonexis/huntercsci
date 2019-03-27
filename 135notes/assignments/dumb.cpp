#include <iostream>

/*void sort3(int&a,int&b,int&c){
  int temp1,temp2;
  if(b<a){
    if(a<c){
      temp1=a;
      a=b;
      b=temp1;
    }
    else if(a>c){
      if(b<c){
	temp1=a;
	temp2=b;
	a=temp2;
	temp2=c;
	b=temp2;
	c=temp1;
      }
      else if(b>c){
	temp1=a;
	a=c;
	c=temp1;	
      }
    }
  }
  else if(c<a){
    if(c<b){
      if(a<b){
	temp1=a;
	temp2=b;
	a=c;
	b=temp1;
	c=temp2;
      }
    }
  }
  else {
    if(c<b){
      temp1=b;
      temp2=c;
      b=temp2;
      c=temp1;
    }
  }
}
*/

void sort2(int& a, int& b)
{
    
  int temp;
  if(a>b){
    temp = a;
    a = b;
    b = temp;
  }
}
void sort3(int& d, int& e, int& f)
{
  sort2(d,e);
  sort2(d,f);
  sort2(e,f);
}

int main(){  
  int v = 4;  
  int w = 1;  
  int x = 3;    
  sort3(v, w, x); // w is now 1, x is now 4
  std::cout << v << " " << w << " " << x  << std::endl;
  return 0;
}
