#This is fixed point iteration method

import math

def f(x):
    return (1/math.sqrt(1+x**2))
    #return the function f(x) as in x = f(x)

n = int(input("number of iterations: "))
a = float(input("initial value x_0: "))

def fixit(n1, a1):
    if (n1>1):
        print(f(a1))
        n1=n1-1
        fixit(n1, f(a1))
    else:
        print(f(a1))

fixit(n, a)

