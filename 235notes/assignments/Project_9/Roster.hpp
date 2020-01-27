/*
Emily Fang 12/6/19
CSCI 235 - Project 9
Mods: Creation of a Roster class which s a BST that stores Student objects in BinaryNodes provided in this project
*/
#pragma once

#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Printer.hpp"
#include "Visitor.hpp"
#include "BinaryNode.hpp"

class Roster
{
public:
  Roster(); //default constructor
  ~Roster(); //call to private destructor
  void clear();
  Roster(const Roster& tree); //copies BST
  bool isEmpty() const; //checks if empty
  void add(Student& pupil); //adds a Student 
  void add(std::vector<Student> pupil); //**************************
  bool remove(Student& pupil); //removes a Student
  int getHeight(); //returns the height
  void display(); //********************************
  // print all students inorder (as per inorder traversal), one per line, separated by comma ( i.e. “id, first_name, last_name\n” )

  //EXTRA CREDIT
  void rotateLeft();
  void rotateRight();
private:
  //PRIVATE MEMBER VARIALESB
  std::shared_ptr<BinaryNode<Student>> root_ptr_; //root

  //PRIVATE HELPER FUNCTIONS
  void destroyTree(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr); //destructor
  int getHeightHelper(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr) const; //getHeight
  auto placeNode(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr, std::shared_ptr<BinaryNode<Student> > new_node_ptr);
  
  auto removeValue(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr, const Student target, bool& success);
  
  auto copyTree(const std::shared_ptr<BinaryNode<Student> > old_tree_root_ptr);
};
