#include <iostream>

using namespace std;

class Profile{
private:
  std::string username;
  std::string displayname;
public:
  Profile(std::string usrn,std::string dspn);
  Profile();
  std::string getUsername();
  std::string getFullName();
  void setDisplayName(std::string dspn);
};

Profile::Profile(std::string usrn,std::string dspn){
  username=usrn;
  displayname=dspn;
}

Profile::Profile(){
  username="";
  displayname="";
}

std::string Profile::getUsername(){
  return username;
}

std::string Profile::getFullName(){
  return displayname + " (@" +username+")";
}

void Profile::setDisplayName(std::string dspn){
  displayname=dspn;
}

int main() {
  Profile p1("marco", "Marco");
  cout << p1.getUsername() << endl; 
  cout << p1.getFullName() << endl; 

  p1.setDisplayName("Marco Rossi");
  cout << p1.getUsername() << endl; 
  cout << p1.getFullName() << endl; 

  Profile p2("tarma1", "Tarma Roving");
  cout << p2.getUsername() << endl; 
  cout << p2.getFullName() << endl; 
}
