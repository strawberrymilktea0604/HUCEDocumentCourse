# -*- coding: utf-8 -*-
"""
Created on Tue Mar 14 08:55:36 2023

@author: minhk
"""

a = 3
b = 3 
c = 3 

def Tong2canhab(a,b):
    return a + b 

def Tong2canhac(a,c):
    return a + c 

def Tong2canhbc(b, c): 
    return b + c 

def Canhbinha(a): 
    return a**2
def Canhbinhb(b): 
    return b**2
def Canhbinhc(c): 
    return c**2 
    
def Tong2canhbinhphuongab(a, b) :
    return Canhbinha(a) + Canhbinhb(b) 
def Tong2canhbinhphuongbc(b, c) :
    return Canhbinhb(b) + Canhbinhc(c)
def Tong2canhbinhphuongac(a, c) :
    return Canhbinha(a) + Canhbinhc(c) 
    
    
    
    
if Tong2canhab(a, b) > c or Tong2canhac(a,c) > b or Tong2canhbc(b, c) > a:
    print("Day la mot tam giac")
    if Tong2canhbinhphuongab(a, b) == Canhbinhc(c) or Tong2canhbinhphuongbc(b, c) == Canhbinha(a) or Tong2canhbinhphuongac(a, c) == Canhbinhb(b) :
        print("Day la mot tam giac vuong") 
    else:
        print("Day khong phai la tam giac vuong") 
        if a == b and b == c:
            print("Day la mot tam giac deu")
            
        else:
            print("Day khong phai la tam giac deu, day la tam giac binh thuong") 
else:
    print("Day khong phai la mot tam giac") 
    
 