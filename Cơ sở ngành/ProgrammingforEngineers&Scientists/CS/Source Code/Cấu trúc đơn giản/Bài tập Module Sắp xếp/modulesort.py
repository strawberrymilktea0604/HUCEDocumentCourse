# -*- coding: utf-8 -*-
"""
Created on Tue May 23 07:48:52 2023

@author: minhk
"""

def bubbleSort(array):
  for i in range(len(array)):
    for j in range(0, len(array) - i - 1):
      if array[j] > array[j + 1]:
        temp = array[j]
        array[j] = array[j+1]
        array[j+1] = temp
        
        swapped = True
          
    if not swapped:
      break

        
dayso1 = [-2, 45, 0, 11, -9]
bubbleSort(dayso1)
        
def selectionSort(array, size):
    for step in range(size):
        min_idx = step
        for i in range(step + 1, size):
            if array[i] > array[min_idx]:
                min_idx = i
        (array[step], array[min_idx]) = (array[min_idx], array[step])
        
dayso2 = [-2, 45, 0, 11, -9]
size2 = len(dayso2)
selectionSort(dayso2, size2)
        
