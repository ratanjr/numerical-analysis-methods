#This is biseciton method for finding roots 

import math

t = int(input("desired number of iterations: "))
a = float(input("first point: "))
b = float(input("second point: "))

def f(x):
    return float(x**2-x-6)
    #return the function expression here

def bisec(ak, bk, k):
    mid = (ak+ bk)/2.0
    print(mid)
    if(k<t):
        if(f(mid)==0):
            return mid
        elif (f(mid)*f(bk)<0):
            return (bisec(mid, bk, k+1))
        else:
            return (bisec(ak, mid, k+1))
    else:
        return mid

print("final result", bisec(a, b, 0))