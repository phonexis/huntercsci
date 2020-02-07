//EMILY FANG
#include <iostream>
#include <string>
#include <algorithm>

#pragma once

void permute ( const std::string &str, int low, int high) {
  std::string copy = str;
  if(low == high - 1) {
    std::cout << copy << std::endl;
    return;
  }
  for(int i = low; i < high; i++) {
    std::swap(copy[low],copy[i]);

    permute(copy, low+1, high);

    std::swap(copy[low], copy[i]);
  }
}

//@ should call the recursive permute functon to print out all permutations of a string
void permute ( const std::string &str){ //Driver function
  permute(str,0, str.length());
}

