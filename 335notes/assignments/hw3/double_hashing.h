//Emily Fang
#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h> 
#include <math.h>  

//Double hashing implementation.
template <typename HashedObj>
class HashTableDouble {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit HashTableDouble(size_t size = 101) : array_(NextPrime(size))
    { MakeEmpty(); }

  //dereference of collisions to keep track of incrementation in FindPos
  bool Contains(const HashedObj & x, int & collisions) const {
    return IsActive(FindPos(x, collisions));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

  //dereference of collisions to keep track of incrementation in FindPos
  bool Insert(const HashedObj & x, int & collisions) {
    // Insert x as active
    size_t current_pos = FindPos(x, collisions);
    if (IsActive(current_pos)) {
      return false;
    }
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash(collisions);    
    return true;
  }

  //dereference of collisions to keep track of incrementation in FindPos
  bool Insert(HashedObj && x, int & collisions) {
    // Insert x as active
    size_t current_pos = FindPos(x, collisions);
    if (IsActive(current_pos)) {
      return false;
    }
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash(collisions);

    return true;
  }

  //dereference of collisions to keep track of incrementation in FindPos
  bool Remove(const HashedObj & x, int & collisions) {
    size_t current_pos = FindPos(x, collisions);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }

  //NEW FUNCTIONS ----------------------------------------------------
  
  //takes in an int for our second hashing function
  void RVal(int R) {
    R_ = R;
  }

  //returns the number of elements in the table
  int Items() {
    return current_size_;
  }

  //returns the size of the table
  int Size() {
    return array_.size();
  }

 private:        
  struct HashEntry {
    HashedObj element_;
    EntryType info_;
    
    HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
    :element_{e}, info_{i} { }
    
    HashEntry(HashedObj && e, EntryType i = EMPTY)
    :element_{std::move(e)}, info_{ i } {}
  };
    

  std::vector<HashEntry> array_;
  size_t current_size_;

  //NEW PRIVATE MEMBER: keeps track of the R value 
  int R_= 0;

  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }

  //increments collision count when finding a position for insertion
  size_t FindPos(const HashedObj & x, int & collisions) const {
    size_t current_pos = InternalHash(x);

    //offset added to the current_pos based on the number of collisions if greater than or equal to 1
    size_t second_hash = InternalHash2(x);

    //current_pos is rehashed if the positions isn't empty and doesn't exist already
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      current_pos += second_hash; //adds the offset from the second hash

      //increments collision
      collisions += 1;
      if (current_pos >= array_.size())
	current_pos -= array_.size();
    }
    
    return current_pos;
  }

  void Rehash(int & collisions) {
    std::vector<HashEntry> old_array = array_;
    // Create new double-sized, empty table.
    array_.resize(NextPrime(2 * old_array.size()));
    for (auto & entry : array_)
      entry.info_ = EMPTY;
    
    // Copy table over.
    current_size_ = 0;
    for (auto & entry :old_array)
      if (entry.info_ == ACTIVE)
	Insert(std::move(entry.element_), collisions);
  }
  
  size_t InternalHash(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return hf(x) % array_.size( );
  }

  //SECOND HASH FUNCTION
  size_t InternalHash2(const HashedObj x) const {
    static std::hash<HashedObj> hf;
    return R_ - (hf(x) % R_);
  }
};
