//
//  SortingComparison.cpp
//  SortTest
//
//  Created by Tiziana Ligorio on 10/4/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************


#include "SortingComparison.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

//parameterized constructor allocate values_ with array_size
SortingComparison::SortingComparison(size_t array_size): SIZE(array_size), values_(new int[SIZE]){}



/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/



/*************** SELECTION SORT + HELPER **************************/

/**
 @post Gets the position of the smallest element in an array range.
 @param a the array
 @param from the beginning of the range
 @param to the end of the range
 @return the position of the smallest element in
 the range a[from]...a[to]
 */
int SortingComparison::minPosition(int a[], int from, int to, int& comparisons)
{
    int min_pos = from;
    for (int i = from + 1; i <= to; i++){
      if (a[i] < a[min_pos]) {
	min_pos = i;
      }
      comparisons+=1;// after the comparsion between a[i] < a[min_pos]   
    }
    return min_pos;
}


/**
   @post Sorts an array in ascending order using the selection sort algorithm.
   @return the number of comparisons made by the algorithm
*/
int SortingComparison::selectionSort(int a[], size_t size)
{
  int comparisons = 0; //counter for comparison
  for (int i = 0; i < size; i++)
    {
      // Find the position of the minimum
      int min_pos = minPosition(a, i, static_cast<int>(size - 1), comparisons); //passed by reference
      // Swap the next element and the minimum
      std::swap(a[i], a[min_pos]);
    }
  return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}




/*************** INSERTION SORT **************************/


