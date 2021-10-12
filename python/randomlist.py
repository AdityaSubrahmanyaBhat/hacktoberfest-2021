#Program to randomize the order of the values of a list and return a new list

from copy import deepcopy
from random import randint

def shuffleList(list):
    temp_list = deepcopy(list)
    n = len(temp_list)
    while (n):
        n = n-1
        i = randint(0, n)
        temp_list[n], temp_list[i] = temp_list[i], temp_list[n]
    return temp_list
nos = [1,23,456,7890]
print("Original list: ", nos)
print("SHUFFLING.....")
print("After shuffling: ")
print(shuffleList(nos))
#end