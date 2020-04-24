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
  //cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();    
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  //cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  vector<int> v(size_of_vector);
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
  vector<int> v(size_of_vector);
  if (smaller_to_larger) { // least -> greatest
    for (int i = 0; i < size_of_vector; i++) {
      v[i] = i;
    }
    return v;
  }
  else { //greatest -> least
    int diff = size_of_vector;
    for (int i = 0; i < size_of_vector; i++) {
      v[i] = diff;
      diff --;
    }
    return v; //return generated vector
  }
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  for(int i = 1; i < input.size(); i++) { //checks elements if sorted
    // uses comparator as function
    if(less_than(input[ i ], input[ i - 1 ])) { // if 0, then false/not sorted
	return false;
      }
  }
  return true; //sorted
}

// Computes duration given a start time and a stop time in nano seconds
auto ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  return (end_time - start_time).count();
}

// Wrapper function to test different sorting algorithms
void sortTestingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);

  //Error handling/ Error catching statments:
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

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;

  //Generates, random, large -> small, or small -> large vectors for sorting
  if (input_type == "random") {
    // Generate random vector
    input_vector = GenerateRandomVector(input_size);

  } else {
    // Generate sorted vector.
    if (input_type == "sorted_small_to_large") {
      input_vector = GenerateSortedVector(input_size, true);
    }
    else {
      input_vector = GenerateSortedVector(input_size, false);
    }
  }


  /*
   * Prints out the test statements, including time duration (ComputeDuration) and verification fo correctness(VerifyOrder)
   * resets being count and end count before and after each sorting algo
   * Vectors should retain the same order if the sorting is correct.
*/
  if (comparison_type == "less") { //less -> great
    //passes less<int> as the comparator function
    cout << "Heapsort" << endl << endl;
    auto begin = chrono::high_resolution_clock::now();
    HeapSort(input_vector, less<int>{});
    auto end = chrono::high_resolution_clock::now();    
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) <<endl << endl;
    
    cout << "Mergesort" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    MergeSort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) <<endl << endl;

    cout << "Quicksort" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) <<endl << endl;

    cout << "Testing Quicksort Pivot Implementations" << endl << endl;
    cout << "Median of Three" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) <<endl << endl;

    cout << "Middle" << endl << endl;
    QuickSort2(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) <<endl << endl;

    cout << "First" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort3(input_vector, less<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) <<endl << endl;
    
  } else { //greatest -> least sorting
    //passes greater<int> as the comparator function
    cout << "Heapsort" << endl << endl;
    auto begin = chrono::high_resolution_clock::now();
    begin = chrono::high_resolution_clock::now();
    HeapSort(input_vector, greater<int>{});
    auto end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) <<endl << endl;
    
    cout << "Mergesort" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    MergeSort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) <<endl << endl;


    cout << "Quicksort" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) <<endl << endl;

    cout << "Testing Quicksort Pivot Implementations" << endl << endl;
    cout << "Median of Three" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) <<endl << endl;

    cout << "Middle" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort2(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) <<endl << endl;

    cout << "First" << endl << endl;
    begin = chrono::high_resolution_clock::now();
    QuickSort3(input_vector, greater<int>{});
    end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << ComputeDuration(begin, end) << " ns" << endl;
    std::cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) <<endl << endl;
  }
}

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  sortTestingWrapper(argc, argv);

  return 0;
}
