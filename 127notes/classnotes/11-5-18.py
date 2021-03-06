##DICTIONARIES
##key value look up
l = [1,2,'Hello',.34]
d={}
d['key1'] = "hello"
d['name'] = "Horatio Hornblower"
d[0] = 'hello world'
d[5] = 26
d['float'] = 123.456
#you cannot put a list or another dictionary as the key to a dictionary
d['x'] = [5,2,3,1,4]
print(d)
#you can put pretty much anything and pull pretty much anything into or from a dictionary
person1 = {'name':'tom', 'age':22}
person2 = {'name':'sally', 'age':18}
person3 = {'name': 'sue', 'age': 20}
people = {'tom': person1, 'sally':person2}
myage = 19
myname= 'albert'
people['sue'] = person3
people['albert'] = {'name':myname, 'age':myage}
print(people)
#D.keys() returns a list of the key values in dictionary D, in no particular order
#D.values() Returns a list of the values from key-value pairs in dictionary D, in no particular order.
#However, if you call both the .items() and .values() methods of a dictionary without changing that dictionary's contents between those calls,
#Python guarantees that the ordering of the two results will be the same.
for k in sorted(people.keys()):
    """
    if you want your keys to be in order, you have to sort tha tout yourself
    """
    print(k)
for k in people.keys():
    print('people.keys:', k)
for k in people:
    print('people: ', k)
print("----------------")
for k in sorted(people):
    print(k," is ", people[k]['age']," years old")
print("--------------------")
for k,v in sorted(people.items()):
    print(k, ' is ',v['age'])

import random

names = ['lisa','bart','marge','homer','barney','moe','carl','smithers']

def generate_votes(name,number_votes):
    votes = []
    for i in range(number_votes):
        votes.append(random.choice(names))
    return votes
    
def winner(names,votes):
    tallies = {}
##    for n in names:
##        tallies[n] = 0
##    print(tallies)
##D.setdefault('a',100) #if it doesn't exist, put in this value. if it does, don't do anything = .setdefault() 
    
    for vote in votes:
        tallies.setdefault(vote,0)
        tallies[vote] = tallies[vote]+1
    final_votes = tallies.values()
    print(final_votes)
    max_vote_count = max(tallies.values())
    print(tallies)
    print(max_vote_count)
    
    winners = []
    for k,v in tallies.items():
        if v== max_vote_count:
            winners.append(k)
        
    print(winners)
votes = generate_votes(names,30)

print(winner(names,generate_votes(names,30)))

#assignment use dictionary to revise apples,lady, and madlibs