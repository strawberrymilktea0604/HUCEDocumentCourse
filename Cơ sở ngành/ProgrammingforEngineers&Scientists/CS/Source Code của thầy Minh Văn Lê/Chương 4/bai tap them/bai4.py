#Trò chơi oẳn tù tì với máy (lựa chọn random)
import random

while True:
    lua_chon = input("Nhập vào lựa chọn: keo, bua, bao: ")
    cac_lua_chon = ["keo", "bua", "bao"]
    if lua_chon not in cac_lua_chon:
        print("lựa chọn không hợp lệ, mời nhập lại")
        continue
    may_chon = cac_lua_chon[random.randint(0, 2)]
    ket_qua = False
    if lua_chon == "keo" and may_chon == "bao":
        ket_qua = True
    elif lua_chon == "bua" and may_chon == "keo":
        ket_qua = True
    elif lua_chon == "bao" and may_chon == "bua":
        ket_qua = True
    elif lua_chon == may_chon:
        print("hòa")
        continue
    print("Máy chọn ", may_chon, ("bạn thắng" if ket_qua else "bạn thua"))
