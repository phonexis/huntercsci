// Emily Fang
// Main file for Part2(a) of Homework 2.

#include "avl_tree_p2a.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

namespace {
  template <typename TreeType>
  void Query(const string &reco_seq, TreeType &a_tree) {
    SequenceMap* temp = new SequenceMap(reco_seq, "");
    SequenceMap* t = a_tree.find(*temp);
    if(t != nullptr) {
      cout << *t << "\n";
      delete temp;
      temp = nullptr;
    }
    else std::cout << "Not Found\n";
  }
  
  // @db_filename: an input filename.
  // @a_tree: an input tree of the type TreeType. It is assumed to be
  //  empty.
  template <typename TreeType>
  void QueryTree(const string &db_filename, TreeType &a_tree) {
    // Code for running Part2(a)
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
      if(acronym != "") {
	while (getline(s,reco_seq,'/')) {
	  if(reco_seq != "") {
	    //reco_seq = token.substr(1,token.length()-1);
	    SequenceMap new_sequence_map(reco_seq, acronym);
	    if(a_tree.contains(new_sequence_map)) {
	      a_tree.find(new_sequence_map)->Merge(new_sequence_map);
	    }
	    else a_tree.insert(new_sequence_map);
	  }
	}
      }
    }
    string sequence;
    while(cin >> sequence) {
      Query(sequence, a_tree);
    }
  }
}
  
int main(int argc, char **argv) {
  /* if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
    }*/
  string db_filename(argv[1]);
  //cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  //a_tree.printTree();

  return 0;
}
