#pragma once

void test_ascii(std::string input); //TASK A
char shiftChar(char c, int rshift); //TASK B
std::string encryptCaesar(std::string palintext, int rshift); //TASK B
std::string encryptVigenere(std::string plaintext, std::string keyword); //TASK C

//TASK D
char deshiftChar(char c, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);
