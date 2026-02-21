from scipy.optimize import bisect


def f(x):
    return x ** 4 - 7 * x ** 3 + 8 * x ** 2 + 17 * x - 5

for i in range(-10, 10):
    print(i,f(i))
    
print(bisect(f, 3, 4))