// Emily Fang
// Main file for Part2(a) of Homework 2.

#include "avl_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

namespace {
  template <typename TreeType>
  void Query(const string &reco_seq, TreeType &a_tree) {
    a_tree->printReco(reco_seq);
  }
  
  // @db_filename: an input filename.
  // @a_tree: an input tree of the type TreeType. It is assumed to be
  //  empty.
  template <typename TreeType>
  void QueryTree(const string &db_filename, TreeType &a_tree) {
    // Code for running Part2(a)
    ifstream myfile(db_filename);
    string input;
    int i = 0;

    if(myfile.fail()) {
      std::cout << "Couldn't open the file!" << endl;
      return;
    }
    
    //Skips over the comments at the start of the database file
    while(i < 9) {
      getline(myfile,input);
    }

    while(getline(myfile, input)) {
      stringstream s(input);
      string token = "";
      
      getline(s,token,'/');
      string acronym = token;
      getline(s,token,'/');
      string reco_seq = token;
      SequenceMap new_sequence_map(reco_seq, acronym);
      a_tree.insert(new_sequence_map);
      
      while (getline(s,token,'/')) {
	reco_seq = token.substr(1,token.length()-1);
	SequenceMap new_sequence_map(reco_seq, acronym);
	if(a_tree.contains(new_sequence_map)) {
	  a_tree.find(new_sequence_map).Merge(new_sequence_map);
	}
	else a_tree.insert(new_sequence_map);
      }
    }
  }
}
  
int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  return 0;
}
