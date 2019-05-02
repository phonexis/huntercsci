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

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];
  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn){
    for(int i=0;i<MAX_USERS;i++){
      if(profiles[i].getUsername()==usrn){
	return i;
      }
    }
    return -1;
  }
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
  bool follow(string usrn1,string usr2);
  void printDot();
};
  
Network::Network(){
  numUsers=0;
  for(int i=0;i<MAX_USERS;i++){
    for(int j=0;j<MAX_USERS;j++){
      following[j][i]=false;
    }
  }
}

bool Network::addUser(string usrn,string dspn){
  if(numUsers==20){
    return false;
  }
  else{
    if(findID(usrn)!=-1){
      return false;
    }
    else if(findID(usrn)==1){
      return false;
    }
    else{
      for(int i=0;i<usrn.length();i++){
	if(!isalpha(usrn[i]) && !isdigit(usrn[i])){
	  return false;
	}
      }
      numUsers+=1;
      profiles[numUsers-1]=Profile(usrn,dspn);
      return true;
    }
  }
}

bool Network::follow(string usrn1,string usrn2){
  int id1=findID(usrn1);
  int id2=findID(usrn2);
  if(id1!=-1 && id2!=-1){
    return true;
  }
  return false;
}

void Network::printDot(){
  std::cout << "digraph {" << std::endl;
  for(int i=0;i<numUsers;i++){
    std::cout << "@" << profiles[i].getUsername() << std::endl;
  }
  for(int i=0;i<numUsers;i++){
    for(int j=0;j<numUsers;j++){
      if(following[j][i]==true){
	std::cout << "@" << following[i] << " -> " << following[j] << std::endl;
      }
    }
  }
}
  

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
