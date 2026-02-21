# -*- coding: utf-8 -*-
"""
Created on Tue May  9 07:39:29 2023

@author: minhk
"""

mofile = open("test2.txt", 'r')
lines = mofile.readlines()
mofile.close()


n = i + 1
for line in lines:
    k = line.split(';')
    k.sort(reverse=True)
    for n in range(len(k)):
        print(k[n])
        
