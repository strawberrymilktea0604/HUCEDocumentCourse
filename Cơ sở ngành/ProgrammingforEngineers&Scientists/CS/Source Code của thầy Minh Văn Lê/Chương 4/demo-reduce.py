from functools import reduce

numbers = [1, 2, 3]

# Tính tổng
tong = reduce(lambda x, y: x + y, numbers, 0)
print("Tong:", tong)

# Tính tích
tich = reduce(lambda x, y: x * y, numbers)
print("Tich:", tich)