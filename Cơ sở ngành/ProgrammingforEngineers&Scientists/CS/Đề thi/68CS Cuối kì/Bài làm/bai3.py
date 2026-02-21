# Câu 3: Lập trình hướng đối tượng quản lý sinh viên

class Nguoi:
    def __init__(self, ten, tuoi, quequan):
        self.ten = ten
        self.tuoi = tuoi
        self.quequan = quequan

class SinhVien(Nguoi):
    def __init__(self, ten, tuoi, quequan, lopquanly, ngaynhaphoc, namtrongdanhsachemail):
        super().__init__(ten, tuoi, quequan)
        self.lopquanly = lopquanly
        self.ngaynhaphoc = ngaynhaphoc
        self.namtrongdanhsachemail = namtrongdanhsachemail

    def __str__(self):
        return f"{self.ten} - {self.tuoi} tuổi - {self.quequan} - Lớp: {self.lopquanly} - Ngày nhập học: {self.ngaynhaphoc} - Trong DS email: {self.namtrongdanhsachemail}"

# ====== a. Nhập n sinh viên ======
def nhap_danh_sach_sv():
    ds = []
    n = int(input("Nhập số lượng sinh viên: "))
    for i in range(n):
        print(f"\n-- Sinh viên thứ {i+1} --")
        ten = input("Tên: ")
        tuoi = int(input("Tuổi: "))
        quequan = input("Quê quán: ")
        lopquanly = input("Lớp quản lý: ")
        ngaynhaphoc = input("Ngày nhập học (dd/mm/yyyy): ")
        namtrongds = input("Có trong danh sách email (y/n): ").lower() == 'y'
        sv = SinhVien(ten, tuoi, quequan, lopquanly, ngaynhaphoc, namtrongds)
        ds.append(sv)
    return ds

# ====== b. Hiển thị danh sách ======
def hien_thi_danh_sach(ds):
    print("\n=== DANH SÁCH SINH VIÊN ===")
    for sv in ds:
        print(sv)

# ====== c. Tìm sinh viên lớn tuổi nhất ======
def tim_sv_lon_tuoi_nhat(ds):
    max_tuoi = max(sv.tuoi for sv in ds)
    print("\n=== Sinh viên lớn tuổi nhất ===")
    for sv in ds:
        if sv.tuoi == max_tuoi:
            print(sv)

# ====== d. Lọc sinh viên có trong danh sách email và ghi file ======
def luu_ds_email(ds, file_path='dssvnamtrongdsemail.txt'):
    ds_email = [sv for sv in ds if sv.namtrongdanhsachemail]
    with open(file_path, 'w', encoding='utf-8') as f:
        for sv in ds_email:
            f.write(str(sv) + '\n')
    print(f"\nĐã lưu {len(ds_email)} sinh viên có trong danh sách email vào {file_path}")

# ====== Chương trình chính ======
if __name__ == "__main__":
    ds = nhap_danh_sach_sv()
    hien_thi_danh_sach(ds)
    tim_sv_lon_tuoi_nhat(ds)
    luu_ds_email(ds)
