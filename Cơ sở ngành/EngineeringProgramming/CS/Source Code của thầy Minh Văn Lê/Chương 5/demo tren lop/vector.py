class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector2D(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2D(self.x - other.x, self.y - other.y)
    
    def __str__(self):
        return f"Vector2D({self.x}, {self.y})"
    
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    
# Sử dụng
v1 = Vector2D(3, 4)
v2 = Vector2D(1, 2)
v3 = v1 + v2
print(f"v1 + v2 = {v3}")
v4 = v1 - v2
print(f"v1 - v2 = {v4}")
print(f"v1 == v2: {v1 == v2}")
print(f"v1 == v1: {v1 == v1}")