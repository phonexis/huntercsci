#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

char DNAbase_to_mRNAbase(char letter){
  if(letter=='A'){ //A
    return 'U'; //to U
  }
  else if( letter=='T'){ //T
    return 'A'; //to A
  }
  else if(letter=='C'){ //C
    return 'G'; //to G
  }
  else if(letter=='G'){ //G
    return 'C'; //to C
  }
}

std::string transcript(std::string theDNA){ //changes strand
  std::string theRNA; //RNA
  for(int i=0;i<theDNA.length();i++){
    theRNA+=DNAbase_to_mRNAbase(toupper(theDNA[i]));
  }
  return theRNA;
}

std::string dictionary_read(std::string seg){
  std::string key, value;
  std::ifstream fin("codons.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }

  fin.clear(); // reset error state
  fin.seekg(0); // return file pointer to the beginning
  while (fin >> key >> value) {
    if(seg==key){
      return value;
    }
  }
  return "";
}

std::string translation(std::string codon){
  std::string transcripted=transcript(codon);
  bool start=false;
  int count=0;
  std::string translated, segment;

  translated+="Met";
  for(int i=0;i<transcripted.length();i+=3){
    segment=transcripted.substr(i,3);
    if(segment=="AUG" && start==false){
      start=true;
    }
    else if(dictionary_read(segment)=="Stop"){
      break;
    }
    else if(start==true){
      translated+="-"+dictionary_read(segment);
    }
  }
  return translated;
}

int main(){
  /*
    std::ifstream fin("dna.txt"); //text file
    if (fin.fail()) {
    std::cerr << "File cannot be read, opened, or does not exist.\n";
    exit(1);
    }
    std::string strand;
    while(getline(fin, strand)){
    std::cout << transcript(strand) << std::endl; //print new strand
    }
    fin.close();
  */
  std::ifstream fin("dna2b.txt"); //text file
  if (fin.fail()) {
    std::cerr << "File cannot be read, opened, or does not exist.\n";
    exit(1);
  }
  std::string strand;
  while(getline(fin, strand)){
    std::cout << translation(strand) << std::endl; //print new strand
  }
  fin.close();

  //std::cout<< translation("tacaacact") << std::endl; //this works
  return 0;
}
