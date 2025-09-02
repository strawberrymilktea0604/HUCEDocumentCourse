# -*- coding: utf-8 -*-
"""
Created on Sat May  6 10:51:41 2023

@author: minhk
"""


mofile = open('shopping.txt', 'r')
lines = mofile.readlines() 
mofile.close() 

xuatfile = open('shopping_cost.txt', 'tw')
for line in lines:
    word = line.split()
    itemname = word[0]
    number = int(word[1])
    cost = float(word[2])
    total =  number * cost 
    xuatfile.write("{:20} {}\n".format(itemname, total))
xuatfile.close()
    
    
    
    