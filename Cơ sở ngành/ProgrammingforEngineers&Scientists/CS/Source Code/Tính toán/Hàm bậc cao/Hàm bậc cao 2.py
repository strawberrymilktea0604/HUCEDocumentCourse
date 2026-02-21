# -*- coding: utf-8 -*-
"""
Created on Tue May 16 08:29:08 2023

@author: minhk
"""

def print_f_table(f):
    for i in range(6):
        x = i * 0.5
        print("{} {}".format(x, f(x)))
        
def square(x):
    return x ** 2

def cubic(x):
    return x ** 3

print_f_table(square)
print_f_table(cubic)