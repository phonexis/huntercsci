import random

def build_random_list(num_items, max_value):
    l=[]

    for i in range(num_items):
        l = l + [ random.randrange(0,max_value) ]
    return l

def index_largest(l):
    li = 0
    for i in range(1,len(l)):
        if l[i] > l[li]:
            li = i
    return li

def freq(l,item):
    count = 0
    for i in l:
        if i ==tem:
            count +=1
    return count
l = build_random_list(30,100)
li = index_largest(l)
print(l)
print(li,l[li])
l[20]=5000
l[25]=5000
li = index_largest(l)
print(li,l[li])
