#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#pragma once

class SequenceMap {
 public:
  //constructs a SequenceMap from two strings
  SequenceMap(const std::string &a_rec_seq, const std::string &an_enz_acro) {
    recognition_sequence_ = a_rec_seq;
    enzyme_acronyms.push_back(an_enz_acro);
  }

  bool operator<(const SequenceMap &rhs) const {
    return recognition_sequence_.compare(rhs.recognition_sequence_) < 0;
  }

  friend std::ostream &operator<<(std::ostream &out, const SequenceMap & some_sequence) {
    if(some_sequence.enzyme_acronyms.size() == 0) {
      out << "Not Found\n";
    }
    else {
      for(auto x: some_sequence.enzyme_acronyms) {
	out << x << " ";
      }
    }
    return out;
  }

  void Merge(const SequenceMap &other_sequence) {
    for(auto x: other_sequence.enzyme_acronyms) {
      auto iterator = std::find(enzyme_acronyms.begin(), enzyme_acronyms.end(), x);
      if(iterator == enzyme_acronyms.end()) {
	enzyme_acronyms.push_back(x);
      }
    }
  }
  
 private:
  std::string recognition_sequence_;
  std::vector<std::string> enzyme_acronyms;

};
