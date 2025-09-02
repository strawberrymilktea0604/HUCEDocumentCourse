# -*- coding: utf-8 -*-
"""
Created on Tue May 23 08:32:55 2023

@author: minhk
"""

def area(a, b=1):
    return a * b

print("The area is {}".format(area(3)))
print("The area is {}".format(area(2.5)))
print("The area is {}".format(area(2.5, 2)))

def f(a, b, c):
    print("a = {}, b = {}, c = {}".format(a, b , c))
    
f(1, 2, 3)
f(c= 3, a=1, b=2)
f(1, c=3, b=2)


def trapez(function, a, b, subdivisions=100):
    pass

import math
int1 = trapez(a=0, b=1, function=math.sin)
int2 = trapez(b=0, function=math.exp, subdivisions=1000, a=-0.5)