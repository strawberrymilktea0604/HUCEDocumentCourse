# -*- coding: utf-8 -*-
"""
Created on Thu Jun  1 09:56:21 2023

@author: minhk
"""

def f(x):
    return x ** 2

int2 = map(f, range(10))
print(list(int2))



print(map(lambda x: x **2, range(10)))


def lonhonhoacbang5(x):
    if x >= 5:
        return True
    else:
        return False
    
a = filter(lonhonhoacbang5, range(20))
print(list(a))

from functools import reduce
def f(x, y):
    print("Called with x={}, y={}".format(x,y))
    return x + y

a = reduce(f, [1, 3, 5], 9)
print(a)