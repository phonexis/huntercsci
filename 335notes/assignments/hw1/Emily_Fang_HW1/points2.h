// EMILY FANG
/* Points 2 is a class that stores a sequence (an array) and its size (because we must keep trak of an array's size separately).
Each point in a sequence is an array of size 2 (Objects of size 2). Thus, sequence_ is an array of many arrays of size 2.
This class implements the Big Five (copy assignment, move constructor, move assignment, destructor, and 0 parameter constructor) as well as operator overloading to use << to print the size and points, + to add these points/vectors together, = to implement the copy assignment, [] to access the array at a specific location. */

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2 {
 public:

  // Zero-parameter constructor.
  Points2() : size_{0} {}

  // Copy-constructor.
  Points2(const Points2 &rhs) {
    size_ = rhs.size_;
    if(rhs.size_ > 0) { //Sequence exists and has size greater than 0
      sequence_ =  new std::array<Object, 2>[rhs.size_]; // allocate for an array of the same size
      for(int i = 0; i < size_; i++) {
	sequence_[i] = rhs.sequence_[i]; //copy each object at index i
      }
    }
  }

  // Copy-assignment.
  Points2& operator=(const Points2 &rhs) { //OPERATOR = OVERLOAD call by const reference
    Points2 copy = rhs; 
    std::swap(*this, copy);
    return *this;
  }

  // Move-constructor. 
  Points2(Points2 &&rhs) : sequence_{rhs.sequence_}, size_{rhs.size_} { //reassign pointer and size
    rhs.sequence_ = nullptr; //remove rhs pointer and size
    rhs.size_ = 0;
  }

  // Move-assignment.
  Points2& operator=(Points2 &&rhs) { //OPERATOR = OVERLOAD call by r-value reference
    std::swap(sequence_, rhs.sequence_);
    std::swap(size_, rhs.size_);
  }

  // Destructor
  ~Points2(){ 
    if(size_ > 0) { //if there is a size greater than 0/ a sequence exists of size 1 or larger
      //memory deallocation
      delete sequence_; 
      sequence_ = nullptr;
      size_ = 0;
    }
  }

  // End of big-five.

  // One parameter constructor.
  Points2(const std::array<Object, 2>& item) {
    sequence_ = new std::array<Object, 2>[1]; //instantiate sequence as array of size 1
    size_ = 1;
    sequence_[0] = item; // assign first point (item) to index 0
  }

  // Read a chain from standard input.
  void ReadPoints2() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence; //first token passed by the input_stream
    input_stream >> size_of_sequence;
    sequence_ = new std::array<Object, 2>[size_of_sequence]; //instantiate a sequence of size_of_sequence
    size_ = size_of_sequence;
    
    Object token; //Each number passed in by the input_stream
    for (int i = 0 ;input_stream >> token; ++i) {
      sequence_[i][0] = token; //x coordinate assignment
      if(input_stream >> token) { //if you can pass the next token
	sequence_[i][1] = token; //y coordinate assignment 
      }
      else //no token passed -> when the size_of_sequence is not accurate/true
	sequence_[i][1] = 0; //the coordinate is 0 by default
    }
    
  }

  //@returns size_ || # of points/arrays in sequence_
  size_t size() const {
    return size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const {
    if(location < size_) { //if not out of scope
      return sequence_[location]; //return point at index location 
    }
    abort();
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
   //figure out which is larger (c1 or c2)
   if(c1.size_ >= c2.size_) {//c1 is larger or equal to c2 in size
     Points2 sum(c1); //take the larger sequence 
     for(int i = 0; i < c2.size_; i++) { //iterate through
       sum.sequence_[i][0] += c2[i][0]; //add x coordinates
       sum.sequence_[i][1] += c2[i][1]; //add y coordinates
     }
     return sum; //return the sum (which is a Points2 object)
   }
   else { //cs is larger
     Points2 sum(c2); //take the larger sequence
     for(int i = 0; i < c1.size_; i++) { //iterate through
       sum.sequence_[i][0] += c1[i][0]; //add x coordinates
       sum.sequence_[i][1] += c1[i][1]; //add y coordinates
     }
     return sum; //return the sum
   }
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) {
   if(some_points2.size_ > 0) { //sequence exists and has a size > 0
     for(int i = 0; i < some_points2.size_; i++) { //iterate through
       out << "(" << some_points2[i][0] << ", " << some_points2[i][1] << ") ";
       //stream (x, y), (has a space after , and ) )
     }
     out << std::endl; //end line
   }
   else out << "()" << std::endl; //empty sequence
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_; //an array of arrays(points)
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
