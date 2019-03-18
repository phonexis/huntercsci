#include <iostream>
#include <string>
#include <cctype>


char deshiftChar(char c, int rshift){
  if(isalpha(c)){
    if((int)c>=97){ //lowercase
      return (((c - 97) + (26 + rshift)) % 26) + 97;
    }
    else { //uppercase
      return (((c - 65) + (26 + rshift)) % 26) + 65;
    }
  }  
  return c;
}

std::string decryptCaesar(std::string ciphertext,int rshift){
  std::string newtext;
  for(int i=0;i<ciphertext.length();i++){
    newtext+=deshiftChar(ciphertext[i],-1*rshift);
  }
  return newtext;
}

std::string decryptVigenere(std::string ciphertext,std::string keyword){
  std::string decrypted;
  int c = 0;
  for (int i=0;i<ciphertext.length();i++){
    char letter=ciphertext[i];
    //    std::cout << letter << std::endl;
    if (isalpha(letter)){
      int shift = -(int)keyword[c%keyword.length()]+97;
      c+=1;
      //std::cout << shift << std::endl;
      decrypted+=deshiftChar(letter,shift);
    }
    else{
      decrypted+=letter;
    }
  }
  return decrypted;
}


int main(){
  std::string input="ab cde fg";
  std::cout << decryptCaesar("Rovvy, Gybvn!",10) << std::endl;
  std::cout << decryptVigenere("Jevpq, Wyvnd!","cake") << std::endl;
  //  getline(std::cin, input);
  return 0;
}
