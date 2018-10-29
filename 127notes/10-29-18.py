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
        if i == item:
            count +=1
    return count

def req2(l,item):
    count = 0
    for i in range(len(l)):
        if l[i] == item:
            count += 1
    return count

def mode(l):
    """
    Look at current item, check it, move to the next
    """
    msf_value = l[0]
    msf_freq = freq(l,l[0])
    msf_index = 0
    for i in range(len(l)):
        test_freq = freq(l,l[i])
        if test_freq>msf_freq:
            #print("FOUND NEW POSSIBLE MODE:")
            #print("old mode: ",msf_value,"old_freq: ",msf_freq,"old_location: ",msf_index)
            #print("new mode: ",l[i],"new_freq: ",test_freq,"new_location: ",i)
            msf_value = l[i]
            msf_index = i
            msf_freq = test_freq
    return msf_value
l = build_random_list(30,100)
li = index_largest(l)
print(l)
print(li,l[li])
l[20]=5000
l[25]=5000
li = index_largest(l)
print(li,l[li])
mode_test_list = [9,3,3,8,2,8,6,7,8,4,8]
print(mode(mode_test_list))
l_new = build_random_list(30,100)

#RUN TIME ANALYSIS-HOW FAST MY STUFF ILL RUN
#SPACE ANALYSIS- HOW MUCH SPACE OR DISK SPACE I ENED FOR MY ALGORITHM
#LINEAR ALGORITHM (predictable(y=x)) => N -> N (spec -> does this many things)
#python is one of the slowest programming languages known to mankind
base_size = 10000
for i in range(1,7):
    new_l = build_random_list(10**i,100)
    start_time = int(round(time.time() * 1000))
    m = mode(l_new)
    running_time = int(time.time() * 1000 - start_time)
    print("Len: ",len(l_new),"mode: ",m,"running time: ",running_time)
#frequency is a linear operation/component for each item in mode
    