"""
Bài tập 7: Viết chương trình cho phép người dùng nhập thông tin sinh viên gồm mã
sinh viên, họ tên và điểm trung bình. Thông tin này được ghi vào tập tin. 
Sau đó, đọc lại tập tin và in ra toàn bộ danh sách sinh viên.
"""

ds_sinh_vien = []
n = int(input("nhap vao so luong sinh vien: "))
for i in range(n):
    print(f"Nhap vao thong tin sinh vien thu {i + 1}:")
    ma_sinh_vien = input("ma sinh vien: ")
    ten_sinh_vien = input("ten sinh vien: ")
    diem = float(input("diem trung binh: "))
    ds_sinh_vien.append({
        "ma_sinh_vien": ma_sinh_vien,
        "ten_sinh_vien": ten_sinh_vien,
        "diem_tb": diem
    })
    
with open("sinh_vien.csv", "w", encoding='utf-8') as f:
    f.write("ma_sinh_vien,ten_sinh_vien,diem_tb\n")
    for sv in ds_sinh_vien:
        f.write(f'{sv["ma_sinh_vien"]},{sv["ten_sinh_vien"]},{sv["diem_tb"]}\n')

is_first_line = True
with open("sinh_vien.csv", "r", encoding='utf-8') as f:
    for line in f:
        if is_first_line:
            is_first_line = False
            continue
        parts = line.strip().split(",")
        #tiếp tục các cv khác