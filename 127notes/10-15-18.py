l = [1,2,3,4,5,6,5,4,3,2,1]

def mapsq(l):
    result = []
    for item in l:
        result = result+[item*item]
    return result
print(mapsq(l))

def mapsq_while(l):
    result = []
    i = 0
    while i < len(l):
        result.append(l[i]*l[i])
        i = i + 1
    return result
print(mapsq_while(l))

def filter_odd(l):
    result = []
    for item in l:
        if item % 2 !=0:
            result.append(item)
    return result
print(filter_odd(l))

def filter_even(l):
    result = []
    for item in l:
        if item % 2 ==0:
            result.append(item)
    return result
print(filter_even(l))

def is_odd(n):
    return n%2==1

def is_even(n):
    return n%2==0

def is_big(n):
    return n>5

def myfilter(predicate, l):
    result = []
    for item in l:
        if predicate(item):
            result.append(item)
    return result
print(myfilter(is_odd,l))
print(myfilter(is_even,l))
print(myfilter(is_big,l))

def mymap(f,l):
    result = []
    for item in l:
        result.append(f(item))
    return result

def cube:
    return n*n*n
def is_name(word):
    return word[0] == word[0].upper()
sentence = "when shall we three meet again"
wl=sentance.split()

pl_sentence = " ".join(mymap(piglatinfy,sentence.split()))

spacestring = "hello"