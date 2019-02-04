#include <iostream>

/*
make [linux command] utilizes a for loop to compile files (automating the process for z) 
it looks to see if a file is already made; otherwise, it will make it 
compiled_file << EOF

if we dont explicitly return something, it returns whatever is in the memory.

ray tracing- you have to calculate what objects it hits and what it hits first (similar to radiocity) objects are surrounded by bounding spheres to make calculations rather than calculating many polygons together. since ost of the rays are going to miss the spheres, you use the discriminant such that is less than 0, you "throw it away"

using std::cout in your functions, you are sending information to the screen rather than processing it into something you can use. A general rule of the thumb is functions should not do inputs and outputs unless it is specifically for inputs and outputs.
originally, c++ didn't have void . "always having it return an int but not using it" kind of thing
To reduce complexity, you keep things in its place.
Currently, 133 is using private repos

Stylistically, you put main at the bottom (unless you have something like a circular dependency)
signature line/prototype -> calling a function and ending it with a semicolon before main (with main being before the actual function)
*/

//onefile
int smaller(int, int); // signature

int main(){
  
  return 0;
}

//another
int smaller(int a, int b)
{

}

/*
the object file is the machine code that needs extra pieces of information and the final step is converting your .o files into executables [g++ -o filename]
g++ -c filename means to link a file into an executable
g++ on its own means to do the whole thing
g++ onefile.o another.o or you could just put the cpp files instead of the object files and compiles the two together
consistency+readability of files by having signatures
file.h (header file)
#include "file.h"
when you have this include line, it cuts the lines fo file.h and pastes it(your protoypes) into your file
#pragma once [modern way] vs #ifndef, #define, and #endif [original way] in your file.h 
*/

//lab thursday as is and will be doing the folowing monday morning & rewriting lab 1 into 3 files
