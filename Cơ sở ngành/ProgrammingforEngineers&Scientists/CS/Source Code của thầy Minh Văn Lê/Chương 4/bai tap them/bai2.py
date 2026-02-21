# Trò chơi đoán số (máy chọn ngẫu nhiên 1–100, người chơi đoán đến khi đúng).

import random

while True:
    so_ngau_nhien = random.randint(1, 100)
    du_doan = input("Nhap so du doan ")
    if (so_ngau_nhien == du_doan):
        print("ban da doan dung")
        break
    else:
        print("ban doan sai, so thuc te la", so_ngau_nhien)

