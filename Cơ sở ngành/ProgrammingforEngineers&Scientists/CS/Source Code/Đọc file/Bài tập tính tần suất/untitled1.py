# -*- coding: utf-8 -*-
"""
Created on Thu May 18 10:39:15 2023

@author: minhk
"""

f = open("tansuat.txt", 'r')
lines = f.readlines()
f.close()

for line in lines:
    k = line.split()
    sortedWord = sorted(k)
    demchu = set(k)
    print(sortedWord)
    for i in demchu:
        print(k.count(i))
        
        #dung tu dien