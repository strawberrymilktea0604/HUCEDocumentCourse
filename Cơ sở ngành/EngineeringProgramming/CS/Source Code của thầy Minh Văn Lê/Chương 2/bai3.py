student={
    "ma_sinh_vien": "1188070",
    "ho ten": "hue",
    "tuoi":"18",
    "diem trung binh":10
}
print("Thong tin sinh vien la:")
for key, value in student.items():
    print(f"{key}:{value}")

diemmoi= float (input("Nhap diem trung binh moi can cap nhat:"))
student["diem trung binh"] = diemmoi

print(student)

