# -*- coding: utf-8 -*-
"""
Created on Tue Apr  4 07:26:35 2023

@author: minhk
"""

m = int(input("Nhap hang: "))
n = int(input("Nhap cot: "))


matran = []


for i in range(m):
    matran.append([]) 
    for j in range(n):
        tmp = int(input(f"Ban hay nhap vao hang [(i)] cot [(j)]: ")) 
        matran[i].append(tmp) 
        
k = int(input(f"So phan tu can tim: "))
    


for i in range(m):
    for j in range(n):
        
        if matran[i][j] == k:
            print(f"vi tri hang [(i)] cot [(j)] co gia tri bang k: " )
        