NAME: Emily Fang
csci 335 - HW 2
Objective: Familiarizing myself with lists and trees and compare the performance of the self-balancing AVL tree (by working with a real world data set and construct a generic test routine for comparing several different implementations of the tree container class).

Q1: Implements the standard library find() function by returning the iterator containing the first occurence of x in the range starting at some start and ending at some end value.
    Bugs encountered: I was unsure of what to reference initially and what to be comparing x to.

Q2 Part 1: Creates a SequenceMap with a string recognition_sequence_ and a vector<string> enzyme_acronyms. Implements a 2 parameter constructor, operator<, operator<<, a Merge function to merge objects sharing the same recognition sequence without affecting the other_sequence object.
   Problems encountered: I was initially confused about the purpose of each private data member and mistakened the one-to-many relationship they shared.
   Bugs encountered: Not passing endl into the out stream of operator<< .

Q2 Part 2:
   2a: Implements QueryTree to read into a database to populate an AVL tree with SequenceMap objects by taking in a enzyme acronym followed by recognition sequence(s), which is done by a separate helper function. This also queries (using cin) recognition squences to print out enzymes under the same object. If the recognition sequence exists in the tree, it will print the enzymes, otherwise it will return a "Not Found" message. 
       Bugs encountered: Returning a pointer to the SequenceMap (Originally, I tried to return an AvlNode pointer but it was not reasonable to since it is a private struct). Using string stream with '/' delimiter resulted in another case to account for, where the recognition sequence is an empty string. Putting the cin in the main() instead of the QueryTree function.

   2b: Implements a test routine that can construct a search tree by parsing a database file, prints the number of nodes, average depth, ratio of the average depth, successful queries, and average number of recursion calls. Added a private member to keep track of the # of nodes. Added dereferenced parameters to increment recursion calls. Added public and priavte member functions to return the total # of nodes and the internal path length.
       Bugs encountered: My output was different from the expected output in the txt file but it was within the acceptable range. Accidentally swapping the internal path length with the number of nodes. Understanding where to increment the # of calls within the given functions.

   2c: Implements the same functions as 2b but the double rotation functions are modified to not call 2 single rotations and the results should be the same as 2b as well.
       Problems encountered: Understanding how to approach the rotation and when/how to recalculate the new height post-rotation.


You will use this exact Makefile for your Homework 2. If you need to change it, please consult with me first.

You can compile everything by typing 

make clean
make all

You can compile one program individually by just typing make <Program Name>, for example

make query_tree

By typing 

make clean

You delete all .o files and executables.

--Note that file avl_tree_modified.h is not provided.
