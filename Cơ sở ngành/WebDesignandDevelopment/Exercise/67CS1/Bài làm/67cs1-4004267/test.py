def compositions (n):
  if n == 1:
    return [[1]]
    L = []
    for x in compositions (n - 1):
       y = x. copy ()
       x. append (1)
       L. append (x)
       y[ -1] += 1
       L. append (y)
    return L

n = 1