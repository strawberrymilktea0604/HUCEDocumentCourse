# -*- coding: utf-8 -*-
"""
Created on Sat May 13 10:50:48 2023

@author: minhk
"""

import sys
try:
    f = open('test.txt', 'r')
except FileNotFoundError:
    print("The file couldn't be found. " + "This program stops here.")
    sys.exit(1)
    
    
for line in f:
    print(line, end='')
f.close()