// <Your name>
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
  template <typename TreeType>
    void Sequences(const string &seq_filename, TreeType &a_tree) {
    // Code for running Part2(b)
    int successes = 0;
    int recursion_calls = 0;
    ifstream myfile;
    myfile.open(seq_filename);
    string input;

    while(getline(myfile,input)) {
      SequenceMap new_sequence_map(input, "");
      if(a_tree.contains(new_sequence_map)) {
	successes++;
	a_tree.find(new_sequence_map, recursion_calls);
      }
    }
    cout << "4a: " << successes << endl;
    cout << "4b: " << (double)recursion_calls/(double)successes << endl;

    myfile.close();
    successes = 0;
    recursion_calls = 0;
    int index = 0;
    myfile.open(seq_filename);
    while(getline(myfile,input)) {
      SequenceMap new_sequence_map(input, "");
      if(index%2 == 0) {
	if(a_tree.contains(new_sequence_map)) {
	  successes ++;
	}
	//recursion_calls++;
	a_tree.remove(new_sequence_map, recursion_calls);
      }
      index++;
    }
    cout << "5a: " << successes << endl;
    // cout << "5b: " << recursion_calls << endl;
    cout << "5b: " << (double)recursion_calls/(double)(index/2) << endl;
  }

  
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
    BuildTree(db_filename, a_tree);
    int nodes = a_tree.inPathLength();
    int path = a_tree.totalNodes();
    double average = (double)nodes/(double)path;
    cout << "2: " << a_tree.inPathLength() << endl;
    cout << "3a: " << average << endl;
    cout << "3b: " << average/ log2(path) << endl;

    Sequences(seq_filename, a_tree);
    nodes = a_tree.inPathLength();
    path = a_tree.totalNodes();
    average = (double)nodes/(double)path;
    cout << "6a: " << nodes << endl;
    cout << "6b: " << average << endl;
    cout << "6c: " << average/ log2(path) << endl;
  }

}  // namespace

int
main(int argc, char **argv) {
  /*if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
    }*/
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  //cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
