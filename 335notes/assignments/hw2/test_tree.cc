// Emily Fang
// Main file for Part2(b) of Homework 2.

#include "avl_tree_p2b.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

namespace {
  //PERFORMS #4 & 5
  template <typename TreeType>
    void Sequences(const string &seq_filename, TreeType &a_tree) {
    int successes = 0;
    int recursion_calls = 0;
    
    ifstream myfile;
    myfile.open(seq_filename);
    string input;

    while(getline(myfile,input)) {
      SequenceMap new_sequence_map(input, ""); //instantiate new SequenceMap object
      if(a_tree.contains(new_sequence_map)) { //if already exists
	successes++; //successful find
	a_tree.find(new_sequence_map, recursion_calls); //dereferenced parameter to keep track of recursive calls
      }
    }
    cout << "4a: " << successes << endl;
    cout << "4b: " << (double)recursion_calls/(double)successes << endl; //average recursive calls

    //Closes file at the end
    myfile.close();

    //Resets variables to 0
    successes = 0;
    recursion_calls = 0;
    
    int index = 0;
    //Opens file again
    myfile.open(seq_filename);
    
    while(getline(myfile,input)) {
      SequenceMap new_sequence_map(input, ""); //instantiate new SequenceMap object
      if(index%2 == 0) { //for every other sequence
	if(a_tree.contains(new_sequence_map)) { //if already exists
	  successes ++; //successful remove
	}
	a_tree.remove(new_sequence_map, recursion_calls); //dereferenced parameter to keep track of recursive calls
      }
      index++;
    }
    cout << "5a: " << successes << endl;
    cout << "5b: " << (double)recursion_calls/(double)(index/2) << endl; //average recursive calls
  }


  //Reused from Q2 Part 2a
  template <typename TreeType>
  void BuildTree(const string&db_filename, TreeType &a_tree) {
    ifstream myfile;
    myfile.open(db_filename);
    string input;
    int i = 0;

    if(myfile.fail()) {
      std::cout << "Couldn't open the file!" << endl;
      return;
    }
    
    //Skips over the comments at the start of the database file
    while(i < 9) {
      getline(myfile,input);
      i += 1;
    }

    while(getline(myfile, input)) {
      stringstream s(input);
      string acronym;      
      getline(s,acronym,'/');

      string reco_seq;
      while (getline(s,reco_seq,'/')) {
	if(reco_seq != "") {
	  int calls = 0;
	  SequenceMap new_sequence_map(reco_seq, acronym);
	  if(a_tree.contains(new_sequence_map)) {
	    a_tree.find(new_sequence_map, calls)->Merge(new_sequence_map);
	  }
	  else a_tree.insert(new_sequence_map);
	}
      }
    }
  }
  
  // @db_filename: an input database filename.
  // @seq_filename: an input sequences filename.
  // @a_tree: an input tree of the type TreeType. It is assumed to be
  //  empty.
  template <typename TreeType>
  void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
    // Code for running Part2(b)

    BuildTree(db_filename, a_tree); //builds tree
    int nodes = a_tree.totalNodes(); //# of nodes
    //sum of the paths of all nodes from the root
    int path = a_tree.inPathLength(); //# of internal path lengths
    double average = (double)path/(double)nodes;
    
    cout << "2: " << nodes << endl;
    cout << "3a: " << average << endl;
    cout << "3b: " << average/ log2(nodes) << endl;

    //For #'s 4 & 5
    Sequences(seq_filename, a_tree);
    
    //Reset of variables Post-remove calls
    nodes = a_tree.totalNodes();
    path = a_tree.inPathLength();
    average = (double)path/(double)nodes;
    
    cout << "6a: " << nodes << endl;
    cout << "6b: " << average << endl;
    cout << "6c: " << average/ log2(nodes) << endl;
  }

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);

  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  cout << "Input files are " << db_filename << " and " << seq_filename << endl;
  cout << "Type of tree is AVL" << endl;
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
