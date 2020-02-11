/*EMILY FANG
csci 235 HW 1
Objective: Using a driver and recursive function, print out the permutations of a string separated by end lines.
The driver should be passed a string and should call the recursive function by passing the string, 0, and the string length.

The recursive function will backtrack when first/low index is equal to the string length-1 or high. After backtracking, each "copy" will be printed out post-swap.

*/


#include <iostream>
#include <string>
#include <algorithm>

#pragma once

//recursive function
void permute ( const std::string &str, int low, int high) { //call by const reference
  std::string copy = str; //make a copy
  if(low == high - 1) { //Base case: low index is equal to string length -1 or the last index of the string
    std::cout << copy << std::endl; //print the permutation
    return; //end the recursive call
  }
  for(int i = low; i < high; i++) { //iterate through from low to high
    std::swap(copy[low],copy[i]); //swap the index low with i

    permute(copy, low+1, high); //recursive call with incremented low
    
    std::swap(copy[low], copy[i]); //swap the index low with i 
  }
}

//@ should call the recursive permute functon to print out all permutations of a string
void permute ( const std::string &str){ //Driver function
  permute(str, 0, str.length()); //pass the string, low = 0, high = strign length
}

