# -*- coding: utf-8 -*-
"""
Created on Sat Jan 21 01:34:32 2017

@author: Shu
"""
import math
for b in range(1, 999):
    for a in range(1, 999):
        P = (1000 - b) * (1000 - a)
        if P == 500000:
            abc = a*b*math.pow(b, 2)*math.pow(a, 2)
            print(abc)