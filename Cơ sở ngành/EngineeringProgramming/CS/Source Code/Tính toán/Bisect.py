# -*- coding: utf-8 -*-
"""
Created on Tue May 30 08:12:12 2023

@author: minhk
"""

from scipy.optimize import bisect


def f(x):
    return x ** 4 - 4 * x ** 3 + 8 * x - 5

for i in range(-10, 10):
    print(i,f(i))
    
    
print(bisect(f, -2, -1))