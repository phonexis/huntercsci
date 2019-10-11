/*
EMILY FANG
CSCI 235
PROJECT 3
*/
#include "ZooRecord.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

ZooRecord::ZooRecord(){
  item_count_=0;
}

ZooRecord::ZooRecord(std::string input_file_name){
  std::string input,junk; //the name of the lines being taken in by getline()
  std::string necessary; //the columns that have these stored values to take
  
  std::ifstream fin(input_file_name.c_str()); //streams the file with the name fin
  if(fin.fail()){ //in the case that the file doesn't open properly
    std::cerr << "File cannot be opened for reading" << std::endl;
    exit(1);
  }
  
  getline(fin,junk); //take the first row, which are the column titles
  while(getline(fin,input)){ //for each row
    std::stringstream strstream(input); //read each line as a stringstream called strstream

    //FOR THE ANIMAL OBJECT CONSTRUCTION
    std::string name, classtype=""; //stores animal name
    bool hair,domestic,airborne,aquatic,toothed,predator,venomous,fins,tail=false;
    int legs=0;
    
    //NAME LINES===========================================================
    getline(strstream, necessary,','); //takes the delimiter ',' to show the animal name
    name=necessary; //animal name is stored
    //std::cout << necessary << " ";

    //HAIR==================================================================
    getline(strstream,necessary,',');
    hair=std::stoi(necessary);
    //std::cout << "hair:" << necessary << " ";
    
    //JUNK LINES==========================================================**
    for(int i=0;i<3;i++){
      getline(strstream,junk,',');
    }

    //AIRBORNE==============================================================
    getline(strstream,necessary,',');
    //std::cout << "airborne:" << necessary << " ";
    airborne=stoi(necessary);

    //AQUATIC===============================================================
    getline(strstream,necessary,',');
    //std::cout << "aquatic:" << necessary << " ";
    aquatic=stoi(necessary);
    //std::cout << aquatic <<std::endl;
    
    //PREDATOR LINES=======================================================
    getline(strstream,necessary,',');
    //std::cout << "predator:" << necessary << " ";
    predator=stoi(necessary);

    //TOOTHED==============================================================
    getline(strstream,necessary,',');
    //std::cout << "toothed:" << necessary << " ";
    toothed=stoi(necessary);

    //JUNK LINES=========================================================**
    for(int i=0;i<2;i++){
      getline(strstream,junk,',');
    }

    //VENOMOUS============================================================
    getline(strstream,necessary,',');
    //std::cout << "venomous:" << necessary << " ";
    venomous=stoi(necessary);

    //FINS================================================================
    getline(strstream,necessary,',');
    //std::cout << "fins:" << necessary << " ";
    fins=stoi(necessary);

    //LEGS======== =======================================================
    getline(strstream,necessary,',');
    //std::cout << "legs:" << necessary << " ";
    legs=std::stoi(necessary);

    //TAIL====================================================================
    getline(strstream,necessary,',');
    //std::cout << "tail:" << necessary << " ";
    tail=stoi(necessary);
    
    //DOMESTIC LINES========================================================
    getline(strstream,necessary,',');
    //std::cout << "domestic:" << necessary << " ";
    domestic=stoi(necessary);

    //FINAL JUNK LINES=====================================================
    getline(strstream, junk, ',');

    //CLASSTYPE============================================================
    getline(strstream, necessary, ',');
    //std::cout << "classtype:" << necessary <<"\n" << std::endl;
    classtype=necessary;
    //std::cout << classtype << std::endl;

    //use indexing for the class type because there is residual data after the classtype int
    
    if(classtype[0]=='1'){ //MAMMAL
      Mammal* object= new Mammal(name,domestic,predator);
      if(hair==true){
	object->setHair();
      }
      if(airborne==true){
	object->setAirborne();
      }
      if(aquatic==true){
	object->setAquatic();
      }
      if(toothed==true){
	object->setToothed();
      }
      if(fins==true){
	object->setFins();
      }
      if(tail==true){
	object->setTail();
      }
      object->setLegs(legs);
      Animal* creature=object;
      insert(item_count_,creature);
      //std::cout << " mammal" << std::endl;
    }
    if(classtype[0]=='2'){ //BIRD
      Bird* object= new Bird(name,domestic,predator);
      if(airborne==true){
	object->setAirborne();
      }
      if(aquatic==true){
	object->setAquatic();
      }
      Animal* creature=object;
      insert(item_count_,creature);
      //std::cout << " bird" << std::endl;
    }
    if(classtype[0]=='4'){ //FISH
      Fish* object= new Fish(name,domestic,predator);
      if(venomous==true){
	object->setVenomous();
      }
      Animal* creature=object;
      insert(item_count_,creature);
      //std::cout << " fish" << std::endl;
    }
  }
  fin.close(); //close the stream
}

ZooRecord::~ZooRecord(){
  clear(); //calls clear
}

void ZooRecord::clear(){
  Node<Animal*>* deletion = first_; //first node
  while(first_ != nullptr){ //while there is no first node || first isnt a nullptr
    first_=first_->getNext(); //reassign the first to the next node to store it

    deletion->setNext(nullptr); //set the node after the first to nullptr
    deletion->setPrevious(nullptr); //set the previous node to nullptr

    //delete the item
    Animal* animal=deletion->getItem(); //get the Animal pointer to the derived object
    delete animal; //delete the object
    animal=nullptr; //handle the dangling ptr
    delete deletion; //delete the first

    deletion=first_;
  }

  last_=nullptr;
  item_count_=0; //cleared means that there are no items
}

bool ZooRecord::remove(size_t position){
  
  Node<Animal*>* ptr=getPointerTo(position); //get the pointer to the node you want to remove
  if(ptr == nullptr){ //if null, then it is a pointer you cant remove
    return false;
  }
  
  else{ //3 CONDITIONS TO PAY ATTENTION TO
    if(ptr == first_){ //FIRST NODE

      //removes the first node
      first_=ptr->getNext(); //first pointer assigned to the second
      first_->setPrevious(nullptr); //first pointer set to null

      //returns node to the system
      ptr->setNext(nullptr); //the pointer to the next pointer set to null

      //delete object & pointer
      Animal* animal=ptr->getItem();
      delete animal;
      animal=nullptr; //handle the dangling pointer
      delete ptr;
      ptr=nullptr;
    }
    else if(ptr==last_){ //LAST NODE
      //remove last node
      last_=ptr->getPrevious(); //last_ is now pointing to the second to last node
      last_->setNext(nullptr); //last node is now null

      ptr->setPrevious(nullptr);// set the previous pointer to null
      //delete object & pointer
      Animal* animal=ptr->getItem();
      delete animal;
      animal=nullptr; //handle the dangling pointer
      delete ptr;
      ptr=nullptr;
    }
    else{ //MIDDLE NODE
      //remove middle
      ptr->getPrevious()->setNext(ptr->getNext()); //set the previous pointer's next to the next pointer
      ptr->getNext()->setPrevious(ptr->getPrevious()); //set next pointer's previous to the previous pointer

      //both pointers are 
      ptr->setNext(nullptr); 
      ptr->setPrevious(nullptr);
      
      //delete object & pointer
      Animal* animal=ptr->getItem();
      delete animal;
      animal=nullptr;
      delete ptr;
      ptr=nullptr;
    }
    item_count_-=1; //one less item
    return true; //removal successful
  }
}
void ZooRecord::display(){ 
  for(int i=0;i<item_count_;i++){ //for items in the record
    getItem(i)->display(); // -> references individual members of classes
  }
}
