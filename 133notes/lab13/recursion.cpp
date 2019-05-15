#include <iostream>
#include <cctype>

void printRange(int left, int right){
  if(right>=left){
    std::cout << left << " ";
    printRange(left+1,right);
  }
  else{
    std::cout << "\n";
  }
}


int sumRange(int left, int right){
  int sum=0;
  if(right>=left){
    sum=left+sumRange(left+1,right);
  }
  return sum;    
}

int sumArrayInRange(int *arr, int left, int right){
  int sum=0;
  if(right>=left){
    sum=arr[left]+sumArrayInRange(arr,left+1,right);
  }
  return sum;
}

int sumArray(int *arr, int size){
  int sum = 0;
  int index = 0;
  sum=arr[index]+sumArrayInRange(arr, index+1, size-1);
  return sum;
}

//PART D
bool isAlphanumeric(std::string s){
  if(s.length()==0){
    return true;
  }
  else if(!isalnum(s[0])){
    //std::cout << s << std::endl;
    return false;
  }
  return isAlphanumeric(s.substr(1,s.length()-1));
}


bool isparens(char c){
  if(c==40 || c==41){
    return true;
  }
  return false;
}

bool nestedParens(std::string s){
  if(s.length()==0){
    return true;
  }
  else if(isparens(s[0]) && isparens(s[s.length()-1])){
    if(s[0]==40 && s[s.length()-1]==41){
      return nestedParens(s.substr(1,s.length()-2));
    }
    return false;
  }
  return false;
}


int main(){
  printRange(-2,10);
  std::cout << sumRange(1,3) << " "; //<< sumRange(-2,10);
  int size = 10;
  int *arr = new int[size]; // allocate array dynamically
  arr[0] = 12;
  arr[1] = 17;
  arr[2] = -5;
  arr[3] = 3;
  arr[4] = 7;
  arr[5] = -15;
  arr[6] = 27;
  arr[7] = 5;
  arr[8] = 13;
  arr[9] = -21;

  int sum1 = sumArray(arr, size); // Add all elements
  std::cout << "Sum is " << sum1 << std::endl;  // Sum is 43
    
  int sum2 = sumArray(arr, 5); // Add up first five elements
  std::cout << "Sum is " << sum2 << std::endl;  // Sum is 34

  delete[] arr;         // deallocate it 
  std::cout << isAlphanumeric("ABCD") << std::endl;        // true (1)
  std::cout << isAlphanumeric("Abcd1234xyz") << std::endl; // true (1)
  std::cout << isAlphanumeric("KLMN 8-7-6") << std::endl;  // false (0)
  std::cout << nestedParens("((()))") << std::endl;      // true (1)
  std::cout << nestedParens("()") << std::endl;          // true (1)
  std::cout << nestedParens("") << std::endl;            // true (1)

  std::cout << nestedParens("(((") << std::endl;         // false (0)
  std::cout << nestedParens("(()") << std::endl;         // false (0)
  std::cout << nestedParens(")(") << std::endl;          // false (0)
  std::cout << nestedParens("a(b)c") << std::endl;       // false (0)

  return 0;
}
