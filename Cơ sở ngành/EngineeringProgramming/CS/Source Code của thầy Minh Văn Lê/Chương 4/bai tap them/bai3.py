#Menu tính toán: cho người dùng chọn cộng, trừ, nhân, chia, 
# lặp lại đến khi chọn thoát (yêu cầu dùng hàm cho các công việc)

# ====Menu====
# 1. cộng
# 2. trừ
# 3. nhân
# 4. chia
# 5. thoát
# vui lòng chọn từ 1 đến 5: 

def tinh_toan(num1, num2, lua_chon):
    if (lua_chon == 1):
        return num1 + num2
    elif (lua_chon == 2):
        return num1 - num2
    elif (lua_chon == 3):
        return num1 * num2
    elif (lua_chon == 4):
        #logic thêm
        return num1 / num2

def menu():
    while True:
        print("""====Menu====
# 1. cộng
# 2. trừ
# 3. nhân
# 4. chia
# 5. thoát
# vui lòng chọn từ 1 đến 5:
""")
        lua_chon = int(input("nhập một số: "))
        if lua_chon in [1,2,3,4]:
            so_1 = float(input("nhập số đầu: "))
            so_2 = float(input("nhập số thứ hai: "))
            tinh_toan(so_1, so_2, lua_chon)
        elif lua_chon == 5:
            break
        else:
            print("lỗi hãy nhập lại")

menu()