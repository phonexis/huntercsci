#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

char DNAbase_to_mRNAbase(char letter){
  if(letter=='A'){ //A
    return 'U';
  }
  else if( letter=='T'){ //T
    return 'A';
  }
  else if(letter=='C'){ //C
    return 'G';
  }
  else if(letter=='G'){ //G
    return 'C';
  }
}

std::string transcript(std::string theDNA){
  std::string theRNA;
  for(int i=0;i<theDNA.length();i++){
    theRNA+=DNAbase_to_mRNAbase(toupper(theDNA[i]));
  }
  return theRNA;
}

int main(){
  std::ifstream fin("dna.txt");
  if (fin.fail()) {
    std::cerr << "File cannot be read, opened, or does not exist.\n";
    exit(1);
  }
  std::string strand;
  while(getline(fin, strand)){
    std::cout << transcript(strand) << std::endl;
  }
  fin.close();

  return 0;
}
