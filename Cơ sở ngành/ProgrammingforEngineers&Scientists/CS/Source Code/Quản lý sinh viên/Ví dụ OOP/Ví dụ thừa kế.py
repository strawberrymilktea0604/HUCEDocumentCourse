# -*- coding: utf-8 -*-
"""
Created on Tue Jun  6 08:15:48 2023

@author: minhk
"""

class Animal:
    def speak(self):
        print("Animal Speaking")
        
        
class Dog(Animal):
    def bark(self):
        print("Gou gou!")
        
d = Dog()
d.bark()
d.speak() 