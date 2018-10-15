#Prints a month in a given range of strings
for amonth in ["January", "February", "March"]:
    print("One of the months of the year is " + amonth)
    
print(list(range(0, 20, 2))) #even numbers  rang(start, beyondLast, step)
def only_even(a):
    if a in range(0, 20, 2):
        return True
    if a in range(1, 20, 2):
        return False
print(only_even(19))

import math #MATH MODULE
print(math.sqrt(144))
print(math.pi)
print(math.e)
print(math.sin(math.radians(90)))

import random #RANDOM MODULE
prob = random.random()
print(prob)
diceThrow = random.randrange(1, 7)       # return an int, one of 1,2,3,4,5,6
print(diceThrow)

import turtle #import turtle
wn=turtle.Screen()
alex=turtle.Turtle()
for i in range(4): #draw square
    alex.forward(90)
    alex.left(90)
wn.exitonclick()
