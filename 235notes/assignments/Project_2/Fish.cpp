#include "Fish.hpp"

Fish::Fish(){

}
Fish::Fish(std::string name, bool domestic, bool predator){

}
bool Fish::isVenomous() const{
  return venemous_;
}
void Fish::setVenomous(){
  if(venemous_==true){
    venemous_=false;
  }
  else{
    venemous_=true;
  }
}
