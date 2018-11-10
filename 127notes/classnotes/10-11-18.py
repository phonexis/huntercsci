import random

def build_random_list(size,max_value):
    """
    Parameters:
      size : the number of elements in the lsit
      max_value : the max random value to put in the list
    """
    l = [] # start with an empty list

    # make a loop that counts up to size
    i = 0
    while i < size:
        l.append(random.randrange(0,max_value))
        # we could have written this instead of the above line:
        # l = l + [random.randrange(0,max_value)]
        i = i + 1
    return l

def locate(l,value):
    i = 0
    found_index = -1
    while i < len(l):
        if l[i] == value:
            found_index = i
            break # breaks out of the current loop
#            return found_index
#            print("FOUND")
#        print(value,i,l[i])
        i+=1
    return found_index


def locate2(l,value):
    if value in l: #n time/linear time = you do something an n amount of times
        return l.index(value)
    else:
        return -1
def locate_for(l,value):
    found_index = -1
    for i in range(len(l)):
        if l[i] == value:
            found_index = i
            break
    return found_index

def count(l,value):
    i = 0
    found_count = 0
    while i < len(l):
        if l[i] == value:
            found_count = found_count +1
        i = i +1
    return found_count

def reverse(l):
    reversed = []
    i = len(l) - 1
    while i >= 0:
        reversed.append(l[i])
        i -= 1
    return reversed
der reverse_for(l):
    for i in range(len(l)-1,-1,-1):
        

##def r2():
##    reversed = []
##    i = 0
##    while i < len(l):

def isPalindrome(l):
    l2 = reverse(l)
    return l == l2

def isIncreasing(l):
    increasing = True
    i = 0
    while i < len(l):
        if l[i] >= l[i+1]:
            increasing = False
            break
        i = i + 1
    return increasing

l = build_random_list(15,100)
l2 = build_random_list(200,50)
print(l)
print(locate(l,10))
print(locate(l,l[4]))
print(locate2(l,10))
print(locate2(l,l[4]))
print(l2)
print(count(l2,l2[4]))
print(reverse(l))
print(isIncreasing(l))

#FOR LOOP
# for v in sequence:
#a sequence is a list or string as of right now
for i in [1, 5, "Hello"]:
    print(i)
for i in "Hello World":
    print(i)
for i in range(5):
    print(i)
for i in range(5,15):
    print(i)
for i in range(5,15,2):
    print(i)
for i in range(5,15,-1):
    print(i)