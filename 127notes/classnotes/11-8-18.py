##def happy(s):
##    if '_' not in s:
##        for i in range(0,len(s)-1):
##            if s[i] != s[i-1] and s[i] != s[i+1]:
##                return False
##        return True
##    else:
##        s = s.replace("_","")
##        counts = {}
##        for bug in s:
###            if bug in counts.keys():
###                counts[bug] = counts[bug] + 1
###            else:
###                counts[bug]=1
###            print(s)
###            print(counts)
###            return False
##            counts.setdefault(bug,0)
##            counts[bug] = counts[bug]+1
##            return not(l in counts.values())
###        if l in counts.values():
###            return False
###        else:
###            return True
##    return True
##testcases = ['abcdea', 'abccde','abd_def','abc__cddeba','abc_abcd_abc_']
##
##for test in testcases:
##    print(test)
##    print(happy(test))
##
##def happy2(s):
##    if '_' not in s:
##        for i in range(1,len(s)-1):
##            if s[i] != s[i-1] and s[i] != s[i+1]:
##                return False
##        if s[0] != s[1] or s[len(s)-1] != s[len(s)-2]:
##            return False
##        return True
##    else:
##        s = s.replace("_","")
##        s = sorted(s)
##        for i in range(1,len(s)-1):
##            if s[i] != s[i-1] and s[i] != s[i+1]:
##                return False
##        if s[0] != s[1] or s[len(s)-1] != s[len(s)-2]:
##            return False
##        return True
##    
def build_word_counts(words):
    d={}
    for word in words.split():
        d.setdefault(word,0)
        d[word]=d[word]+1
    return d

#s = "one two three four five four six three seven three two three eight nine"
#d=build_word_counts(s)
#print(d)

# you should only need filename="macbeth.txt"
filename="/home/fang/fall-2018-127/classcode/dictionaries/macbeth.txt"
f = open(filename)
# we can read the whole thing
s = f.read()
##print(s)
##f.close()
##print("-------")
### or we can read a line at a time.
##f = open(filename)
##s = f.readline()
##print(s)
##s = f.readline()
##print(s)
##f.close()
##print('------')
##f = open(filename)
for line in f.readlines():
    print(line)

words = build_word_counts(s)
print(words)
def clean_data(s):
    result = ''
    for letter in s:
        if letter in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
            result = result + letter.lower()
        else:
            result = result + " "
words_uncleaned = build_word_counts
cleaned_string = clean_data(s)
print("----------------------------------")
words = build_word_counts(cleaned_string)
#go to project gutenberg, pull down a book (not a play) [plaintext],
#cut off the stuff from the top and bottom, clean it so you get reasonable results
print(word)