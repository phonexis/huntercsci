#include <iostream>
#include <cmath>

class Coord3D {
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p){
  //std::cout << pow(p[1].y,2);
  return sqrt(pow((*p).x,2) + pow(p[0].y,2) + pow(p[0].z,2));
}

Coord3D *fartherFromOrigin(Coord3D*p1,Coord3D*p2){
  if(length(p1)>length(p2)){
    return p1;
  }
  else{
    return p2;
  }
}

void move(Coord3D *ppos,Coord3D *pvel,double dt){
  ppos[0].x=ppos[0].x + (pvel[0].x)*dt;
  ppos[0].y=ppos[0].y + (pvel[0].y)*dt;
  ppos[0].z=ppos[0].z + (pvel[0].z)*dt;
}

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z){
  Coord3D *p=new Coord3D;
  (*p).x=x;
  (*p).y=y;
  (*p).z=z;
  return p;
}

// free memory
void deleteCoord3D(Coord3D *p){
  delete p;
}

int main(){
  /*Coord3D pointP={10,20,30};
  Coord3D pointQ={-20,21,-22};
  std::cout << "Address of P: " << &pointP << std::endl;
  std::cout << "Address of Q: " << &pointQ << std::endl << std::endl;

  Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
  std::cout << "ans = " << ans << std::endl; // So which point is farther?
  std::cout << fartherFromOrigin(&pointP,&pointQ) << std::endl;
  std::cout << length(&pointP) << std::endl;
  */
  /*
  Coord3D pos={0,0,100.0};
  Coord3D vel={1,-5,0.2};

  move(&pos,&vel,2.0);
  std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
  */
  double x, y, z;
  std::cout << "Enter position: ";
  std::cin >> x >> y >> z;
  Coord3D *ppos = createCoord3D(x,y,z);
    
  std::cout << "Enter velocity: ";
  std::cin >> x >> y >> z;
  Coord3D *pvel = createCoord3D(x,y,z);

  move(ppos, pvel, 10.0);

  std::cout << "Coordinates after 10 seconds: " 
	    << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

  deleteCoord3D(ppos); // release memory
  deleteCoord3D(pvel);
  return 0;
}
