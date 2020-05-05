#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {
  //GRAPH BUILDING
  ifstream graph_file;
  graph_file.open(argv[1]);
  
  if(graph_file.fail()) {
    std::cout << "Couldn't open the file!" << endl;
    return 0;
  }
  
  Graph graph;
  int vertices;
  string input;
  getline(graph_file,input);
  vertices = std::stoi(input);
  while(getline(graph_file,input)) {
    //std::cout << input << std::endl;
    stringstream sstream(input);
    string line, index; //stringstream input
    int vertex; //also used for conencted vertexes
    double weight; //connected vertex weight
    bool v = true;
    
    getline(sstream, index, ' '); //vertex | NOT THE CONNECTED VERTEX
    graph.insert(std::stoi(index));
    while(getline(sstream,line,' ')) {
      // std::cout << line << std::endl;
      if(v) { //if connected vertex
	vertex = std::stoi(line);
	v = false;
      } else { // if connected vertex weight
	weight = std::stod(line);
	//make vertex and weight pair to insert
	std::pair<int,double> vw_pair(vertex,weight);
	graph.insert(std::stoi(index), vw_pair);
	v = true;
      }
    }
  }

  graph_file.close();
  /*
  for(auto it = graph.begin(); it != graph.end(); ++it) {
    std::cout << it->first << ": ";
    for(auto item: it->second) {
      std::cout << "{" << item.first << ": " << item.second << "}, ";
    }
    std::cout << "\n";
    }*/

  //QUERIES
  ifstream query_file;
  query_file.open(argv[2]);

  if(query_file.fail()) {
    std::cout << "Couldn't open the file!" << endl;
    return 0;
  }
  
  while(getline(query_file,input)) {
    //std::cout << input << std::endl;
    stringstream sstream(input);
    string vertex, query; //stringstream input
   
    while(sstream >> vertex >> query) {
      //std::cout << vertex << " " << query << std::endl;
      if(graph.find(std::stoi(vertex),std::stoi(query))) {
	double weight = graph.weight(std::stoi(vertex), std::stoi(query));
	std::cout << vertex << " " << query << ": connected " << weight << std::endl;
      } else {
	std::cout << vertex << " " << query << ": not_connected " << std::endl;
      }
    }
  }
  return 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
