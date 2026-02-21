# -*- coding: utf-8 -*-
"""
Created on Sat May 13 09:58:23 2023

@author: minhk
"""

def find_value(N):
    x = 0
    y = 0
    for i in range(1, N + 1):
        x = i
        y = (N*N - i) / (i + 1)
        
        if(y.is_integer()):
            return [x, int(y)]
            break
        
def result(infile, outfile):
    fin = open(infile, 'tr')
    lines = fin.readlines()
    fin.close()
    fout = open(outfile, 'tw')
    array = []
    
    for line in lines:
        array.append(int(line.rstrip("\n")))
        
    for j in range(array[0]):
        stringResult = ""
        arrayResult = find_value(array[j+1])
        
        if(arrayResult == None):
            stringResult = "None"
            
        else:
            for arr in arrayResult:
                stringResult = stringResult + str(arr)
                
            
        fout.write("{}\n".format(stringResult))
    fout.close()
        