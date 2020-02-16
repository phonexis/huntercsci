NAME: Emily Fang
csci 335 - HW 1
Objective: To create 2 permute functions such that one acts recurisively to print out string permutations while the other is the driver.
To implement the functionalities of the points2 class such that it includes the Big Five and operator overloaders for <<, +, =, and [].


Warnings due to the for loops comparing int i with size_t size_
Completion:
 Question 1: Implemented the permute functions such that the function with a single parameter calls for the other permute function, which runs recursively to swap chars of a string copy.
      Bugs encountered: I didn't realize that I had to put the recursive function before the single parameter permute function. Now, I understand that the order matters, especially since the code is read from the top downwards.


 Question 2 (Part 1): Implemented the Big Five functions to create teh destructor and various constructors/move functionalities.
      Bugs encountered: Neglected the cases in which a sequence is empty or does not exist in the destructor and copy constructor. Neglected to make a deep copy for the copy constructor. (My initial approach created a shallow copy using pointer assignemnt.) Neglected to realize that a point's x and y should eb accessed by treating the sequence as a 2-d array.
      
 Question 2 (Part 2): Overloaded the + and [] operators.
      Bugs encountered: Neglected the case in which an object has size 0. Neglected to realize that only two cases are necessary for the + operator rather than 3 (when the sizes are the same, when c1 is larger, when c2 is larger.) Now, the operator has to cases where c1 i greater than or equal to c2 and where c2 is greater than c1. Neglected to check the location and th size such that location<size; otherwise, you wouldn't be able to access an index ut of scope.


COMPILATION--------------------------------------------------------------

You will use this exact Makefile for your Homework 1.
Failure to do so will result in deduction of points.

To compile on terminal type
  make clean
  make all

To delete executables and object file type
  make clean

To run:

./test_points2

^^In that case you will provide input from standard input.

To run with a given file that is redirected to standard input:

./test_points2 < test_input_file.txt

