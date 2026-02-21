"""
{
    "ma_thiet_bi": "",
    "ten_thiet_bi": "",
    "trang_thai": ""
}
"""
ds_thiet_bi = [{
    "ma_thiet_bi": "TB001",
    "ten_thiet_bi": "May tinh",
    "trang_thai": "work"
},
{
    "ma_thiet_bi": "TB002",
    "ten_thiet_bi": "May in",
    "trang_thai": "error"
}]

#ds_thiet_bi = []

#Nhập vào từ bàn phím toàn bộ danh sách
so_luong = int(input("Nhập vào số lượng thiết bị"))
for num in range(so_luong):
    while True:
        ma_thiet_bi = input(f"Nhập vào mã thiết bị thứ {num + 1}")
        tim_thay_trung_ma = False
        for thiet_bi in ds_thiet_bi:
            if thiet_bi["ma_thiet_bi"] == ma_thiet_bi:
                tim_thay_trung_ma = True
                break
        if not tim_thay_trung_ma:
            break
    
    ten_thiet_bi = input(f"Nhập vào tên thiết bị thứ {num + 1}")
    trang_thai = input(f"Nhập vào trạng thái thiết bị thứ {num + 1}")
    ds_thiet_bi.append({
        "ma_thiet_bi": ma_thiet_bi,
        "ten_thiet_bi": ten_thiet_bi,
        "trang_thai": trang_thai
    })

#In ra toàn bộ danh sách thiết bị
print("Danh sách thiết bị là:")
for thiet_bi in ds_thiet_bi:
    for key, value in thiet_bi.items():
        print(f"{key}: {value}")
    print("-----")

dem = 0
for thiet_bi in ds_thiet_bi:
    if thiet_bi["trang_thai"] == "work":
        dem += 1

print("so luong thiet bi con hoat dong la", dem)

ma_tim_kiem = input("Nhập mã cần tìm kiếm ")

thim_thay = False
for thiet_bi in ds_thiet_bi:
    if thiet_bi["ma_thiet_bi"] == ma_tim_kiem:
        thim_thay = True
        thiet_bi["trang_thai"] = "error"

if not thim_thay:
    print("Không tìm thấy thiết bị có mã ", ma_tim_kiem)
