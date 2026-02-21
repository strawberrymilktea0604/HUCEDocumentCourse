# -*- coding: utf-8 -*-
"""
Created on Tue May 16 08:38:14 2023

@author: minhk
"""

import math
funcs = (math.sin, math.cos)
for f in funcs:
    for x in [0, math.pi/2]:
        print("{}({:.3f}) = {:.3f}".format(f.__name__, x, f(x)))