#include <iostream>

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

bool isAlphanumeric(std::string s){
  if(s.length()==0){
    return true;
  }
  else if(isalpha(s) || isdigit(s)){
    return true;
  }
  return false;
}

int main(){
  //printRange(-2,10);
  //std::cout << sumRange(1,3) << " "; //<< sumRange(-2,10);
  /*int size = 10;
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

  delete[] arr;         // deallocate it */
  return 0;
}
