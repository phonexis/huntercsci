#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <limits>
#include "binary_heap.h"

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outsode those statements
struct Vertex {
  int vertex;
  std::vector<std::pair<int,double>> adjacent_vertices;
  bool known = false;
  double distance;
  Vertex * path;

  inline bool operator<(const Vertex& rhs) {
    return distance < rhs.distance;
  }
};

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
      //std::vector<string> row = {"F","INF", "-1"};
      graph.insert(std::make_pair(vertex,v));
      //table.insert(std::make_pair(vertex,row));
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

  double cost(int vertex) {
    return table[vertex].distance;
  }

  Vertex * table_vertex(int vertex) {
    return & table[vertex];
  }

  void printTable() {
    for(auto it = table.begin(); it != table.end(); ++it) {
      std::cout << it->second.vertex;
      for(auto item: it->second.adjacent_vertices) {
	std::cout << " {" << item.first << ", " << item.second << "}";
      }
      std::cout << " " << it->second.known << " " << it->second.distance;
      std::cout << "\n";
    }
  }

  void printPath( Vertex* v ) {
    if(v->path != nullptr) {
      printPath(v->path);
      cout << " ";
    }
    std::cout << v->vertex;
  }

  void dijkstra(int starting_vertex) {
    for(auto it = graph.begin(); it != graph.end(); ++it) {
      int index = it->first;
      double d = std::numeric_limits<double>::infinity();
      Vertex v = {index, it->second , false , d, nullptr };
      table.insert(std::make_pair(index,v));
    }

    BinaryHeap<Vertex*> priority_queue;
    table[starting_vertex].distance = 0;
    Vertex * start = & table[starting_vertex];
    priority_queue.insert(start);
    
    while(!priority_queue.isEmpty()) {
      Vertex* v = priority_queue.findMin();
      std::cout << "\n" << v->vertex << std::endl;
      v->known = true;
      priority_queue.deleteMin();
      
      std::cout << "Adjacency" << std::endl;
      for(auto w: v->adjacent_vertices) {
	std::cout << w.first << std::endl;
	if(table[w.first].known == false) {
	  double path_cost = w.second;
	  if(v->distance + path_cost < table[w.first].distance) {
	    //UPDATE W
	    Vertex * w_pointer = & table[w.first];
	    priority_queue.insert(w_pointer);
	    w_pointer->distance = v->distance + path_cost;
	    w_pointer->path = v;
	  }
	}
      }
      
    }
    
    
  }
  
 private:
  std::map<int,std::vector<std::pair<int,double>>> graph;
  std::map<int,Vertex> table;
};



#endif
