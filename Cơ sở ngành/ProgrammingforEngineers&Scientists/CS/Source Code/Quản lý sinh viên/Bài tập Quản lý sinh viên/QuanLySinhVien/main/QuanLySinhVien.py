import math
from main.SinhVien import SinhVien

class QuanLySinhVien:
    listSinhVien = []

    # Hàm tạo ID tăng dần cho nhân viên
    def generateID(self):
        maxId = 1
        if (self.soLuongSinhVien() > 0):
            maxId = self.listSinhVien[0]._id
            for sv in self.listSinhVien:
                if (maxId < sv._id):
                    maxId = sv._id
            maxId = maxId + 1
        return maxId

    def soLuongSinhVien(self):
        return self.listSinhVien.__len__()

    def nhapSinhVien(self):
        # Khởi tạo một sinh viên mới
        svId = self.generateID()
        name = input("Nhap ten sinh vien: ")
        sex = input("Nhap gioi tinh sinh vien: ")
        age = int(input("Nhap tuoi sinh vien: "))
        diemToan = float(input("Nhap diem toan: "))
        diemLy = float(input("Nhap diem Ly: "))
        diemHoa = float(input("Nhap diem Hoa: "))
        sv = SinhVien(svId, name, sex, age, diemToan, diemLy, diemHoa)
        self.tinhDTB(sv)
        self.xepLoaiHocLuc(sv)
        self.listSinhVien.append(sv)

    def updateSinhVien(self, ID):
        # Tìm kiếm sinh viên trong danh sách listSinhVien
        sv:SinhVien = self.findByID(ID)
        # Nếu sinh viên tồn tại thì cập nhập thông tin sinh viên
        if (sv != None):
            # nhập thông tin sinh viên
            name = input("Nhap ten sinh vien: ")
            sex = input("Nhap gioi tinh sinh vien: ")
            age = int(input("Nhap tuoi sinh vien: "))
            diemToan = float(input("Nhap diem toan: "))
            diemLy = float(input("Nhap diem Ly: "))
            diemHoa = float(input("Nhap diem Hoa: "))
            # cập nhật thông tin sinh viên
            sv._name = name
            sv._sex = sex
            sv._age = age
            sv._diemToan = diemToan
            sv._diemLy = diemLy
            sv._diemHoa = diemHoa
            self.tinhDTB(sv)
            self.xepLoaiHocLuc(sv)
        else:
            print("Sinh vien co ID = {} khong ton tai.".format(ID))

    # Hàm sắp xếp danh sach sinh vien theo ID tăng dần
    def sortByID(self):
        self.listSinhVien.sort(key=lambda x: x._id, reverse=False)

    #Hàm sắp xếp danh sach sinh vien theo tên tăng dần
    def sortByName(self):
        self.listSinhVien.sort(key=lambda x: x._name, reverse=False)

    # Hàm sắp xếp danh sach sinh vien theo điểm TB tăng dần
    def sortByDiemTB(self):
        self.listSinhVien.sort(key=lambda x: x._diemTB, reverse=False)

    # Hàm tìm kiếm sinh viên theo ID
    # Trả về một sinh viên
    def findByID(self, ID):
        searchResult = None
        if (self.soLuongSinhVien() > 0):
            for sv in self.listSinhVien:
                if (sv._id == ID):
                    searchResult = sv
        return searchResult

    # Hàm tìm kiếm sinh viên theo tên
    # Trả về một danh sách sinh viên
    def findByName(self, keyword):
        listSV = []
        if (self.soLuongSinhVien() > 0):
            for sv in self.listSinhVien:
                if (keyword.upper() in sv._name.upper()):
                    listSV.append(sv)
        return listSV

    # Hàm xóa sinh viên theo ID
    def deleteById(self, ID):
        isDeleted = False
        # tìm kiếm sinh viên theo ID
        sv = self.findByID(ID)
        if (sv != None):
            self.listSinhVien.remove(sv)
            isDeleted = True
        return isDeleted

    # Hàm tính điểm TB cho sinh viên
    def tinhDTB(self, sv:SinhVien):
        diemTB = (sv._diemToan + sv._diemLy + sv._diemHoa) / 3
        # làm tròn điểm trung binh với 2 chữ số thập phân
        sv._diemTB = math.ceil(diemTB * 100) / 100

    #Hàm xếp loại học lực cho nhân viên
    def xepLoaiHocLuc(self, sv:SinhVien):
        if (sv._diemTB >= 8):
            sv._hocLuc = "Gioi"
        elif (sv._diemTB >= 6.5):
            sv._hocLuc = "Kha"
        elif (sv._diemTB >= 5):
            sv._hocLuc = "Trung Binh"
        else:
            sv._hocLuc = "Yeu"

    # Hàm hiển thị danh sách sinh viên ra màn hình console
    def showSinhVien(self, listSV):
        # hien thi tieu de cot
        print("{:<8} {:<18} {:<8} {:<8}{:<8} {:<8} {:<8} {:<8} {:<8}"
              .format("ID", "Name", "Sex", "Age", "Toan", "Ly", "Hoa", "Diem TB", "Hoc Luc"))
        # hien thi danh sach sinh vien
        if (listSV.__len__() > 0):
            for sv in listSV:
                print("{:<8} {:<18} {:<8} {:<8}{:<8} {:<8} {:<8} {:<8} {:<8}" 
                      .format(sv._id, sv._name, sv._sex, sv._age, sv._diemToan, sv._diemLy, 
                              sv._diemHoa,sv._diemTB, sv._hocLuc))
        print("\n")

    # Hàm trả về danh sách sinh viên hiện tại
    def getListSinhVien(self):
        return self.listSinhVien
