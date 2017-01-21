# -*- coding: utf-8 -*-
"""
Created on Sat Jan 21 01:34:32 2017

@author: Shu
"""
import math
for b in range(1, 500):
    for a in range(1, 500):
        if (1000 - b) * (1000 - a) == 500000  and b > a:
            abc = a*b*math.pow(b, 2)*math.pow(a, 2)
            print(abc, a, b)

#Note: Solved mathematically first and then decided to use program
#Problem reduced to 500,000 = (1000 - b) * (1000 * a)