#include "Roster.hpp"

Roster::Roster(){
  root_ptr_ = nullptr;
}

//DESTRUCTOR FUNCTION
Roster::~Roster(){
  destroyTree(root_ptr_);
}
void Roster::clear(){
  destroyTree(root_ptr_);
}

//PRIVATE MEMBER DESTRUCTOR HELPER FUNCTION
void Roster::destroyTree(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr){
  if(sub_tree_ptr != nullptr){
    destroyTree(sub_tree_ptr->getLeftChildPtr());
    destroyTree(sub_tree_ptr->getRightChildPtr());
    sub_tree_ptr.reset();
  }
}

//REMOVES VALUE ---------------------------------------account for gpa and shiz
auto Roster::removeValue(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr, const Student target, bool& success){
  std::string FirstName = target.getFirstName();
  std::string LastName = target.getLastName();
  if(sub_tree_ptr == nullptr){
    success = false;
    return sub_tree_ptr;
  }
  if((sub_tree_ptr->getItem()).getFirstName() == FirstName && (sub_tree_ptr->getItem()).getLastName() == LastName){
    sub_tree_ptr = removeNode(sub_tree_ptr);
    success = true;
    return sub_tree_ptr;
  }
  /*else
    {
      if (subtree_ptr->getItem() > target)
	{
	  // Search the left subtree
	  subtree_ptr->setLeftChildPtr(removeValue(subtree_ptr
						   ->getLeftChildPtr(), target, success));
	}
      else
	{
	  // Search the right subtree
	  subtree_ptr->setRightChildPtr(removeValue(subtree_ptr
						    ->getRightChildPtr(), target, success));
	}
      return subtree_ptr;
      } // end if*/
}

//REMOVES STUDENT
bool Roster::remove(Student& pupil){
  bool success = false;
  root_ptr_ = removeValue(root_ptr_, pupil, success);
  return success;
}

//COPY FUNCTION
auto Roster::copyTree(const std::shared_ptr<BinaryNode<Student> > old_tree_root_ptr){
  std::shared_ptr<BinaryNode<Student> > new_tree_ptr;
  if(old_tree_root_ptr != nullptr){
    new_tree_ptr = std::make_shared<BinaryNode<Student> >(old_tree_root_ptr->getItem(), nullptr, nullptr);
    new_tree_ptr->setLeftChildPtr(copyTree(old_tree_root_ptr->getLeftChildPtr()));
    new_tree_ptr->setRightChildPtr(copyTree(old_tree_root_ptr->getRightChildPtr()));
  }
  return new_tree_ptr;
}

Roster::Roster(const Roster& tree){
  root_ptr_ = copyTree(tree.root_ptr_);
}

bool Roster::isEmpty() const{
  if(root_ptr_ == nullptr){
    return true;
  }
  return false;
}

void Roster::add(Student& pupil){
  auto new_node_ptr = std::make_shared<BinaryNode<Student> >(pupil);
  placeNode(BinaryNode(root_ptr_, new_node_ptr));
}
template<class T>
auto Roster::placeNode(std::shared_ptr<BinaryNode<Student> > sub_tree_ptr, std::shared_ptr<BinaryNode<Student> > new_node_ptr){
  if(sub_tree_ptr == nullptr){
    return new_node_ptr;
  }
  else{
    //implement a way to compare student names here since we aren't using numerical values
    //------------------------------------------------------------------------
    if(sub_tree_ptr->getItem() > new_node_ptr->getItem()){
      sub_tree_ptr->setLeftChildPtr(placeNode(sub_tree_ptr->getLeftChildPtr(), new_node_ptr));
    }
    else{
      sub_tree_ptr->setRightChildPtr(placeNode(sub_tree_ptr->getRightChildPtr(),new_node_ptr));
    }
    return sub_tree_ptr;
  }
}
void Roster::add(std::vector<Student> pupil){
  for(int i = 0; i < pupil.size(); i++){
    add(pupil[i]);
  }
}
 
//MAIN FUNCTION TO FIND HEIGHT
int Roster::getHeight(){
  return getHeightHelper(root_ptr_);
}
//HELPER FUCNTION CALLED IN MAIN FUNCTION
int Roster::getHeightHelper(std::shared_ptr<BinaryNode<Student>> sub_tree_ptr) const{
  if(sub_tree_ptr == nullptr){
    return 0;
  }
  return 1 + std::max(getHeightHelper(sub_tree_ptr->getLeftChildPtr()),getHeightHelper(sub_tree_ptr->getRightChildPtr())); 
}

void Roster::display(){

}
