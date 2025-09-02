from scipy.optimize import bisect


def f(x):
    return x ** 3 - 2 * x ** 2




x = bisect(f, a=1.5, b=3, xtol=1e-6)
print("Root x is approx. x={:14.12g}.".format(x))
print("The error is less than 1e-6.")
print("The exact error is {}.".format(2 - x))



from scipy.optimize import newton


def f(x):
     return x ** 3 - 2 * x ** 2



x = newton(f, x0=3.2)
print("Root x is approx. x={:14.12g}.".format(x))
print("The error is less than 1e-6.")
print("The exact error is {}.".format(2 - x))
