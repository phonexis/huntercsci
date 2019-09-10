#include "Bird.cpp"

Bird::Bird(){

}
Bird::Bird(std::string name, bool domestic, bool predator){

}
bool Bird::isAirborne() const{
  return airborne_;
}
bool Bird::isAquatic() const{
  return aquatic_;
}
void Bird::setAirborne(){
  if(airborne_==true){
    airborne_=false;
  }
  else{
    airborne_=true;
  }
}
void Bird::setAquatic(){
  if(aquatic_==true){
    aquatic_=false;
  }
  else{
    aquatic_=true;
  }
}
