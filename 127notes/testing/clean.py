##def build_word_counts(string):
##    d={}
##    for word in string.split():
##        d.setdefault(word,0)
##        d[word]=d[word]+1
##    return d
##
##def clean(s):
##    result = ''
##    punct = "',:!?."
##    for letter in s:
##        if letter in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
##            result = result + letter.lower()
##        else:
##            result = result + " "
##    for letter in result:
##        if letter in punct:
##            result = result + s.replace(letter,'')
##        else:
##            continue
##    return result
##
##def max_count(filename):
##    f = open(filename)
##    s = f.read()
##    cleaned = clean(s)
##    count = build_word_counts(cleaned)
##    vals = count.values()
##    vals = sorted(vals)
##    common_words = [ [k,count[k]] for k in count if count[k] > 50 ]
##    return common_words
##
##
##print("-------------------")
##def thousand(filename):
##    common_words = []
##    f = open(filename)
##    s = f.read()
##    cleaned = clean(s)
##    count = build_word_counts(cleaned)
##    for k in count:
##        if count[k] > 1000:
##            common_words.append[k]
##    return common_words


##newfilename = "/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"
##n = open(newfilename)
##o = n.readlines()



####print(max_count("/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"))
####print(max_count("/home/fang/fall-2018-127/classcode/dictionaries/moby-small.txt"))
##print(max_count("/home/fang/fall-2018-127/classcode/dictionaries/moby.txt"))
##print(thousand(max_count("/home/fang/fall-2018-127/classcode/dictionaries/moby.txt")))

####x for x in l if x%2 == 0 #List comprenhension-> x for x in ___ [if____]-optional
####"hello" for number in range(5,20,5)
####[number,number**2] for number in range(5,20,5)

def build_word_counts(words):
    d={}
    for word in words.split():
        d.setdefault(word,0)
        d[word]=d[word]+1
    return d

def clean_data(s):
    result=""
    for letter in s:
        if letter in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
            result = result + letter.lower()
        else:
            result = result + " "
    return result

filename="/home/fang/fall-2018-127/classcode/dictionaries/moby-small.txt"

f = open(filename)
s = f.read()
#words_uncleaned = build_word_counts(s)
#print(words_uncleaned)
###print("-------------------")
cleaned_string = clean_data(s)
words = build_word_counts(cleaned_string)
vals = words.values()
vals = sorted(vals)
###print('------')
###common_words = []
###for k in words:
###    if words[k] > 1000:
###        common_words.append([k,words[k]])
##
common_words = [ [k,words[k]] for k in words if words[k] > 50 ]
print(common_words)
