#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#pragma once

class SequenceMap {
 public:
  //BIG FIVE
  SequenceMap() : recognition_sequence{""}, new std::vector<std::string> enzyme_acronyms{0} {};

  SequenceMap(const SequenceMap &rhs) {
    recognition_sequence_ = rhs.recognition_sequence_;
  }
  
  ~SequenceMap() = default;

  //constructs a SequenceMap from two strings
  SequenceMap(const std::string &a_rec_seq, const std::string &an_enz_acro) {
    recognition_sequence = a_rec_seq;
    enzyme_acronyms.push_back(an_enz_acro);
  }

  bool operator<(const SequenceMap &rhs) const {
    return (recognition_sequence_.compare(rhs) < 0) ? true: false;
  }

  friend std::ostream &operator<<(std::ostream &out, const SequenceMap & some_sequence) {
    for(auto x: enzyme_acronyms) {
      out << x << " ";
    }
    out << std::endl;
  }

  void Merge(const SequenceMap &other_sequence) {
    for(auto x: other_sequence) {
      int iterator = std::find(enzyme_acronyms.begin(), enzyme_acronyms.end(), x);
      if(iterator != enzyme_acronyms.end()) {
	enzyme_acronyms.push_back(x);
      }
    }
  }
  
 private:
  std::string recognition_sequence_;
  std::vector<std::string> enzyme_acronyms;

};
