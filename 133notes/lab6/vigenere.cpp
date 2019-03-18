#include <iostream>
#include <string>
#include <cctype>

std::string test_ascii(std::string input){
  std::string s;
  for(int i=0;i<input.length();i++){
    char c=input[i];
    std::cout << input[i]<<" "<<(int)c<<"\n";
  }
  return s;
}

char shiftChar(char c, int rshift){
  if(isalpha(c)){
    if((int)c>=97){
      return (((c - 97) + rshift) % 26) + 97;;
    }
    else {
      return (((c - 65) + rshift) % 26) + 65;;
    }
  }  
  return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
  std::string newtext;
  for(int i=0;i<plaintext.length();i++){
    newtext+=shiftChar(plaintext[i],rshift);
  }
  return newtext;
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
  std::string encrypted;
  int c = 0;
  for (int i=0;i<plaintext.length();i++){
    char letter=plaintext[i];
    //std::cout << letter << std::endl;
    if (isalpha(letter)){
      int shift = (int)keyword[c%keyword.length()]-97;
      c+=1;
      //std::cout << shift << std::endl;
      encrypted+=shiftChar(letter,shift);
    }
    else{
      encrypted+=letter;
    }
  }
  return encrypted;
}

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
      decrypted+=shiftChar(letter,shift);
    }
    else{
      decrypted+=letter;
    }
  }
  return decrypted;
}


int main(){
  std::string input="ab cde fg";
  std::cout << test_ascii(input);
  std::cout << encryptCaesar("Hello, World!",10) << std::endl;
  std::cout << encryptCaesar("Way to Go!",5) << std::endl;
  std::cout << encryptVigenere("Hello, World!","cake") << std::endl;
  std::cout << encryptVigenere("Hello, World!","x") << std::endl;
  std::cout << decryptCaesar("Rovvy, Gybvn!",10) << std::endl;
  std::cout << decryptVigenere("Jevpq, Wyvnd!","cake") << std::endl;
  //  getline(std::cin, input);

  return 0;
}
