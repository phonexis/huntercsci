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


int difference(std::string string1, std::string string2){
  int diff=0;
  for(int i=0;i<string1.length();i++){
    if(string1[i]!=string2[i]){
      diff+=1;
    }
  }
  return diff;
}

/*
void sort2(double *p,double *q){
  double hold=p;
  if(*p>*q){
    p=q;
    q=hold;
  }
}

double x=1.0;//value
double* p=&x;
p=&x;//p on its own is the address of x
*p=1.0;//* cancels out & so you're left with the value
*/

std::string hamming(std::string s1,std::string s2){
  std::string first=translation(s1);
  std::string second=translation(s2);
  if(first.length()==second.length()){
    if(first==second ){
      return "no";
    }
    else{
      return "yes";
    }
  }
    return "yes";
}

int main(){
  std::ifstream fin("mutations.txt"); //text file
  if (fin.fail()) {
    std::cerr << "File cannot be read, opened, or does not exist.\n";
    exit(1);
  }
  std::string strand1,strand2;
  
  while(fin >> strand1 >> strand2){
    //std::cout << strand1 << " " << strand2 << std::endl; //print new strand
    //std::cout << translation(strand1) << std::endl;
    //std::cout << translation(strand2) << std::endl;    
    std::cout << difference(strand1,strand2) << " " << hamming(strand1,strand2) << std::endl;
  }
  fin.close();
  return 0;
}
