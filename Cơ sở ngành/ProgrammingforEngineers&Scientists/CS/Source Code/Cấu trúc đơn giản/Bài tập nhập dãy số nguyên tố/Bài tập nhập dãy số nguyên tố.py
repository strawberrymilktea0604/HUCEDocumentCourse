# -*- coding: utf-8 -*-
"""
Created on Tue Apr  4 01:41:59 2023

@author: minhk
"""

def songuyento(n):
    if n < 2:
        return False
    
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

n = int(input("Nhap so phan tu cua day so: "))
daysonguyento  = [] 
for i in range(n):
    val = int(input("Nhap mot so: "))
    daysonguyento.append(val) 

print(daysonguyento) 