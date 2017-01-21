# -*- coding: utf-8 -*-
"""
Created on Fri Jan 20 21:59:26 2017

@author: Shu
"""
#  Find 1001st prime
n = 2
count = 0
while count < 1001:
    for i in range(n, n + 1):
        for j in range(i - 1, 0, -1):

            if j == 1:
                prime = i
                count += 1

            if i % j == 0:
                break

    if count == 1001:
        prime_1001 = i
        print(prime_1001)

    n += 1
