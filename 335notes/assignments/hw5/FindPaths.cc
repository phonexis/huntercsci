#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "graph.h"

using namespace std;

int pathfindDriver(int argc, char **argv) {
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
  
  int starting_vertex = std::stoi(argv[2]);
  graph.dijkstra(starting_vertex);

  for(auto it = graph.begin(); it != graph.end(); ++it) {
    Vertex * v = graph.table_vertex(it->first);
    std::cout << it->first << ": ";
    if(graph.possible(starting_vertex,v)) {
      graph.printPath(v);
      std::cout << " cost: " << graph.cost(it->first);
      std::cout << "\n";
    } else {
      std::cout << "not_possible" << std::endl;
    }
  } 
  return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }

    pathfindDriver(argc, argv);

    return 0;
}
