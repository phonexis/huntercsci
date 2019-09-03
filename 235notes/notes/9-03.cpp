/*
Default constructor automatically supplied by compiler if no constructors are provided. Primitive types are initialized to 0.

Default destructors automatically supplied by compiler if not provided (it frees up memory)
 -Must provide destructor to free-up memory when some class performs dynamic memory allocation

documents use and limitations of a class and its methods

Function prototype and comments MUST specify: Data flow (Input=>parameters; Output=>return); Pre and Post conditions

Default Arguements
EX: void point(int x=3, int y=4);

Overloading Functions [Same name, different parameter list]

Friend Functions: functions that are not members of the class but can access private members of the class
you declare the friend function in the class interface:
EX: friend datatype someFriendFunction();

Operator Overloading: Desirable operator(=,+,-,==...) behavior may not be well defined on objects

Inheritance:
class BatchPrinter: publlic Printer //inheriting from Printer class all the public members

Overloading (independent inheritance): Define new function with same name but different parameter list (different signature or prototype)
 int someFunction(){ }
 int someFunction(string some_string){ }
Overriding: rewriting function with same signature in derived class
 int BaseClass:: someMethod(){ }
 int DerivedClass::someMethod(){ }

protected access specifier: protected members available to class members and derived classes

Important points about Inheritance:
Derived class inherits all public and protected members of base class
DOes nto have access to base class private members
Does not inherit constructor and destructor
DOes nto inherit assignment operator
Does not inherit friend functions and friend classes 
