/*`
Emily Fang
12/1/19
CSCI 235
Modifications: generateShortestWord and generateLengthWord functions
inclusion of the regex library
*/

#include "CodewordGenerator.hpp" //header file with CodewordGenerator class

#include <regex> //library string regex functions

std::string CodewordGenerator::generateShortestWord(std::string pattern)
{
  char alpha [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //capital alphabet

  std::queue<std::string> permutations; // BFS queue
  permutations.push(""); //first string that complies with the regex expression
  //from left to right
  while(!permutations.empty()){ //still permutations in queue
    std::string front = permutations.front(); //current string
    permutations.pop(); //removes next element
    
    if(std::regex_match(front, std::regex(pattern))){ //if pattern is found
      return front; //returns the shortest string matching the pattern
    }
    
    else{ //otherwise
      for(int i = 0; i < 27; i++){ //for all capital letters in the alphabet
	permutations.push(front + alpha[i]); //append the letter and enqueue it
	//enqueue - inserts a new element at the rear of the queue
      }
    }
  }
  return " "; //if there is no pattern, then return nothing
}

std::string CodewordGenerator::generateLengthWord(std::string pattern, int length)
{
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //capital alphabet

  std::stack<std::string> permutations; //stack is used specifically for DFS
  //DFS is more memory efficient in this case
  permutations.push("");

  while(!permutations.empty()){
    std::string front = permutations.top(); //current string
    permutations.pop();
    if(front.size() != length){ //while not the desired length
      for(int i = 0; i < 27; i++){ //for all capital alphabet letters
	permutations.push(front + alpha[i]); //append to the current string and push
      }
    }
    else if(std::regex_match(front, std::regex(pattern))){ //if pattern found
      return front; //returns the string of desired length
    }
  }
  return " "; //if there is no pattern, then return nothing
}
