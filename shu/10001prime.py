# -*- coding: utf-8 -*-
"""
Created on Fri Jan 20 21:59:26 2017

@author: Shu
"""
#  Find 1001st prime

def find_prime(n):
    primes = [2]
    for i in range(2, n + 1):
        if i % 2 != 0:
            for j in range(2, i):
                if i % j == 0:
                    break
                elif i % j != 0 and j == i - 1:
                    primes.append(i)
                    break
        
    return primes    

def check_prime(n):
    primes = False
    
    if n % 2 == 0:
        return primes

    elif n % 2 != 0:
        for i in range(3, int(n/2) + 1, 2):
            if n % i == 0:
                primes = False
                return primes
        
        primes = True
        return primes
                

if __name__ == "__main__":
    n = 5
    count = 2
    total = 5
    primes = False
    while count < 10001:
        primes = check_prime(n)

        if primes is True:
            count += 1

            if count == 10001:
                prime1001 = n
                break
            
        n = n + 2
    
    print(prime1001)

