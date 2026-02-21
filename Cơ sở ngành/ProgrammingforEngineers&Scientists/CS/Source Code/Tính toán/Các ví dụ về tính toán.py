# -*- coding: utf-8 -*-
"""
Created on Sat May 27 09:52:23 2023

@author: minhk
"""

a = [2 ** i for i in range(10)]
print(a)

xs = [i for i in range(10)]
print(xs)
ys = [x ** 2 for x in xs]
print(ys)

import math
xs = [0.1 * i for i in range(5)]
print(xs)
ys = [math.exp(x) for x in xs]
print(ys)

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
    
print(factorial(15)) 

def f(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return f(n - 2) + f(n - 1)
    
print(f(4))