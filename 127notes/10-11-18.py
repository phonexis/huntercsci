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
l = build_random_list(15,100)
print(l)
print(locate(l,10))
print(locate(l,l[4]))

def locate2(l,value):
    if value in l: #n time/linear time = you do something an n amount of times
        return l.index(value)
    else:
        return -1
print(locate2(l,10))
print(locate2(l,l[4]))