/*
Emily Fang
12/1/19
CSCI 235 - Project 8: Uses BFS and DFS
Modifications: CodewordGenerator class
inclusion of string and queue
*/

#pragma once

#include <iostream>
#include <string>
#include <queue>

class CodewordGenerator{
public: //public members

  CodewordGenerator() = default;
  /*
    takes a string pattern and returns the shortest string that matches the pattern  (searching using BFS - Breadth First Search or first in first out.)
    The input string pattern is guaranteed to represent a valid regular expression pattern. 
  */
  //BFS definition: one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue
  std::string generateShortestWord (std::string pattern);

  /*
    takes a string pattern and an integer n and returns a string of length n that matches (searching using DFS - Depth First Search)
    Here too, the input string pattern is guaranteed to represent a valid regular expression pattern. 
  */
  //DFS definition: first visited vertices are pushed into stack and second if there is no vertices then visited vertices are popped
  std::string generateLengthWord (std::string pattern,int length);

private:
  //no private members needed
};
