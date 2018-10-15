l = [1,2,3,4,5,6,7,8]

def filter(l):
    newl = [] #empty list for the odd #s
    for i in l: #loops through l
        if i % 2 == 1: #checks if the value in the list is odd
            newl.append(i) # adds the value if i is odd
    return newl #return the new list
    
print(filter(l)) #FILTER TEST

l =[4,2,5,3,5]

def mapsquare(l):
    newl = [] #empty list for the odd #s
    for i in l: #loops through l
        square = i**2 #assigns square to i raised to the 2nd power
        newl.append(square) #appends the squared value to the new list
    return newl #returns the new list

print(mapsquare(l)) #MAPSQUARE TEST