/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 @return the number of comparisons of two  array elements made by the algorithm
*/
int SortingComparison::insertionSort(int a[], size_t size)
{
  int comparisons = 0;
  for (int i = 1; i < size; i++)
    {
      int next = a[i];
      // Move all larger elements up
      int j = i;
      if(a[j - 1] <= next){ 
	comparisons += 1; //in the event that the comparison in the while loop passes but the statement doens't return true
      }
      while (j > 0 && a[j - 1] > next)
	{
	  comparisons += 1; //in the event that the wile statement returns true
	  a[j] = a[j - 1];
	  j--;
        }

      // Insert the element
      a[j] = next;
    }
  return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* MERGE SORT + HELPER **************************/

/**
 @post Merges two adjacent subarrays.
 @param a the array with the elements to merge
 @param from the start of the first subarray
 @param mid the end of the first subarray
 @param to the end of the second subarray
 */
void SortingComparison::merge(int a[], int from, int mid, int to, int& comparisons)
{
  int n = to - from + 1; // Size of the range to be merged
  // Merge both halves into a temporary array temp_array
  int* temp_array = new int[n];

  int i1 = from;
  // Next element to consider in the first half
  int i2 = mid + 1;
  // Next element to consider in the second half
  int j = 0; // Next open position in temp_array

  // Compare elements in subarrays for merging
  // As long as neither i1 nor i2 is past the end,
  // move the smaller element into temp_array

  while (i1 <= mid && i2 <= to)
    {
      comparisons += 1;//comparison with the first if statement
      comparisons += 1; //comparison if the if statement is not true
      if (a[i1] < a[i2])
        {
	  temp_array[j] = a[i1];
	  comparisons += 1; // temp array is being assigned = 1 comparison
	  i1++;
        }
      else
        {
	  temp_array[j] = a[i2];
	  comparisons += 1; // temp array is being assigned = 1 comparison
	  i2++;
        }
      j++;
    }

  // Note that only one of the two while loops below is executed

  // Copy any remaining entries of the first half
  while (i1 <= mid)
    {
      comparisons += 1; //comparison in while loop
      comparisons += 1; // temp array is being assigned = 1 comparison
      temp_array[j] = a[i1];
      i1++;
      j++;
    }
  // Copy any remaining entries of the second half
  while (i2 <= to)
    {
      comparisons += 1; // temp array is being assigned = 1 comparison
      temp_array[j] = a[i2];
      i2++;
      j++;
    }

  // Copy back from the temporary array
  for (j = 0; j < n; j++)
    {
      a[from + j] = temp_array[j];
    }

  delete[] temp_array;
}

/**
   @post Sorts the elements in a range of a array.
   @param a the array with the elements to sort
   @param from the first position in the range to sort
   @param to the last position in the range to sort (included)
   @return the number of comparisons made by the algorithm
*/
int SortingComparison::mergeSort(int a[], int from, int to)
{
  int comparisons = 0;
  if (from == to) {
    return 0;
  }
  int mid = (from + to) / 2;
  // Recursively sort the first and the second half
  comparisons += mergeSort(a, from, mid); //recursively combines comparisons
  comparisons += mergeSort(a, mid + 1, to); //recursively combines comparisons
  merge(a, from, mid, to, comparisons); //comparison count passed by reference


  return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}




/************************* QUICK SORT + HELPER**************************/

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int SortingComparison::partition(int a[], int from, int to, int& comparisons)
{
  int pivot = a[from];
  int i = from - 1; //index of data item being compared from left
  int j = to + 1;   //index of data item being compared from right
  while (i < j)    // as long as i and j did not cross (meet)
    {
      i++;
      while (a[i] < pivot){//increment i until a[i] >= pivot
	comparisons += 1; //comparison in the while loop
	i++;
      }

      j--;
      while (a[j] > pivot){ //decrement j until a[j] <= pivot
	comparisons += 1; //comparison of the while loop statement
	j--;
      }
      if (i < j){
	std::swap(a[i], a[j]);
      }
    }
  return j; // the pivot index
}

/**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
  @return the number of comparisons made by the algorithm
*/
int SortingComparison::quickSort(int a[], int from, int to)
{
  int comparison_count = 0;
  if (from >= to){return 0;}

  int p = partition(a, from, to, comparison_count);
  comparison_count += quickSort(a, from, p); //recursively adds comparison_count
  comparison_count += quickSort(a, p + 1, to); //recursively adds comparison_count


  return comparison_count;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}





/*****************************************************************/
/******************  TEST FUNCTION *******************************/
/*****************************************************************/



  //*************  IMPLEMENT runComparison HERE!!!! ************//
void SortingComparison::runComparison(data_distribution array_type){
  int selectsort[SIZE],insertsort[SIZE],mergesort[SIZE],quicksort[SIZE];
  switch(array_type){
  case RANDOM: //------------------------------------------------------------
    //RANDOM VALUES STORED IN VALUES_
    std::srand(static_cast<unsigned>(time(NULL)));
    for(int i = 0; i < SIZE; i++){
      values_[i] = std::rand() % SIZE;
      //std::cout << values_[i] << " " << std::endl;
    }
    
    //COPIES VALUES
    for(int i = 0;i < SIZE; i++){
      selectsort[i]=values_[i];
      insertsort[i]=values_[i];
      mergesort[i]=values_[i];
      quicksort[i]=values_[i];
    }

    //PRINT STATEMENTS
    std::cout << "Selection sort comparisons: " << selectionSort(selectsort, SIZE) << std::endl << std::endl;
    std::cout << "Insertion sort comparisons: " << insertionSort(insertsort, SIZE) << std::endl << std::endl;
    std::cout << "Merge sort comparisons: " << mergeSort(mergesort,0,SIZE) << std::endl << std::endl;
    std::cout << "Quick sort comparisons: " << quickSort(quicksort,0,SIZE) << std::endl << std::endl;
    break; // stops the case 
    
  case INCREASING: //---------------------------------------------------------
    //PLACES NUMBERS INCREASING FROM 0
    for(int i = 0; i < SIZE; i++){
      values_[i] = i;
      //std::cout << values_[i] << " " << std::endl;
    }
    
    //COPIES VALUES
    for(int i = 0;i < SIZE; i++){
      selectsort[i]=values_[i];
      insertsort[i]=values_[i];
      mergesort[i]=values_[i];
      quicksort[i]=values_[i];
    }

    //PRINT STATEMENTS
    std::cout << "Selection sort comparisons: " << selectionSort(selectsort, SIZE) << std::endl << std::endl;
    std::cout << "Insertion sort comparisons: " << insertionSort(insertsort, SIZE) << std::endl << std::endl;
    std::cout << "Merge sort comparisons: " << mergeSort(mergesort,0,SIZE) << std::endl << std::endl;
    std::cout << "Quick sort comparisons: " << quickSort(quicksort,0,SIZE) << std::endl << std::endl;
    break; //stops the case
    
  case DECREASING: //----------------------------------------------------------
    int val=SIZE-1; //storing the larget value that could be in values_

    //DECREASING VALUES STARTING FROM SIZE-1
    for(int i = 0; i < SIZE; i++){
      values_[i] = val;
      val-=1;
      //std::cout << values_[i] << " " << std::endl;
    }

    //COPIES VALUES
    for(int i = 0;i < SIZE; i++){
      selectsort[i]=values_[i];
      insertsort[i]=values_[i];
      mergesort[i]=values_[i];
      quicksort[i]=values_[i];
    }

    //PRINT STATEMENTS
    std::cout << "Selection sort comparisons: " << selectionSort(selectsort, SIZE) << std::endl << std::endl;
    std::cout << "Insertion sort comparisons: " << insertionSort(insertsort, SIZE) << std::endl << std::endl;
    std::cout << "Merge sort comparisons: " << mergeSort(mergesort,0,SIZE) << std::endl << std::endl;
    std::cout << "Quick sort comparisons: " << quickSort(quicksort,0,SIZE) << std::endl << std::endl;
    break; //stops the case
    
  }
}
