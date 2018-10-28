def string_splosion(str):
    i = 0
    new_string = ""
    while i < len(str):
        new_string = new_string + str[:i+1]
        i+=1
    return new_string

def array_count9(array):
    count = 0
    for i in array:
        if i == 9:
            count+=1
    return count
print(array_count9([1,2,9]))

def array_front9(array):
    count = 0
    for i in array[:4]:
        if i == 9:
            count+=1
    return count
print(array_front9([1,9,9,3,4,9]))