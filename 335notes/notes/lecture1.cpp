//lvalue is an expression that identifies a non-temp object (=synonym) -> &

//rvalue is an expression that identifies a temp object OR is a value not associated with an object(literal) -> &&

// COPY PREVENTION
//call-by-value: small objects that won't be changes by function

//call-by-reference: all objects that may be changed by function.

//call-by-constant-reference: large bjects that will not be changed by funciton and are expensive to copy.

//Calling by Rvalue reference
//Rvalue stores a temporary value.

//std::move converts any lvalue to rvalue
//it does not literally move your lvalue. it makes it subject to be moved

/*
The Big Five: destructor(deleting/deallocating), copy constructor(instantiates and creates a new structure), copy assignment operator=, move constructor, move assignment operator=

lvalue => copy
rvalue => move
*/


/*When do defaults fail?
- when classes contian a data member that is a pointer; otherwise, by default, you would have a copy of a pointer (now 2 pointers are pointing at an object)
- when you want a deep copy, then a clone of the entire object is needed
  + implement ddestructor, copy assignment and copy constructor operators themselves
*/


/*
If the default doesn't make sense, implement destrucotr, copy-and-move constructors, and copy-and-move assignment operators.

Copy assignemtn operator can eb implemented by creating a copy using the copy constructor then swapping it with the existing object.

Move assignment operator implemented by swapping member by member
*/

//Const means something is immutable (page 15 of the textbook)

//-----------------------------------TEMPLATES -----------------------------------------

/*
templates are type independent or generic algorithms ( function templates vs . class templates)

Object Templates
 - at least 0 parameter construcotr
 - operator=
 - copy constructor
*/

//----------------------------------MATRIX ------------------------------------------------
/*
Matrices can be written as 2-d arrays in c++
return by value, return by reference, return by const reference
returning by value => could be bad if your object is large
*/

//---------------------------------BIG-O NOTATION------------------------------------------
/*
Big-o notation is a special notation to deine upper bounds and lower bounds of functions. 
Usually the functions that we are bounding are run times and memory requirements.
Refer to runtime as T(n).

We want to establish the relative order of functions ( compare the rate of growth ).
f(n) is the actual growth rate of the algo. g(n) is the function that bounds the growth rate (which amy be upper or lower bound)

EX: If f(s) is O(x^2) then is it also O(x^3)? => YES x^3 grows faster than x^2 so x^3 grows faster than f(x). Therefore, we always have to find the smallest simple function g(x) for which f(x) is O(g(x)).


A problem that can be solved with polynomial worst-case complexity is called tractable. [SOLVABLE]
(ex: searching an ordered list, sorting a list, integer multiplication) 

Problems with higher complexities are called intractable. (which can be taken advantage of for encryption)

Problems that no clgo can solves is called unsolvable.

Model of computation: model needed for algo nalysis
One unit of times corresponds with simple instructions
Fixed size
infinite memory (interest in algo and not performance itself)

WHAT TO ANALYZE:
 - running time
 - memory usage
 - size of the input N

USEFUL RULES FOR BIG-O
If ann algo's execution time is N62 + N then it is said to be O(N^2)
When adding algo complexcities, the alrger avlue dominates.

log_k(x) = O(x)

Loops: at most the running time of the statements inside the loop times the nmebr of iterations
Nested loops: n^2
consecute statements: just add
*/

//LOOK AT THE TWO FILES FO INTCELL on bb
