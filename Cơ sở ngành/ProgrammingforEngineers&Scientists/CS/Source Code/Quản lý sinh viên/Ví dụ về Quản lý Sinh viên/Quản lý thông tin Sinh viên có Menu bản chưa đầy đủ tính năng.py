import numpy


class SinhVien:
    def __init__(self, ten: str, id: str, gioitinh: str, tuoi: str, que: str, diem: int):
        self.ten = ten
        self.id = id
        self.que = que
        self.gioitinh = gioitinh
        self.tuoi = tuoi
        self.diem = diem
        
        self.dtb = numpy.array(diem).mean()
        if self.dtb >= 8.:
            self.xeploai = 'Gioi'
        elif self.dtb >= 6.5:
            self.xeploai = 'Kha'
        elif self.dtb >= 5.:
            self.xeploai = 'Trung binh'
        else:
            self.xeploai = 'Kem'
        
        
class QuanLySinhVien:
    def __init__(self):
        n_str = input('Nhap so sinh vien: ')
        assert n_str.isnumeric(), 'Bat buoc la so nhe!'
        self.n = int(n_str)
        
        k_str = input('Nhap so mon hoc: ')
        assert k_str.isnumeric(), 'Bat buoc la so nhe!'
        self.k = int(k_str)
        
        self.listsinhvien = []
        for sinhvien_stt in range(self.n):
            ten = input('Nhap ten sinh vien: ')
            assert ten != '', 'Ten sinh vien khong duoc de trong!'
            
            que = input(f'Nhap que quan sinh vien {ten}: ')
            assert que != '', 'Khong duoc de trong!'
            
            gioitinh = input(f'Nhap gioi tinh sinh vien {ten}: ')
            assert gioitinh != '', 'Khong duoc de trong!'
            
            tuoi = input(f'Nhap tuoi sinh vien sinh vien {ten}: ')
            assert ten != '', 'Khong duoc de trong!'
            
            id = f'{sinhvien_stt:03d}'
            
            diem = []
            while diem == []:
                diem = self.nhapdiem(ten)
                
            sinhvien = SinhVien(ten, id, que, gioitinh, tuoi, diem)
            self.listsinhvien.append(sinhvien)
            
    def nhapdiem(self, ten):
        k_diem_str = input(f'Nhap diem cua sinh vien {ten}: \n')
        k_diem_strs = k_diem_str.split()
        
        flags_0                 = [k_str.isnumeric() for k_str in k_diem_strs]
        cond_0                  = all(flags_0)
        
        if not cond_0:
            print('Diem bat buoc la 1 con so!')
            return []
        
        flags_1                 = [0 <= int(k_str) <= 10 for k_str in k_diem_strs]
        cond_1                  = all(flags_1)
        if not cond_1:

            print('Diem phai trong khoang tu 0 den 10!')
            return []

        if len(k_diem_strs) != self.k:
            print('Phai tuong ung voi so mon hoc!')
            return []

        k_diem  = [int(k_str) for k_str in k_diem_strs]
        return  k_diem
        print("\nThem sinh vien thanh cong!")
    
    def inthongtin(self):
        print('Thong tin sinh vien: \n')
        for sinhvien in self.listsinhvien:
            print(sinhvien.__dict__)
            
            

qlsv = QuanLySinhVien()
while (1==1):
    print("\nCHUONG TRINH QUAN LY SINH VIEN C#")
    print("*************************MENU**************************")
    print("**  1. Them sinh vien.                               **")
    print("**  2. Hien thi danh sach sinh vien.                 **")
    print("**  0. Thoat                                         **")
    print("*******************************************************")
    
    key = int(input("Nhap tuy chon: "))
    if (key == 1):
        print("\n1. Them sinh vien.")
        qlsv.__init__()
        qlsv.nhapdiem()
    if (key == 2):
        qlsv.inthongtin()
    elif (key == 0):
        print("\nBan da chon thoat chuong trinh!")
        break
    else:
        print("\nKhong co chuc nang nay!")
        print("\nHay chon chuc nang trong hop menu.")
        
                