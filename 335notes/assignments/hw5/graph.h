#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include <iostream>
#include <unordered_map>
#include <vector>
//#include "binary_heap.h"

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outsode those statements

class Graph {
 public:
  auto begin() {
    return graph.begin();
  }

  auto end() {
    return graph.end();
  }

  bool insert(int vertex) {
    auto index = graph.find(vertex);
    if(index == graph.end()) {
      std::vector<std::pair<int,double>> v;
      graph.insert(std::make_pair(vertex,v));
      return true;
    } else {
      return false;
    }
  }
  
  bool insert(int vertex, std::pair<int,double> p) {
    auto index = graph.find(vertex);
    if(index == graph.end()) { //DOES NOT EXIST ON GRAPH YET
      std::vector<std::pair<int,double>> v;
      v.push_back(p);
      graph.insert(std::make_pair(vertex, v));
    } else { //EXISTS ON GRAPH
      graph[vertex].push_back(p);
    }
    return true;
  }

  bool find(int vertex, int query_vertex) {
    auto index = graph.find(vertex);
    if(index != graph.end()) {
      for(auto x: graph[vertex]) {
	if(x.first == query_vertex) {
	  return true;
	}
      }
      return false;
    } else {
      return false;
    }
  }

  double weight(int vertex, int query_vertex) {
    auto index = graph.find(vertex);
    if(index != graph.end()) {
      for(auto x: graph[vertex]) {
	if(x.first == query_vertex) {
	  return x.second;
	}
      }
      return -1;
    } else {
      return -1;
    }
  }
  
 private:
  std::unordered_map<int,std::vector<std::pair<int,double>>> graph;
};



#endif
