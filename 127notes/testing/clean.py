def build_word_counts(string):
    d={}
    for word in string.split():
        d.setdefault(word,0)
        d[word]=d[word]+1
    return d

def testing(filename):
    f = open(filename)
    s = f.read()
##    print(s)
    cleaned = clean(s)
    f.close()
    return build_word_counts(cleaned)

newfilename = "/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"
n = open(newfilename)
o = n.readlines()

def clean(s):
    result = ''
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

print(testing("/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"))
print(testing("/home/fang/fall-2018-127/classcode/dictionaries/moby-small.txt"))
##print(testing("/home/fang/fall-2018-127/classcode/dictionaries/moby.txt"))