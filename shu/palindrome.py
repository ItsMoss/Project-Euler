# -*- coding: utf-8 -*-
"""
Created on Wed Jan 18 18:25:11 2017

@author: Shu
"""

#Determine which palindromes
import math
A = 0
for i in range(990100, 10000, -1):
    x = i
    pal = [int(x) for x in str(x)]
    pal_rev = [0] * len(pal)
    
    for i in range(0, len(pal)):
        pal_rev[i] = pal[len(pal) - (i + 1)]


    if pal_rev == pal:
        pal_or = 0
        for i in range(len(pal)):
            pal_or = pal_or + pal[i]*math.pow(10, len(pal) - i - 1)

        for i in range(999, 99, -1):
            B = pal_or % i
            
            if B == 0:
                rem = pal_or / i
                
                if rem < 1000 and rem > 99:
                    A = rem * i
    else:
        if A > 0:
            break

                
 
                    
                        
                    

        

        