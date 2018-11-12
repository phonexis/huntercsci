def clean_data(s):
    result=""
    punct = "',:!?."
    for letter in s:
        if letter in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
            result = result + letter.lower()
        else:
            result = result + " "
    for letter in result:
        if letter in punct:
            result = result + s.replace(letter,'')
        else:
            continue
    return result

def next(string):
    d={}
    s = string.split()
    for i in range(0,len(s)-1):
        d.setdefault(s[i],[])
        d[s[i]].append(s[i+1])
    return d
def testing(filename):
    f = open(filename)
    s = f.read()
    f.close
    print(s)
    return next(clean_data(s))
filename = "/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"
filename1 = "/home/fang/fall-2018-127/classcode/dictionaries/moby-small.txt"
print(testing(filename))
print(testing(filename1))
