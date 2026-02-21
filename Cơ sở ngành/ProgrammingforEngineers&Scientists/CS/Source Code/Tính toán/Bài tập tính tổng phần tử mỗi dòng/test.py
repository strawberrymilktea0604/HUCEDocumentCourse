# -*- coding: utf-8 -*-
"""
Created on Tue May  9 02:36:18 2023

@author: minhk
"""

def print_line_sum_of_file(filename):
    mofile = open("test.txt", 'r')
    lines = mofile.readlines()
    print(lines)
    mofile.close()
    
    for line in lines:
        tongsophantungdong = 0
        tungsophantu = line.split()
        for i in tungsophantu:
            tongsophantungdong += int(i)
        print("Tong cac so phan tu moi dong la: ")
        print(tongsophantungdong)


print_line_sum_of_file("test.txt")