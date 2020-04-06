NAME: Emily Fang
csci 335 - HW 3
Objective: Familiarizing myself with hashing implementations for linear, quadratic, and double hashing.

Q1:
PART 1: Implements the linear and quadratic hashing tables to insert words from a words text file and perform queries. In addition, it summarizes the # of elements, table size, collision count, and average collisions post-insertions. It also prints out the # of probes after each query.
    Bugs encountered: Recalling the differences between lienar and quadratic hashing.
    Initializing variables properly:
    		 int collisions, size = 0; vs int collisions = 0, size = 0;

PART 2: Implements the double hashing table to insert words from a words text file and perform queries. In addition, it summarizes the # of elements, table size, collision count, and average collisions post-insertions. It also prints out the # of probes after each query.
     RVALUES USED: 13, 41, 71
    Bugs encountered: Understanding the purpose of the second hash in relation to the first hashing function.

PART 3: Implements the double hashing tables to make a dictionary of words to make queries to check spelling. It also performs three different tasks:
     	1) Adding one character in any possible position
	2) Removing one character from the word
	3) Swapping adjacent characters in the word
	These tasks are split up into three functions that return vectors of strings containing all possibilities for its task performed. The vectors are iterated through and checked in the dictionary and prints the corresponding statements.
    Bugs encountered: char and string manipulations.

-------------------------------------------------------------------------
You will use this exact Makefile for your Homework 3. If you need to change it, please consult with me first.

You can compile everything by typing 

make clean
make all

You can compile one program individually by just typing make <Program Name>, for example

make query_tree

By typing 

make clean

You delete all .o files and executables.
--------------------------------------------------------------------------
Part 1: ./create_and_test_hash <words file name> <query words file name> <flag>
Part 2: ./create_and_test_hash words.txt query_words.txt double <R VALUE>
Part 3: ./spell_check <document file> <dictionary file>
