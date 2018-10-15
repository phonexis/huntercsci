def bondify(name):
    """
    takes in the form "first last" and returns it in the form "last, first last"
    """
    space_index = name.find(" ")
    first  = name[0:space_index]
    last = name[space_index+1:]
    bond_name = last + ", " + first + " " + last
    return bond_name

def capitalize_name(name):
    """
    name -> a string in the form "first last" all lower case
    returns -> the sting with both names capitalized
    ex: capitalize_name("james bond") --> James Bond
    """
    Big = name.capitalize(name)
    capitalize(name)
    return capitalize_name()
print(capitalize_name("nathan"))
print(bondify("Hello World"))

s = "Hello World"

#World, Hello World



print("s = " + s) # adding two string to print the argument
print("Access the first character: ", s[0]) #printing two separate strings
#s[0]="Z" #this is illegal - you can't change a string
