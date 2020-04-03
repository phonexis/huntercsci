#pragma once


#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h> 
#include <math.h>  

template <typename HashedObj>
class HashTableDouble {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit HashTableDouble(size_t size = 101) : array_(NextPrime(size))
    { MakeEmpty(); }
  
  bool Contains(const HashedObj & x, int & collisions) const {
    return IsActive(FindPos(x, collisions));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

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

  bool Remove(const HashedObj & x, int & collisions) {
    size_t current_pos = FindPos(x, collisions);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }

  void RVal(int R) {
    R_ = R;
  }

  int Items() {
    return current_size_;
  }

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
  int R_= 0;

  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }

  size_t FindPos(const HashedObj & x, int & collisions) const {
    size_t current_pos = InternalHash(x);
    size_t second_hash = InternalHash2(x);
    
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      current_pos += second_hash;
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

  size_t InternalHash2(const HashedObj x) const {
    static std::hash<HashedObj> hf;
    return R_ - (hf(x) % R_);
  }
};
