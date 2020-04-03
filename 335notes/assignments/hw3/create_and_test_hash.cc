// Emily Fang

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  hash_table.MakeEmpty();
  
  int collisions = 0;
  ifstream build;
  build.open(words_filename);
  string input;

  while(getline(build, input)) {
    hash_table.Insert(input, collisions);
  }
  
  int items = hash_table.Items();
  int size = hash_table.Size();
  build.close();

  //Print statements
  cout << "number_of_elements: " << items << endl;
  cout << "size_of_table: " << size << endl;
  cout << "load_factor: " << (double)items/size << endl;
  cout << "collisions: " << collisions << endl;
  cout << "avg_collisions: "<< (double)collisions/items << endl;

  cout << endl;

  //Queries
  ifstream query;
  query.open(query_filename);
  while(getline(query, input)) {
    int probes = 1;
    if (hash_table.Contains(input, probes)) {
      std::cout << input << " Found " << probes << std::endl;
    }
    else {
      std::cout << input << " Not_Found " << probes << std::endl;
    }
  }
  collisions = 0;
  query.close();
}

int testFunctionWrapper(int argument_count, char **argument_list) {
  const string words_filename(argument_list[1]);
  const string query_filename(argument_list[2]);
  const string param_flag(argument_list[3]);
  
  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    const string R_flag(argument_list[4]);
    HashTableDouble<string> double_probing_table;
    double_probing_table.RVal(std::stoi(R_flag));
    std::cout << "r_value: " << std::stoi(R_flag) << std::endl;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Unknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}

// Sample main for program create_and_test_hash.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE MAIN.
// WE WILL DIRECTLY CALL testFunctionWrapper. ALL FUNCTIONALITY SHOULD BE THERE.
// This main is only here for your own testing purposes.
int main(int argc, char **argv) {

  /*if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
    }*/
  
  testFunctionWrapper(argc, argv);
  return 0;
}
