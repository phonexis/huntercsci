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
};
  
Network::Network(){
  numUsers=0;
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
  
int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
