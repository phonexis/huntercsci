#this is a comment
#print('hello')

a= 10
b= 2*a
print(a,b)
a= 30
print(a,b)

#a = b
# '=' is assignment -> evaluate the right hand side and store it in the variable
#represented by the left hand side
# an identifier is something we can give a name to/ we are storing information
#such that we can use the identifier to pull up the value or information


#print() prints
#len() length of a word but it cannot measure the length of numbers

#def identifier(params):
def add_one(x) :
    """
    this is a docstring that can describe the function.
    plug in an input in as x to recieve the following output of the function
    """
    c = x
    
    #print("You sent in", x)
    #it is important to be wary of indentation in python
    #c = c+ 1
    x = x + 1
    # ^ this line makes it such that you cannot input strings
    #print('Now x is', x)
    #Variables created in the function are only usable in the function. The variables are called LOCAL VARIABLES.
    #They are created each time you call or use the function and are destroyed when the function returns.
    #Arguemnts orparameters are like local variables but they get values from the function caller each time the function is called or used.
    return c
    #return sends it back within the program
c = 20
print(c)
c = add_one(c)
print(c)
#Functions take something in and send soemthing back. Printing is putting something on the screen.
#
print ("This line isn't indented anymore")

def sub_two(a,b):
    return a-b

def greeter(name):
    """
    greeter("Steve") --> "Hello Steve!")
    greeter("Dana") --> "Hello Dana!")
    """
    result= "Hello", name , "!"
    return result
def greeter2(name,greeting):
    return greeting + " "+name+"!"
    #the name needs to be surrounded by quotation marks
print(greeter("Steve"))
print(greeter2("Bob", "Welcome"))
s=greeter2("San", "Howdy")
print(s)
s=greeter2(s,
