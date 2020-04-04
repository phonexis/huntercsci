// YOUR NAME.

#include "quadratic_probing.h"
#include "double_hashing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string clean(string s) {
  int index = 0;
  for(char &c: s) {
    if(c != 39 && c != 45 && ispunct(c)) {
      s.erase(index, 1);
    }
    if(isalpha(c) && c >= 'A' && c <= 'Z') {
      c += 32;
    }
    index ++;
  }
  return s;
}

vector<string> taskA(string s) {
  vector<string> possibilities;
  size_t i = 0;
  while (i <= s.length()) {
    string temp = s;
    for (char c = 'a'; c <= 'z'; ++c) {
      possibilities.push_back(s.substr(0,i) + c + s.substr(i,s.length( )));
    }
    i++;
  }
  return possibilities;
}

vector<string> taskB(string s) {
  vector<string> possibilities;
  size_t i = 0;
  while (i < s.length()) {
    string temp = s;
    possibilities.push_back(temp.erase(i, 1));
    i++;
  }
  return possibilities;
}

vector<string> taskC(string s) {
  vector<string> possibilities;
  size_t i = 0;
  while (i < s.length()) {
    string temp = s;
    std::swap(temp[i], temp[i+1]);
    possibilities.push_back(temp);
    i++;
  }
  return possibilities;
}

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

  int found = 0;
  ifstream document_file;
  document_file.open(document_filename);
  
  while(getline(document_file, input)) {
    std::stringstream ss(input);
    while(ss >> word) {
      string cleaned_word =  clean(word);
      if(dictionary.Contains(cleaned_word, collisions)) {
	found ++;
	std::cout << cleaned_word << " is CORRECT" << std::endl;
      }
      else {
	std::cout << cleaned_word << " is INCORRECT" << std::endl;

	for(auto possibility: taskA(cleaned_word)) {
	  if(dictionary.Contains(possibility, collisions)) {
	    found ++;
	    std::cout << "** " << cleaned_word << " -> " << possibility << " ** case A" << std::endl;
	  }
	}
	
	for(auto possibility: taskB(cleaned_word)) {
	  if(dictionary.Contains(possibility, collisions)) {
	    found ++;
	    std::cout << "** " << cleaned_word << " -> " << possibility << " ** case B" << std::endl;
	  }
	}

	for(auto possibility: taskC(cleaned_word)) {
	  if(dictionary.Contains(possibility, collisions)) {
	    found ++;
	    std::cout << "** " << cleaned_word << " -> " << possibility << " ** case C" << std::endl;
	  }
	}
	
      }
    }
  }
  
  document_file.close();

  // Call functions implementing the assignment requirements.
  return found;
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
