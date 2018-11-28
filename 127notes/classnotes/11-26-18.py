def make_acronym(ine):
    result = ""
    for word in line.split():
        result = result + word[0]
    return result
def rle1(line):
    encoded = []
    i = 0
    while i < len(line)-1:
        next_letter = i+1
        encoded.append([next_letter-i,line[i]])
        i = next_letter
        while next_letter < len(line) and line[next_letter] == line[i]:
             next_letter = next_letter + 1
    if i == len(line)-1:
        encoded.append([1,line[i]])
    return encoded

print(rle1("aaaabb"))
print(rle1("bbbaaaabb"))
print(rle1("abcd"))
print(rle1("cbbbbdee"))

def rle2(line):
    encoded = []
    count = 1
    prevchar = line[0]
    for c in line[1:]:
        if c ==prevchar:
            count = count + 1
        else:
            encoded.append([count,prevchar])
            count  = 1
            prevchar = c
    encoded.append([count,prevchar])
    return encoded
print(rle2("aaaabb"))
print(rle2("bbbaaaabb"))
print(rle2("abcd"))
print(rle2("cbbbbdee"))

def decode(encoded):
    result = ""
    for item in encoded:
        result = rsult +item[0]*item[1]
    return result

composite_scores = {['A','E','I','O','U','L','N','R','S','T']:1}
def score1(word,scores):
    score = 0
    for letter in word:
        for k in scores:
            if letter in k:
                score = score + scores[k]
    return score

def score2(word,scores_raw):
    scores = {}
    for k in scores_raw:
        for letter in k:
            scores[letter] = scores_raw[k]
    score = 0
    for letter in word:
        score = score+scores[letter]
    return score
##Python = scripting and interpreter language (doesn't deal with memory/made for quick writing)
##C++ = lower level and compiler language (runs much faster because it doesn't translate/industrial strength)
## ___.cpp == C++ files
