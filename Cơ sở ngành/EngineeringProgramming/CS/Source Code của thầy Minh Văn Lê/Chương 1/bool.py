from decimal import Decimal

print(Decimal("0.1") + Decimal("0.2") == Decimal("0.3"))
# True


num1 = float(input("Nhập số thứ nhất: ")) # 3
num2 = float(input("Nhập số thứ hai: ")) # 1

print(not (num1 > num2 and not (num2 > 3 or num1 > 0)))


if num1 > 0:
    print("Số thứ nhất là số dương")
else:
    print("Số thứ nhất không phải số dương")
    

if num2 <= 0:
    print("Số thứ hai không phải số dương")
elif num2 > 5:
    print("Số thứ hai lớn hơn 5")
else:
    print("Số thứ hai là số dương và nhỏ hơn hoặc bằng 5")
    

if num2 <= 0:
    print("Số thứ hai không phải số dương")
if num2 < 10 and num2 > 5:
    print("Số thứ hai lớn hơn 5")
else:
    print("Số thứ hai là số dương và nhỏ hơn hoặc bằng 5")