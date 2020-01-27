//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Adapted by Tiziana Ligorio for Project9 Fall 2019 on 11/29/19

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.hpp */
 
#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class T>
class BinaryNode
{   
private:
   T              item;           // Data portion
   std::shared_ptr<BinaryNode<T>> leftChildPtr;   // Pointer to left child
   std::shared_ptr<BinaryNode<T>> rightChildPtr;  // Pointer to right child

public:
   BinaryNode();
   BinaryNode(const T& anItem);
   BinaryNode(const T& anItem,
              std::shared_ptr<BinaryNode<T>> leftPtr,
              std::shared_ptr<BinaryNode<T>> rightPtr);

   void setItem(const T& anItem);
   T getItem() const;
   
   bool isLeaf() const;

   auto getLeftChildPtr() const;
   auto getRightChildPtr() const;
   
   void setLeftChildPtr(std::shared_ptr<BinaryNode<T>> leftPtr);
   void setRightChildPtr(std::shared_ptr<BinaryNode<T>> rightPtr);
}; // end BinaryNode

#include "BinaryNode.cpp"

#endif 
