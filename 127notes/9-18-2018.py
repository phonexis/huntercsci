#PART_PIG_LATIN
#def part_pig_latin(name):
    #"""
    #Input: A string that is a single lower case word
    #Returns: that string in fake pig latin -> move the first letter of the word to the end and add "ay"
    #so: "hello" --> "ellohay"
    #"""
    #first_letter = name[:1]
    #mid_letter = name[1:len(name)-1]
    #last_letter = name[len(name)-1:len(name)]
    #pig_latin = last_letter + mid_letter + first_letter + "ay"
    #return pig_latin
#print(part_pig_latin("Hello"))
#print(part_pig_latin("Mary"))

def capitalize_name (name):
    """
    input: name --> a string in the form "first last"
    output: returns a string with each of the two words capitalized
    """
    space_index = name.find(" ")
    first = name[0:space_index]
    last = name[space_index+1:]
    capitalized = first.title() + " " + last.title()
    return capitalized
print(capitalize_name("james bond"))

print("This is before the if / conditional")
if True:
    print("This always executes")
    print("Multiple lines can execute if the boolean condition")
    print("Is true as long as they're all indented the same")
print("This is outside all if statements")
if False:
    print("This never executes")
print("This is after te if / conditional")
if 5>3: #appears becuase it is true
    print("the above boolean is true")
if 5!=5: # does not appear because 5!=5 is False
    print("Hello")
if 5==5:
    print("Hi")

#name = "Joe" #Does not wor b/c Joe and joe are not the same
#if name=="joe"
#    print("Hi Joe")

name = "Joe"
if name.upper()=="joe".upper():
    print("Hi Joe")

if False==False:
    print("this is tricky")

import random

name= "Joe"
age=20
if name== "Joe" and age>18:
    print("It's JOe and he's over 18")

number = random.randrange(10)
print("Number = ", number)
if number >= 5:
    print("number is greater than 5:", number)
if number < 5:
    print("Number is less that 5:", number)

if number >=5:
    print("Number is >= than 5 with an else:", number)
else:
    print("Number is less that 5 with an else:", number)
    
if number > 7:
    print("Number > 7", number)
elif number > 4:
    print("Number: 4", number)
else:
    print("Number<= 4", number)
    

#PIG_LATIN
def pig_latin(name):
    """
    Input: A string that is a single lower case word
    Returns: that string in fake pig latin -> move the first letter of the word to the end and add "ay"
    so: "hello" --> "ellohay"
    """
    word = name.lower()
    firstl = word[0]
    if firstl == "a" "e" "i" "o" "u":
        return word +"ay"
print(pig_latin("Hello"))
print(pig_latin("Mary"))
