#include <iostream>

class Bird{
public:
  Bird();
  Bird(std::string name, bool domestic = false, bool predator = false);
  bool isAirborne() const;
  bool isAquatic() const;
  void setAirborne();
  void setAquatic();
private:
  bool airborne_;
  bool aquatic_;
}
