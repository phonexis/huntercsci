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
      return (((c - 'a') + rshift) % 26) + 'a';;
    }
    else {
      return (((c - 'A') + rshift) % 26) + 'A';;
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

int main(){
  std::string input="ab cde fg";
  std::cout << test_ascii(input);
  std::cout << encryptCaesar("Hello, World!",10) << std::endl;
  std::cout << encryptCaesar("z ab",8) << std::endl;
  //getline(std::cin, input);

  return 0;
}
