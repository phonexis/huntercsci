// YOUR NAME.

#include "quadratic_probing.h"
#include "double_hashing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*string taskA(string s) {

}

string taskB(string s) {

}

string taskC(string s) {

}*/

int testSpellingWrapper(int argument_count, char** argument_list) {
  const string document_filename(argument_list[1]);
  const string dictionary_filename(argument_list[2]);

  HashTableDouble<string> dictionary;
  dictionary.RVal(13);
  int collisions = 0;
  ifstream dictionary_file;
  string input, word;
  dictionary_file.open(dictionary_filename);
  while(getline(dictionary_file, input)) {
    dictionary.Insert(input, collisions);
    // std::cout << input << std::endl;
  }
  dictionary_file.close();


  ifstream document_file;
  document_file.open(document_filename);
  
  while(getline(document_file, input)) {
    std::stringstream ss(input);
    while(ss >> word) {
      if(dictionary.Contains(word, collisions)) {
	std::cout << word << " is CORRECT" << std::endl;
      }
      else {
	//std::cout << input << " is INCORRECT" << std::endl;
	//std::cout << "** " << input << " -> " << " ** case A" << std::endl;
	//std::cout << "** " << input << " -> " << " ** case B" << std::endl;
	//std::cout << "** " << input << " -> " << " ** case C" << std::endl;
      }
    }
  }
  
  document_file.close();

  // Call functions implementing the assignment requirements.
  return 0;
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE MAIN.
// WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE THERE.
// This main is only here for your own testing purposes.
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);

  return 0;
}
