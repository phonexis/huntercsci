#include "Mammal.hpp"

Mammal::Mammal(){

}
Mammal::Mammal(std::string name, bool domestic, bool predator){

}
bool Mammaml::hasHair() const{
  return hair_;
}
bool Mammal::isAirborne() const{
  return airborne_;
}
bool Mammal::isAquatic() const{
  return aquatic_;
}
bool Mammal::isToothed() const{
  return toothed_;
}
bool Mammal::hasFins() const{
  return fins_;
}
bool Mammal::hasTail() const{
  return tail_;
}
int Mammal::legs() const{
  return legs_;
}
void Mammal::setHair(){
  if(hair_==true){
    hair_=false;
  }
  else{
    hair_=true;
  }
}
void Mammal::setAirborne(){
  if(airborne_==true){
    airborne_=false;
  }
  else{
    airborne_=true;
  }
}
void Mammal::setAquatic(){
  if(aquatic_==true){
    aquatic_=false;
  }
  else{
    aquatic_=true;
  }
}
void Mammal::setToothed(){
  if(toothed_==true){
    toothed_=false;
  }
  else{
    toothed_=true;
  }
}
void Mammal::setFins(){
  if(fins_==true){
    fins_=false;
  }
  else{
    fins_=true;
  }
}
void Mammal::setTail(){
  if(tail_==true){
    tail_=false;
  }
  else{
    tail_=true;
  }
}
void Mammal::setLegs(int legs){
  legs_=legs;
}
