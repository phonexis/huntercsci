/*
return is returning it back to the caller
if you just wanted to print out results opposed to returning, you would use a void function. you could still use an int function but its return is unpredictable.
std::cerr (Standard Error)
User input and output is a very small part that is visible.
*/

//#include "____.h" "literally a cut and paste" __.h == header file .hpp == c++ specific header file 

/*
you just want to put the signatures. not the full function so you shouldnt include full .cpp files

when you run the compiler, <> means don't look in my project file/ look in my system files. meanwhile, "" means to look in my file then my system stuff

make is an archaic build system. it has one major problem with it: uses tab, not spaces

a make file is a file you put into your directory such that when you run it, "it does its magic"
There's a target (what I want to build)
 */

//Format of a make file(Makefile)
/*
target: dependencies
        what to do to make dependencies into the target

twothings: help install // do help and install targets first before you can do whatever under this target

main: main.cpp
         g++ -o main main.cpp //this is the command I use
	 echo "I have multiple commands if I want
	 @echo "The @ sign makes it not display the command"

help: //you do not need a dependency & this cna run infinitely
//you could also specify what you want to make by writing: make [target]
      @echo "This is some help information"
      @echo "that could be printed"
*/
/*
cp Makefile ___
make -f ____
*/
//From here, you type make into your terminal to read and run the commands
