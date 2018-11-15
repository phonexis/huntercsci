#python is a really slow language to use
#IDE-integrated development environment
#most IDEs utilize a single language
#jetbrains-clean fast debugging help (Pycharm-free for educational and open source use)
#editor can do alot of different things in it rather than rotating between tools for projects
#eclipse is big for java (big & bloated)
#open source editors are freely available while closed source editors are commercially sold

##
##def build_word_list(words):
##    d = {}
##    #we know we want to look at words 2 at a time
##    words = words.split()
##    for in range(0,len(words)-2):
##        d.setdefault(words[i],[])
##        d[words[i]].append(words[i+1])
##    return d
##
##
##def build_word_list_next(words):
##    d = {}
##    #we know we want to look at words 2 at a time
##    words = words.split()
##    prev = word[0]
##    for nextword in words[1:]:
##        d.setdefault(prev,[])
##        d[prev].append(nextword)
##        prev = nextword
##    return d
##
##          
##filename = '/home/fang/fall-2018-127/classcode/dictionaries/moby-small.txt'
##f = open(filename)
##s = f.read()
##
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

def build_word_lists_by_index(words):
    d={}
    words = words.split()
    for i in range(0,len(words)-2):
        d.setdefault(words[i],[])
        d[words[i]].append(words[i+1])
    return d

def build_word_lists(words):
    #TUPLE
    d={}
    words = words.split()
    first = words[0]
    second = words[1]
    for nextword in words[2:]:
        key = (first,second)
        d.setdefault(key,[])
        d[key].append(nextword)
        first = second
        second = nextword
    return d

import random
"""
bygrams- looking at two words at a time
we can use multiplewords at a time
"""
def gen_text(wl,number,tuple):
    start = tuple[0]
    second = tuple[1]
    text = []
    for i in range(number):
        text.append(start)
        next = random.choice(wl[tuple])
        tuple = (second,next)
    return ' '.join(text)


filename="/home/zamansky/gh/fall-2018-127/classcode/dictionaries/moby-small.txt"

f = open(filename)
s = f.read()
story = gen_text(wl,100,s.split()[10])
#print(story)
#words_uncleaned = build_word_counts(s)
#print(words_uncleaned)
#print("-------------------")
cleaned_string = clean_data(s)
#words = build_word_counts(cleaned_string)
#vals = words.values()
#vals = sorted(vals)
#print('------')
#common_words = []



filename="/home/zamansky/gh/fall-2018-127/classcode/dictionaries/moby-small.txt"

f = open(filename)
s = f.read()
s = clean_data(s)
slist = s.split()
wl = build_word_lists(s)
print(wl)
prit(gen_text(wl,100,(slist[0],slist[1])))

#words_uncleaned = build_word_counts(s)
#print(words_uncleaned)
#print("-------------------")
cleaned_string = clean_data(s)
words = build_word_counts(cleaned_string)
vals = words.values()
vals = sorted(vals)
#print('------')
#common_words = []
#for k in words:
#    if words[k] > 1000:
#        common_words.append([k,words[k]])

#common_words = [ [k,words[k]] for k in words if words[
#for k in words:
#    if words[k] > 1000:
#        common_words.append([k,words[k]])

#common_words = [ [k,words[k]] for k in words if words[k] > 50 ]
