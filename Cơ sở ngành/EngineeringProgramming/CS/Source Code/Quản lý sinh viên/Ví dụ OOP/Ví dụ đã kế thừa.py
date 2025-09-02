# -*- coding: utf-8 -*-
"""
Created on Tue Jun  6 08:20:01 2023

@author: minhk
"""

class Calculation1:
    def Summation(self, a, b):
        return a + b
    
class Calculation2:
    def Multiplication(self, a, b):
        return a * b
    
class Devired(Calculation1, Calculation2):
    def Divide(self, a, b):
        return a/b
    
d = Devired()
print(d.Summation(10, 20))
print(d.Multiplication(10, 20))
print(d.Divide(10, 20))

print("Devired la con cua Calculation2: ", issubclass(Devired, Calculation2))
print("Calculation1 la con cua Calculation2: ", issubclass(Calculation1, Calculation2))
print("Doi tuong d la the hien cua lop Devired: ", isinstance(d, Devired))