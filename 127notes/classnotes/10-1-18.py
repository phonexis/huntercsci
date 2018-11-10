##def collatz(n):
##    """
##    if n = 1 stop
##    otherwise
##    if n is odd -->3n+1
##    if n is even --> n/2
##    until n becomes
##    """
##    i = 0
##    while n != 1:
##        #do the calculation
##        print(n)
##        if n % 2 == 0: #even
##            n = n / 2
##        else: #odd
##            n = 3 * n + 1
##        i = i + 1
##    print(n)
##    return i
##collatz(9)

##def calc_new_guess(n,oldguess):
##    newguess = (oldguess + (n / oldguess)) / 2
##    return newguess
##def mysqrt(n):
##    guess = 1
##    while abs((guess*guess)-n) > .001:
##        guess = calc_new_guess(n,guess)
##    return guess
##i = 1
##while i <= 25:
##    print(i, ":", mysqrt(5))
##    i = i + 1

#Lists in python
#l = [] <- Empty list
##empty_list = []
##l = [5, 3, 10, 21, 19.7]
##l2 = [10, True, "HI", 3.5, 20]
##l3 = []
##s = "Hello World"
##s[4] #the other instance we use a square bracket
##
###you can index , slice, and add lists just like arrays
##
##print(len(l))
##print(l2)
##l2[2] = "New string" # you can reassign a list value
###s[2] = 'a' <-- you can't do this to a string
##
##print(l2)
##
##l3.append(1) #.append adds to the list
##l3.append("word")
##l3.append(l2)
##print("l3:",l3)
##
##l4 = l3 + l2
##print("Changing l2[1] to a Z")
##l2[1] = "Z"
##print("l2:",l2)
##print("l4:", l4)
##
##l2.insert(3, "I've been inserted") #l2.insert(3rd stored, what is being stored)
##print("l2:", l2)
##l2.remove(10) # removes the first occurance of 10
##print("l2:", l2)
##l2.pop()
##print("l2:", l2)

import random
random.randrange(5, 10) #random number from range 5 to 10
def build_random_lists(items):
    """
    create and return a list filled with items number of element
    each element should be a random integer value
    between 0 an 99
    """
    l = []
    i = 0
    while i < items:
        #l.append(random.randrange(0,max_value))
        l = l + [random.randrange(0,100)] #the brackets allow foe the two to be combined
        #only lists + lists
        i = i + 1
##    while True:
##        a = random.randrange(0,99)
##        l.append(a)
##        if len(l) == items:
##            break
    return l
print(build_random_lists(3))