// Homework 4
// Testing Sorting Algorithms
// Emily Fang

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// Test function that shows how you can time a piece of code.
// Just times a simple loop.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();    
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  vector<int> v{size_of_vector};
  srand(time(NULL));
  for (int i = 0; i < size_of_vector; i++) {
    int randnum = rand() % 100 + 1;
    v[i] = randnum;
  }
  return v;
}

// Generate and returns sorted vecotr of size @size_of_vector
// If smaller_to_larger is true, returns vector sorted from small to large
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  vector<int> v{size_of_vector};
  if (smaller_to_larger) {
    for (int i = 0; i < size_of_vector; i++) {
      v[i] = i;
    }
    return v;
  }
  else {
    int diff = size_of_vector;
    for (int i = size_of_vector; i > 0; i--) {
      v[i - diff] = i;
      diff --;
    }
    return v;
  }
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  // Add code
  /* if (typeid(Comparator) == typeid(greater)) {
    for(int i = 0; i < input.size(); i++) {
      if(input[i] < input[i+1]) {
	return false;
      }
    }
    return true;
  }
  else {
    for(int i = 0; i < input.size(); i++) {
      if(input[i] > input[i+1]) {
	return false;
      }
    }
    return true;
    }*/
}

// Computes duration given a start time and a stop time in nano seconds
auto ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  // Add code
  return end_time - start_time;
}

// Wrapper function to test different sorting algorithms
void sortTestingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return;
  }
  
  // This block of code to be removed for your final submission.
  TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    // Generate random vector
    input_vector = GenerateRandomVector(input_size);
    for(int x: input_vector) {
      cout << x << ", ";
    }
  } else {
    // Generate sorted vector.
    if (input_type == "sorted_small_to_large") {
      input_vector = GenerateSortedVector(input_size, true);
      for(int x: input_vector) {
	cout << x << ", ";
      }
    }
    else {
      input_vector = GenerateSortedVector(input_size, false);
      for(int x: input_vector) {
	cout << x << ", ";
      }
    }
  }

  // Call quicksort / heapsort / mergesort using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // MergeSort(input_vector, less<int>{})
  // otherwise call
  // MergeSort(input_vector, greater<int>{})
  // ...

  // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // QuickSort(input_vector, less<int>{})
  // otherwise call
  // QuickSort(input_vector, greater<int>{})
  // ...

}

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  sortTestingWrapper(argc, argv);

  return 0;
}
