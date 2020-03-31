#pragma once

template <typename HashedObj>
class HashTableLinear {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit HashTableLinear(size_t size = 101) : array_(NextPrime(size))
    { MakeEmpty(); }
  
  bool Contains(const HashedObj & x) const {
    return IsActive(FindPos(x));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

  bool Insert(const HashedObj & x, int & collisions, int & probes) {
    // Insert x as active
    size_t current_pos = FindPos(x, collisions, probes);
    if (IsActive(current_pos)) {
      collisions += 1;
      return false;
    }
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash(collisions, probes);    
    return true;
  }
    
  bool Insert(HashedObj && x, int & collisions, int & probes) {
    // Insert x as active
    size_t current_pos = FindPos(x, collisions, probes);
    if (IsActive(current_pos)) {
      collisions += 1;
      return false;
    }
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash(collisions, probes);

    return true;
  }

  bool Remove(const HashedObj & x, int & collisions) {
    size_t current_pos = FindPos(x, collisions);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }

  bool Find(const HashedObj & x, int & collisions, int & probes) {
    size_t current_pos = FindPos(x, collisions, probes);
    if (!IsActive(current_pos))
      return false;
    return true;
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

  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }

  size_t FindPos(const HashedObj & x, int & collisions, int & probes) const {
    size_t offset = 1;
    size_t current_pos = InternalHash(x, offset);
      
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      collisions += 1;
      offset += 1;
      current_pos = InternalHash(x, offset);
      //current_pos += offset;  // Compute ith probe.
      
      if (current_pos >= array_.size())
	current_pos -= array_.size();
    }
    probes = offset;
    
    return current_pos;
  }

  void Rehash(int & collisions, int & probes) {
    std::vector<HashEntry> old_array = array_;
    // Create new double-sized, empty table.
    array_.resize(NextPrime(2 * old_array.size()));
    for (auto & entry : array_)
      entry.info_ = EMPTY;
    
    // Copy table over.
    current_size_ = 0;
    for (auto & entry :old_array)
      if (entry.info_ == ACTIVE)
	Insert(std::move(entry.element_), collisions, probes);
  }
  
  size_t InternalHash(const HashedObj & x, size_t offset) const {
    static std::hash<HashedObj> hf;
    return (hf(x) + offset) % array_.size( );
  }
};
