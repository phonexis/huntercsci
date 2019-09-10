#include <iostream>

class Fish{
public:
  Fish();
  Fish(std::string name, bool domestic = false, bool predator = false);
  bool isVenomous() const;
  void setVenomous();
private:
  bool venomous_;
}
