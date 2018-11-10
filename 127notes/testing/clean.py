def build_word_counts(string):
    d={}
    for word in string.split():
        d.setdefault(word,0)
        d[word]=d[word]+1
    return d

def testing(filename):
    f = open(filename)
    s = f.read()
    cleaned = clean(s)
    return build_word_counts(cleaned)


newfilename = "//home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"
n = open(newfilename)
o = n.read()

def clean(s):
    result = ''
    for letter in s:
        if letter in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
            result = result + letter.lower()
        else:
            result = result + " "
    for letter in result:
        if letter == "'":
            result = result + s.replace("'",'')
        elif letter == ",":
            result = result + s.replace(",",'')
        elif letter == ":":
            result = result + s.replace(":",'')
        else:
            continue
    return result

#print(testing("/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"))
print(testing("/home/fang/fall-2018-127/classcode/dictionaries/moby.txt"))
