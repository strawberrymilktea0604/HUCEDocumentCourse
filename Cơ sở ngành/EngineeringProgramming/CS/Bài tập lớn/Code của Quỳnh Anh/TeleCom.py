from math import sqrt
from random import randint, shuffle



class Point:
    """A class representing a point in 2D space."""
    def __init__(self, x=0, y=0) -> None:
        self.x = x
        self.y = y


class Circle:
    """A class representing a circle in 2D space."""
    def __init__(self, c=Point(), r=0) -> None:
        self.c = c
        self.r = r


def dist(a, b):
    """Returns the distance between two points a and b."""
    return sqrt((a.x - b.x) ** 2 + (a.y - b.y) ** 2)


def is_inside(c, p):
    """Function to check if a point inside or on the boundary of a circle."""
    return float(dist(c.c, p)) <= c.r


def get_circle_center(bx, by, cx, cy):
    """Returns the a circle defined by 3 points"""
    B = bx * bx + by * by
    C = cx * cx + cy * cy
    D = bx * cy - by * cx
    return Point((cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D))


def circle_from1(A, B):
    """Return the smallest circle that intersects 2 points"""
    C = Point((A.x + B.x) / 2.0, (A.y + B.y) / 2.0) #Set the center to be the midpoint of A and B
    return Circle(C, dist(A, B) / 2.0)  #Set the radius to be half the distance between A and B


def circle_from2(A, B, C):
    """Return the smallest circle that intersects 3 points"""
    I = get_circle_center(B.x - A.x, B.y - A.y, C.x - A.x, C.y - A.y)
    I.x += A.x
    I.y += A.y
    return Circle(I, dist(I, A))  


def is_valid(c, P):
    """Check whether a circle encloses all points given"""
    for p in P:
        if not is_inside(c, p):
            return False
    return True


def min_circle_trivial(P):
    """Return the minimum enclosing circle for N <= 3"""
    assert len(P) <= 3
    if not P:
        return Circle()
    elif len(P) == 1:
        return Circle(P[0], 0)
    elif len(P) == 2:
        return circle_from1(P[0], P[1])
    for i in range(3):
        for j in range(i + 1, 3):
            C = circle_from1(P[i], P[j])
            if is_valid(C, P):
                return C
    return circle_from2(P[0], P[1], P[2])


def welzl_helper(P, R, n):
    """Return the mec using welzl's algorithm
    P: list of points
    R: list of points on the boundary of the circle boundary
    n: the number of points in P not yet processed"""
    if n == 0 or len(R) == 3:
        #Base case when all points processed or |R| = 3
        return min_circle_trivial(R)
    #Pick a random point p
    i = randint(0, n - 1)
    p = P[i]
    P[i], P[n - 1] = P[n - 1], P[i]
    #Get the MEC circle d from the set of points P - {p}
    d = welzl_helper(P, R.copy(), n - 1)
    #If d contains p, return d
    if is_inside(d, p):
        return d
    #Otherwise, must be on the boundary of the MEC circle
    R.append(p)
    #Return the mec circle from P - {p} and R U {p}
    return welzl_helper(P, R.copy(), n - 1)


def welzl(P):
    P_copy = P.copy()
    shuffle(P_copy)
    return welzl_helper(P_copy, [], len(P_copy))
