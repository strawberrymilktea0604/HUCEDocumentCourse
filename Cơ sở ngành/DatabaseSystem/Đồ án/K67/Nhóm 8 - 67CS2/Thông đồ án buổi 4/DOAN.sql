CREATE DATABASE QuanLyKhachSan
USE QuanLyKhachSan

CREATE TABLE PHONG (
	SoPhong tinyint constraint PK_PHONG primary key,
	MaHangPhong char(3) not null,
	MaLoaiPhong char(3) not null,
	SucChua tinyint not null,
	DienTich decimal(4,2) not null,
	TrangThai nvarchar(20) not null
)
GO

CREATE TABLE LOAI_PHONG (
	MaLoaiPhong char(3) constraint PK_LOAI_PHONG primary key,
	TenLoaiPhong nvarchar(20) constraint UQ_TEN_LOAI_PHONG unique not null,
	GiaLoai int constraint CK_GIALOAI_GT_0 check(GiaLoai > 0) not null
)
GO

CREATE TABLE HANG_PHONG (
	MaHangPhong char(3) constraint PK_HANG_PHONG primary key,
	TenHangPhong nvarchar(20) constraint UQ_TEN_HANG_PHONG unique not null,
	GiaHang int constraint CK_GIAHANG_GT_0 check(GiaHang > 0) not null
)
GO

CREATE TABLE PHIEU_DAT_PHONG (
	MaPhieuDP char(10) constraint PK_PDP primary key,
	NgayLap datetime not null,
	MaKH char(10) not null,
	MaNV char(5) not null,
	MaKHTT char(10),
	MaVoucher char(15)
)
GO

CREATE TABLE PHIEU_DAT_COC (
	MaPhieuDC char(10) constraint PK_PDC primary key,
	NgayLap datetime not null,
	PTTT nvarchar(20) not null,
	MaPhieuDP char(10),
	MaNV char(5)	
)
GO

CREATE TABLE CHI_TIET_DAT_PHONG (
	SoPhong tinyint,
	MaPhieuDP char(10),
	NgayDen datetime not null,
	NgayDi datetime not null,
	constraint PK_CHI_TIET_DP primary key (SoPhong, MaPhieuDP)
)
GO

CREATE TABLE PHIEU_SU_DUNG_DICH_VU (
	MaPhieuSDDV char(10) constraint PK_PSDDV primary key,
	MaPhieuDP char(10) not null,
	NgayLap date not null,
	MaNV char(5) not null,
	MaVoucher char(15)
)
GO

CREATE TABLE CHI_TIET_SU_DUNG_DICH_VU (
	MaPhieuSDDV char(10),
	MaDV char(5),	
	SoLuong tinyint constraint CK_SO_LUONG_SDDV_GT_0 check (SoLuong > 0) not null,
	GiaBan int constraint CK_GIA_BAN_GT_0 check (GiaBan > 0) not null,
	constraint PK_CTSDDV primary key (MaPhieuSDDV, MaDV)
)
GO

CREATE TABLE DICH_VU (
	MaDV char(5) constraint PK_MA_DV primary key,
	TenDV nvarchar(20) constraint UQ_TEN_DV unique not null,
	DVTinh nvarchar(10) not null,
	GiaNY int constraint CK_GIA_NY_GT_0 check (GiaNY > 0) not null
)
GO

CREATE TABLE PHIEU_NHAP_TIEN_NGHI (
	MaPhieuNhap char(10) constraint PK_PNTN primary key,
	MaNV char(5) not null,
	NgayLap date not null
)
GO

CREATE TABLE CHI_TIET_NHAP_TIEN_NGHI (
	MaPhieuNhap char(10),
	MaTN char(5),
	SoLuong tinyint constraint CK_SO_LUONG_NTN_0 check (SoLuong > 0) not null,
	DVTinh nvarchar(10) not null,
	constraint PK_CTNTN primary key (MaPhieuNhap, MaTN)
)
GO

CREATE TABLE TIEN_NGHI (
	MaTN char(5) constraint PK_MaTN primary key,
	TenTN nvarchar(20) not null,
	MaNCC char(5) not null,
	Gia int constraint CK_GIA_GT_0 check (Gia > 0) not null
)
GO

CREATE TABLE PHIEU_BOI_THUONG_THIET_HAI (
	MaPhieuBTTH char(10) constraint PK_PBTTH primary key,
	MaPhieuDP char(10) not null,
	NgayLap date not null,
	MaNV char(5) not null
)
GO

CREATE TABLE CHI_TIET_BOI_THUONG_THIET_HAI (
	MaPhieuBTTH char(10),
	MaTN char(5),
	SoLuong tinyint constraint CK_SO_LUONG_BTTH_GT_0 check (SoLuong > 0) not null,
	DVTinh nvarchar(10) not null,
	constraint PK_CTBTTH primary key (MaPhieuBTTH, MaTN)
)
GO

CREATE TABLE KHACH_HANG (
	MaKH char(10) constraint PK_KH primary key,
	TenKH nvarchar(40) not null,
	CCCD char(12) constraint UQ_CCCD unique not null,
	QuocTich nvarchar(20) not null,
	SDT varchar(15) constraint UQ_SDT unique not null,
	Email nvarchar(40)
)
GO

CREATE TABLE THE_KHTT (
	MaKHTT char(10) constraint PK_KHTT primary key,
	MaKH char(10) not null,
	DiemTL int not null,
	HSD date not null,
	TrangThai nvarchar(20) not null,
	Hang nvarchar(15) constraint CK_HANG CHECK (Hang IN (N'Bạc', N'Vàng', N'Kim cương')) not null
)
GO

CREATE TABLE NHA_CUNG_CAP (
	MaNCC char(5) constraint PK_MA_NCC primary key,
	TenNCC nvarchar(50) constraint UQ_TEN_NCC unique not null
)
GO

CREATE TABLE VOUCHER (
	MaVoucher char(15) constraint PK_MA_VOUCHER primary key,
	Loai nvarchar(20) not null,
	PhanTram tinyint constraint CK_VOUCHER_VALUE check (PhanTram >= 30 AND PhanTram <= 70) not null 
)
GO

CREATE TABLE NHAN_VIEN (
	MaNV char(5) constraint PK_MANV primary key,
	HoTen nvarchar(40) not null,
	CCCD char(12) not null,
	GioiTinh bit not null,
	SDT varchar(15) not null ,
	Email nvarchar(40) not null,
	DiaChi nvarchar(20) not null,
	NgayVao date not null
)
GO

CREATE TABLE SO_CHAM_CONG (
	MaCC char(10) constraint PK_MA_CC primary key,
	MaNV char(5) not null,
	TenCa nvarchar(10) not null, 
	NgayCham date not null, 
	GioBD time not null, 
	GioKT time not null,
	constraint UQ_MANV_TENCA_NGAYCHAM unique (MaNV, TenCa, NgayCham)
)
GO

CREATE TABLE CA_LAM (
	TenCa nvarchar(10) constraint PK_TEN_CA primary key,
	KhungGio nvarchar(15) not null
)
GO

alter table PHONG
add constraint FK_PHONG_HANGPHONG foreign key (MaHangPhong) references HANG_PHONG(MaHangPhong),
	constraint FK_PHONG_LOAIPHONG foreign key (MaLoaiPhong) references LOAI_PHONG(MaLoaiPhong);
go

alter table PHIEU_DAT_PHONG
add constraint FK_PDP_KHACHHANG foreign key (MaKH) references KHACH_HANG(MaKH),
	constraint FK_PDP_NHANVIEN foreign key (MaNV) references NHAN_VIEN(MaNV),
	constraint FK_PDP_KHTT foreign key (MaKHTT) references THE_KHTT(MaKHTT),
	constraint FK_PDP_VOUCHER foreign key (MaVoucher) references VOUCHER(MaVoucher);
go

alter table PHIEU_DAT_COC
add constraint FK_PDC_PDP foreign key (MaPhieuDP) references PHIEU_DAT_PHONG(MaPhieuDP),
	constraint FK_PDC_NHANVIEN foreign key (MaNV) references NHAN_VIEN(MaNV);
go

alter table PHIEU_SU_DUNG_DICH_VU
add constraint FK_PSDDV_PDP foreign key (MaPhieuDP) references PHIEU_DAT_PHONG(MaPhieuDP),
	constraint FK_PSDDV_NV foreign key (MaNV) references NHAN_VIEN(MaNV),
	constraint FK_PSDDV_VOUCHER foreign key (MaVoucher) references VOUCHER(MaVoucher);
go

alter table PHIEU_NHAP_TIEN_NGHI
add constraint FK_PNTN_NHANVIEN foreign key (MaNV) references NHAN_VIEN(MaNV);
go

alter table TIEN_NGHI
add constraint FK_TIENNGHI_NHACC foreign key (MaNCC) references NHA_CUNG_CAP(MaNCC);
go

alter table PHIEU_BOI_THUONG_THIET_HAI
add constraint FK_PBTTH_PDP foreign key (MaPhieuDP) references PHIEU_DAT_PHONG(MaPhieuDP),
	constraint PK_PBTTH_NV foreign key (MaNV) references NHAN_VIEN(MaNV);
go

alter table THE_KHTT
add constraint FK_KHTT_KHACHHANG foreign key (MaKH) references KHACH_HANG(MaKH);
go

alter table SO_CHAM_CONG
add constraint FK_SCC_NHANVIEN foreign key (MaNV) references NHAN_VIEN(MaNV),
	constraint FK_SCC_CALAM foreign key (TenCa) references CA_LAM(TenCa);
go

--- Bổ sung ràng buộc khóa ngoại đối với các bảng nhiều khóa chính
alter table CHI_TIET_SU_DUNG_DICH_VU
add constraint FK_CTSDDV_PSDDV foreign key (MaPhieuSDDV) references PHIEU_SU_DUNG_DICH_VU(MaPhieuSDDV),
	constraint FK_CTSDDV_DICHVU foreign key (MaDV) references DICH_VU(MaDV);
go

alter table CHI_TIET_DAT_PHONG
add constraint FK_CTDP_PHONG foreign key (SoPhong) references PHONG(SoPhong),
	constraint FK_CTDP_PDP foreign key (MaPhieuDP) references PHIEU_DAT_PHONG(MaPhieuDP);
go

alter table CHI_TIET_NHAP_TIEN_NGHI
add constraint FK_CTNTN_PNTN foreign key (MaPhieuNhap) references PHIEU_NHAP_TIEN_NGHI(MaPhieuNhap),
	constraint FK_CTNTN_TIENNGHI foreign key (MaTN) references TIEN_NGHI(MaTN);
go

alter table CHI_TIET_BOI_THUONG_THIET_HAI
add constraint FK_CTBTTH_PBTTH foreign key (MaPhieuBTTH) references PHIEU_BOI_THUONG_THIET_HAI(MaPhieuBTTH),
	constraint FK_CTBTTH_TIENNGHI foreign key (MaTN) references TIEN_NGHI(MaTN);
go

-------------------------------------------------------------------------------------------------------------------------
INSERT INTO HANG_PHONG(MaHangPhong,	TenHangPhong, GiaHang)
VALUES 
	('STD', 'Standard', 300000),
	('SUP', 'Superior', 600000),
	('DLX', 'Deluxe', 900000);
GO

INSERT INTO LOAI_PHONG(MaLoaiPhong,	TenLoaiPhong, GiaLoai)
VALUES 
	('L01', N'1 giường đơn', 50000),
    ('L02', N'2 giường đơn', 100000),
	('L03', N'1 giường đôi', 75000),
	('L04', N'2 giường đôi', 150000);
GO

INSERT INTO PHONG(SoPhong, MaHangPhong, MaLoaiPhong, SucChua, DienTich, TrangThai)
VALUES 
	('11', 'STD', 'L01', 1, 20, N'Đầy'),
    ('12', 'STD', 'L02', 2, 20, N'Trống'),
	('13', 'SUP', 'L01', 1, 30, N'Đang dọn'),
    ('14', 'SUP', 'L02', 2, 30, N'Đầy'),
	('15', 'DLX', 'L02', 2, 45, N'Đầy'),
    ('21', 'STD', 'L01', 1, 20, N'Đang dọn'),
	('22', 'STD', 'L02', 2, 20, N'Trống'),
    ('23', 'SUP', 'L02', 2, 30, N'Đang dọn'),
	('24', 'SUP', 'L03', 2, 30, N'Trống'),
    ('25', 'DLX', 'L03', 2, 45, N'Đầy'),
	('31', 'STD', 'L02', 2, 20, N'Đang dọn'),
    ('32', 'STD', 'L03', 2, 20, N'Đầy'),
	('33', 'SUP', 'L02', 2, 30, N'Đầy'),
    ('34', 'SUP', 'L03', 2, 30, N'Trống'),
	('35', 'DLX', 'L04', 4, 45, N'Trống');
GO 
-------------------------------------------------------------------------

INSERT INTO KHACH_HANG(MaKH, TenKH, CCCD, QuocTich, SDT, Email)
VALUES
	('KH00000001', N'Nguyễn Văn Quang', '001204081792', N'Việt Nam', '0968452917', 'quangdzpro@gmail.com'),
	('KH00000002', N'Hoàng Mạnh Hùng', '006946284926', N'Việt Nam', '0369725497', 'hung2k4@gmail.com'),
	('KH00000003', N'Lê Kim Ngân', '008625194628', N'Việt Nam', '0908542835', 'nganlk@gmail.com'),
	('KH00000004', N'Nguyễn Huy Hoàng', '002649254724', N'Việt Nam', '0987542835', 'hoangnh@gmail.com'),
	('KH00000005', N'Mai Ngọc Linh', '009324748258', N'Việt Nam', '0974839519', 'linhxjnh@gmail.com'),
	('KH00000006', N'Nguyễn Thu Trang', '007451947258', N'Việt Nam', '0969641835', 'trannt98@gmail.com'),
	('KH00000007', N'Đặng Minh Đức', '000864729454', N'Việt Nam', '0982945248', 'duc18c@gmail.com'),
	('KH00000008', N'Ngô Sơn Tùng', '004815458294', N'Việt Nam', '0996517385', 'tungngoo@gmail.com'),
	('KH00000009', N'Phạm Quỳnh Chi', '007897635528', N'Việt Nam', '0958153614', 'chihihi@gmail.com')
GO

INSERT INTO NHAN_VIEN(MaNV, HoTen, CCCD, GioiTinh, SDT, Email, DiaChi, NgayVao)
VALUES 
	('NV001', N'Nghiêm Vũ Hoàng Long', '001234567890', 1, '0987654321', 'hoanglong99@gmail.com', N'Hà Nội', '01/01/2024'),
	('NV002', N'Nguyễn Thảo Linh', '002345678901', 0, '0912345678', 'tlingcute@gmail.com', N'Hà Nội', '01/01/2024'),
	('NV003', N'Phạm Nam Hải', '003456789012', 1, '0976543210', 'wxrdie420@gmail.com', N'Hà Nội', '01/01/2024'),
	('NV004', N'Trần Tất Vũ', '004567890123', 1, '0901234567', 'vubigdd@gmail.com', N'Nam Định', '01/01/2024'),
	('NV005', N'Hoàng Quang Minh', '005678901234', 1, '0965432109', 'minhqh@gmail.com', N'Thái Bình', '01/01/2024'),
	('NV006', N'Hoàng Mai Anh', '006789012345', 0, '0932109876', 'maianhhoang@gmail.com', N'Thái Nguyên', '01/01/2024'),
	('NV007', N'Khúc Thị Hương', '007890123456', 0, '0945678901', 'huongtit@gmail.com', N'Hà Nội', '01/01/2024'),
	('NV008', N'Nguyễn Thanh Tùng', '008901234567', 1, '0956789012', 'tungmtp@gmail.com', N'Thái Bình', '01/01/2024'),
	('NV009', N'Lê Phương Trang', '009012345678', 0, '0921098765', 'chanhuwu@gmail.com', N'Hưng Yên', '01/01/2024'),
	('NV010', N'Trần Kim Ngân', '000123456789', 0, '0998765432', 'nganst@gmail.com', N'Hà Nội', '01/01/2024');
GO

INSERT INTO THE_KHTT (MaKHTT, MaKH, DiemTL, HSD, TrangThai, Hang)
VALUES
	('THE0000001', 'KH00000001', 15, '2025-01-01', N'Đang sử dụng', N'Vàng'),
	('THE0000002', 'KH00000002', 9, '2025-01-01', N'Đang sử dụng', N'Bạc'),
	('THE0000003', 'KH00000004', 15, '2025-01-08', N'Đang sử dụng', N'Vàng'),
	('THE0000004', 'KH00000005', 16, '2025-01-19', N'Đang sử dụng', N'Vàng'),
	('THE0000005', 'KH00000007', 25, '2025-02-27', N'Đang sử dụng', N'Kim cương'),
	('THE0000006', 'KH00000008', 10, '2025-03-08', N'Đang sử dụng', N'Vàng'),
	('THE0000007', 'KH00000009', 20, '2025-03-20', N'Đang sử dụng', N'Kim cương');
GO

INSERT INTO VOUCHER(MaVoucher, Loai, PhanTram)
VALUES 
	('H3J8K7L6P0M9N2Q', N'Voucher phòng', '30'),
	('R5T1Y2U0I8O6P41', N'Voucher phòng', '40'),
	('A9S8D7F6G3H1J21', N'Voucher phòng', '30'),
	('W0E1R2T3Y4U5I12', N'Voucher phòng', '55'),
	('B6N7M8J9K0L1I19', N'Voucher phòng', '30'),
	('Z3X5C7V9B2N4M12', N'Voucher dịch vụ', '40'),
	('F8G7H6J5K4L3I12', N'Voucher dịch vụ', '30'),
	('Q1W2E3R4T5Y6U34', N'Voucher dịch vụ', '40'),
	('O9I8U7Y6T5R4E34', N'Voucher dịch vụ', '30'),
	('D0F1G2H3J4K5L45', N'Voucher dịch vụ','60');
GO

INSERT INTO PHIEU_DAT_PHONG(MaPhieuDP, NgayLap, MaKH, MaNV, MaKHTT, MaVoucher)
VALUES 
	('PDP0000001', '01/01/2024', 'KH00000001', 'NV002', 'THE0000001', 'H3J8K7L6P0M9N2Q'),
	('PDP0000002', '01/01/2024', 'KH00000002', 'NV002', 'THE0000002', NULL),
	('PDP0000003', '01/02/2024', 'KH00000003', 'NV001', NULL, 'R5T1Y2U0I8O6P41'),
	('PDP0000004', '01/08/2024', 'KH00000004', 'NV004', 'THE0000003', NULL),
	('PDP0000005', '01/15/2024', 'KH00000005', 'NV003', 'THE0000004', 'A9S8D7F6G3H1J21'),
	('PDP0000006', '01/20/2024', 'KH00000001', 'NV003', 'THE0000001', NULL),
	('PDP0000007', '01/27/2024', 'KH00000006', 'NV004', NULL, NULL),
	('PDP0000008', '01/27/2024', 'KH00000007', 'NV001', 'THE0000005', 'W0E1R2T3Y4U5I12'),
	('PDP0000009', '02/01/2024', 'KH00000008', 'NV001', 'THE0000006', 'B6N7M8J9K0L1I19'),
	('PDP0000010', '02/09/2024', 'KH00000009', 'NV004', 'THE0000007', NULL);
GO

INSERT INTO PHIEU_DAT_COC(MaPhieuDC, NgayLap, PTTT, MaPhieuDP, MaNV)
VALUES 
	('PDC0000001', '01/01/2024', N'Tiền mặt', 'PDP0000001', 'NV002'),
	('PDC0000002', '01/01/2024', N'Tiền mặt', 'PDP0000002', 'NV002'),
	('PDC0000003', '01/02/2024', N'Chuyển khoản', 'PDP0000003', 'NV001'),
	('PDC0000004', '01/08/2024', N'Tiền mặt', 'PDP0000004', 'NV004'),
	('PDC0000005', '01/15/2024', N'Chuyển khoản', 'PDP0000005', 'NV003'),
	('PDC0000006', '01/20/2024', N'Chuyển khoản', 'PDP0000006', 'NV003'),
	('PDC0000007', '01/27/2024', N'Tiền mặt', 'PDP0000007', 'NV004'),
	('PDC0000008', '01/27/2024', N'Tiền mặt', 'PDP0000008', 'NV001'),
	('PDC0000009', '02/01/2024', N'Chuyển khoản', 'PDP0000009', 'NV001'),
	('PDC0000010', '02/09/2024', N'Chuyển khoản', 'PDP0000010', 'NV004');
GO

INSERT INTO CHI_TIET_DAT_PHONG(SoPhong, MaPhieuDP, NgayDen, NgayDi)
VALUES 
	(13, 'PDP0000001', '01/05/2024', '01/07/2024'),
	(22, 'PDP0000002', '01/03/2024', '01/05/2024'),
	(24, 'PDP0000003', '01/04/2024', '01/06/2024'),
	(34, 'PDP0000003', '01/04/2024', '01/06/2024'),
	(33, 'PDP0000004', '01/10/2024', '01/11/2024'),
	(24, 'PDP0000005', '01/25/2024', '01/27/2024'),
	(14, 'PDP0000006', '01/26/2024', '01/28/2024'),
	(31, 'PDP0000007', '02/05/2024', '02/07/2024'),
	(15, 'PDP0000008', '01/30/2024', '02/01/2024'),
	(21, 'PDP0000009', '02/10/2024', '02/12/2024'),
	(35, 'PDP0000010', '02/16/2024', '02/18/2024');
GO

INSERT INTO PHIEU_SU_DUNG_DICH_VU (MaPhieuSDDV, MaPhieuDP, NgayLap, MaNV, MaVoucher)
VALUES
	('PDV0000001', 'PDP0000002', '2024-01-04', 'NV005', null),
	('PDV0000002', 'PDP0000001', '2024-01-05', 'NV006', 'F8G7H6J5K4L3I12'),
	('PDV0000003', 'PDP0000001', '2024-01-06', 'NV007', null),
	('PDV0000004', 'PDP0000004', '2024-01-11', 'NV007', null),
	('PDV0000005', 'PDP0000006', '2024-01-27', 'NV006', 'Z3X5C7V9B2N4M12'),
	('PDV0000006', 'PDP0000006', '2024-01-28', 'NV005', null),
	('PDV0000007', 'PDP0000007', '2024-02-06', 'NV006', null),
	('PDV0000008', 'PDP0000008', '2024-01-31', 'NV005', 'Q1W2E3R4T5Y6U34'),
	('PDV0000009', 'PDP0000010', '2024-02-17', 'NV007', 'O9I8U7Y6T5R4E34'),
	('PDV0000010', 'PDP0000010', '2024-02-17', 'NV007', null);
GO
	
INSERT INTO DICH_VU (MaDV, TenDV, DVTinh, GiaNY)
VALUES
	('DV001', N'Nước khoáng Lavie', N'Chai', 10000),
	('DV002', N'Ăn chính', N'Xuất', 80000),
	('DV003', N'Buffet ngoài trời', N'Xuất', 200000),
	('DV004', N'Cắm trại đồi thông', N'Giờ', 80000),
	('DV005', N'Giặt ủi quần áo', N'Kg', 12000),
	('DV006', N'Trông giữ xe ô tô', N'Lượt', 15000),
	('DV007', N'Đưa đón sân bay', N'Lượt', 600000),
	('DV008', N'Tắm trà xanh', N'Khách', 300000),
	('DV009', N'Massage toàn thân', N'Khách', 400000),
	('DV010', N'Gội đầu dưỡng sinh', N'Khách', 300000);
GO

INSERT INTO CHI_TIET_SU_DUNG_DICH_VU (MaPhieuSDDV, MaDV, SoLuong, GiaBan)
VALUES
	('PDV0000001', 'DV005', 8, 12000),
	('PDV0000002', 'DV001', 4, 10000),
	('PDV0000002', 'DV002', 4, 80000),
	('PDV0000003', 'DV001', 10, 10000),
	('PDV0000003', 'DV002', 4, 80000),
	('PDV0000004', 'DV006', 1, 15000),
	('PDV0000005', 'DV001', 4, 10000),
	('PDV0000005', 'DV004', 4, 80000),
	('PDV0000006', 'DV003', 3, 200000),
	('PDV0000007', 'DV008', 2, 300000),
	('PDV0000008', 'DV009', 1, 400000),
	('PDV0000009', 'DV010', 1, 300000),
	('PDV0000010', 'DV007', 1, 600000);
GO


INSERT INTO PHIEU_NHAP_TIEN_NGHI (MaPhieuNhap, MaNV, NgayLap)
VALUES
	('PTN0000001', 'NV008', '2024-01-02'),
	('PTN0000002', 'NV009', '2024-01-02'),
	('PTN0000003', 'NV008', '2024-01-02'),
	('PTN0000004', 'NV009', '2024-01-15'),
	('PTN0000005', 'NV008', '2024-01-15'),
	('PTN0000006', 'NV009', '2024-01-31'),
	('PTN0000007', 'NV010', '2024-02-15');
GO

INSERT INTO NHA_CUNG_CAP(MaNCC, TenNCC)
VALUES 
	('NCC01', N'Công ty TNHH Colgate'),
	('NCC02', N'Tổng công ty CP may Sông Hồng'),
	('NCC03', N'Công ty CP Thế Giới Di Động'),
	('NCC04', N'Công ty Falcon');
GO

INSERT INTO TIEN_NGHI(MaTN, TenTN, MaNCC, Gia)
VALUES
	('TN001', N'Bàn chải đánh răng', 'NCC01', 10000),
	('TN002', N'Kem đánh răng', 'NCC01', 7000),
	('TN003', N'Khăn tắm', 'NCC02', 25000),
	('TN004', N'Dép', 'NCC04', 20000),
	('TN005', N'Chăn gối', 'NCC02', 250000),
	('TN006', N'TV', 'NCC03', 5000000),
	('TN007', N'Tủ lạnh mini', 'NCC03', 1000000),
	('TN008', N'Giường', 'NCC03', 2500000),
	('TN009', N'Máy sấy', 'NCC03', 500000),
	('TN010', N'Ấm siêu tốc', 'NCC03', 600000);
GO

INSERT INTO CHI_TIET_NHAP_TIEN_NGHI (MaPhieuNhap, MaTN, SoLuong, DVTinh)
VALUES
	('PTN0000001', 'TN001', 20, N'Chiếc'),
	('PTN0000002', 'TN003', 20, N'Chiếc'),
	('PTN0000003', 'TN003', 40, N'Chiếc'),
	('PTN0000004', 'TN005', 10, N'Bộ'),
	('PTN0000005', 'TN009', 5, N'Chiếc'),
	('PTN0000006', 'TN007', 5, N'Chiếc'),
	('PTN0000007', 'TN010', 5, N'Chiếc');
GO


INSERT INTO PHIEU_BOI_THUONG_THIET_HAI (MaPhieuBTTH, MaPhieuDP, NgayLap, MaNV)
VALUES
	('PBT0000001', 'PDP0000001', '2024-01-06', 'NV008'),
	('PBT0000002', 'PDP0000002', '2024-01-04', 'NV009'),
	('PBT0000003', 'PDP0000003', '2024-01-05', 'NV008'),
	('PBT0000004', 'PDP0000006', '2024-01-27', 'NV009'),
	('PBT0000005', 'PDP0000007', '2024-02-05', 'NV008'),
	('PBT0000006', 'PDP0000009', '2024-02-11', 'NV009'),
	('PBT0000007', 'PDP0000010', '2024-02-16', 'NV010');
GO

INSERT INTO CHI_TIET_BOI_THUONG_THIET_HAI (MaPhieuBTTH, MaTN, SoLuong, DVTinh)
VALUES
	('PBT0000001', 'TN006', 1, N'Chiếc'),
	('PBT0000002', 'TN009', 1, N'Chiếc'),
	('PBT0000003', 'TN005', 1, N'Bộ'),
	('PBT0000004', 'TN005', 2, N'Bộ'),
	('PBT0000005', 'TN005', 1, N'Bộ'),
	('PBT0000006', 'TN010', 1, N'Chiếc'),
	('PBT0000007', 'TN010', 1, N'Chiếc');
GO

INSERT INTO CA_LAM(TenCa, KhungGio)            
VALUES 
	(N'Sáng', '6:00 - 12:00'),
	(N'Chiều', '12:00 - 18:00'),
	(N'Tối', '18:00 - 00:00'),
	(N'Đêm', '00:00 - 6:00');
GO

INSERT INTO SO_CHAM_CONG(MaCC, MaNV, TenCa, NgayCham, GioBD, GioKT)
VALUES 
	('CC00000001', 'NV001', N'Sáng', '01/02/2024', '6:02', '12:10'),
	('CC00000002', 'NV003', N'Sáng', '01/02/2024', '6:00', '12:05'),
	('CC00000003', 'NV005', N'Sáng', '01/02/2024', '6:03', '12:00'),
	('CC00000004', 'NV002', N'Chiều', '01/02/2024', '12:01', '18:02'),
	('CC00000005', 'NV004', N'Chiều', '01/02/2024', '12:00', '18:00'),
	('CC00000006', 'NV006', N'Chiều', '01/02/2024', '12:00', '18:03'),
	('CC00000007', 'NV009', N'Tối', '01/02/2024', '18:02', '00:02'),
	('CC00000008', 'NV010', N'Tối', '01/02/2024', '18:02', '00:05'),
	('CC00000009', 'NV007', N'Đêm', '01/03/2024', '00:00', '6:00'),
	('CC00000010', 'NV008', N'Đêm', '01/03/2024', '00:02', '6:04'),
	('CC00000011', 'NV001', N'Sáng', '01/03/2024', '6:02', '12:10'),
	('CC00000012', 'NV005', N'Sáng', '01/03/2024', '6:00', '12:05'),
	('CC00000013', 'NV009', N'Sáng', '01/03/2024', '6:03', '12:00'),
	('CC00000014', 'NV004', N'Chiều', '01/03/2024', '12:01', '18:02'),
	('CC00000015', 'NV001', N'Chiều', '01/03/2024', '12:00', '18:00'),
	('CC00000016', 'NV008', N'Chiều', '01/03/2024', '12:00', '18:03'),
	('CC00000017', 'NV004', N'Tối', '01/03/2024', '18:02', '00:02'),
	('CC00000018', 'NV003', N'Tối', '01/03/2024', '18:02', '00:05'),
	('CC00000019', 'NV004', N'Đêm', '01/04/2024', '00:00', '6:00'),
	('CC00000020', 'NV007', N'Đêm', '01/04/2024', '00:02', '6:04');
GO

SELECT * FROM PHONG
SELECT * FROM HANG_PHONG
SELECT * FROM LOAI_PHONG
SELECT * FROM PHIEU_DAT_PHONG
SELECT * FROM PHIEU_DAT_COC
SELECT * FROM CHI_TIET_DAT_PHONG
ORDER BY MaPhieuDP ASC
SELECT * FROM PHIEU_SU_DUNG_DICH_VU
ORDER BY MaPhieuDP ASC
SELECT * FROM CHI_TIET_SU_DUNG_DICH_VU
SELECT * FROM DICH_VU
SELECT * FROM PHIEU_NHAP_TIEN_NGHI
SELECT * FROM CHI_TIET_NHAP_TIEN_NGHI
SELECT * FROM TIEN_NGHI
SELECT * FROM PHIEU_BOI_THUONG_THIET_HAI
SELECT * FROM CHI_TIET_BOI_THUONG_THIET_HAI
SELECT * FROM KHACH_HANG
SELECT * FROM THE_KHTT
SELECT * FROM NHA_CUNG_CAP
SELECT * FROM VOUCHER
SELECT * FROM NHAN_VIEN
SELECT * FROM SO_CHAM_CONG
SELECT * FROM CA_LAM

--- Liệt kê các phòng còn trống với hạng phòng Standard
SELECT * FROM PHONG P
WHERE P.TrangThai = N'Trống' AND P.MaHangPhong = 'STD'

--- Đưa ra các phiếu đặt phòng sử dụng voucher
SELECT * FROM PHIEU_DAT_PHONG
WHERE MaVoucher IS NOT NULL

--- Đưa ra các phòng được đặt vào ngày 05/01/2024
SELECT * FROM CHI_TIET_DAT_PHONG CTDP 
WHERE CTDP.NgayDen <= '01/05/2024' AND CTDP.NgayDi >= '01/05/2024'

--- Liệt kê các phòng còn trống
SELECT * FROM PHONG P
WHERE P.TrangThai = N'Trống'

--- Cho biết các phòng hạng Superior có 2 giường đơn còn trống
SELECT * FROM PHONG P JOIN LOAI_PHONG LP ON P.MaLoaiPhong = LP.MaLoaiPhong JOIN HANG_PHONG HP ON P.MaHangPhong = HP.MaHangPhong
WHERE HP.TenHangPhong = 'Superior' AND LP.TenLoaiPhong = N'2 giường đơn' AND P.TrangThai = N'Trống'

--- Tính tổng số tiền đặt phòng phải trả của 1 phiếu đặt phòng (sau khi apply voucher và trừ tiền đặt cọc)
SELECT
    CTDP.MaPhieuDP,
    SUM((((LP.GiaLoai + HP.GiaHang) * DATEDIFF(day, CTDP.NgayDen, CTDP.NgayDi)) * (1 - (ISNULL(VC.PhanTram, 0) * 0.01))))/2 AS TongTienDatPhong
FROM
    CHI_TIET_DAT_PHONG CTDP
INNER JOIN
    PHIEU_DAT_PHONG PDP ON CTDP.MaPhieuDP = PDP.MaPhieuDP
LEFT JOIN
    VOUCHER VC ON PDP.MaVoucher = VC.MaVoucher
INNER JOIN
    PHONG P ON CTDP.SoPhong = P.SoPhong
INNER JOIN
    LOAI_PHONG LP ON P.MaLoaiPhong = LP.MaLoaiPhong
INNER JOIN
    HANG_PHONG HP ON P.MaHangPhong = HP.MaHangPhong
GROUP BY
	CTDP.MaPhieuDP
ORDER BY
	CTDP.MaPhieuDP;

-- Tính tổng tiền sử dụng dịch vụ của 1 phiếu đặt phòng
SELECT
	PSDDV.MaPhieuDP,
    SUM((CTSDDV.SoLuong * CTSDDV.GiaBan) * (1 - (ISNULL(VC.PhanTram, 0) * 0.01))) AS TongTienSDDV
FROM
    PHIEU_SU_DUNG_DICH_VU PSDDV
LEFT JOIN
    VOUCHER VC ON PSDDV.MaVoucher = VC.MaVoucher
INNER JOIN
    CHI_TIET_SU_DUNG_DICH_VU CTSDDV ON PSDDV.MaPhieuSDDV = CTSDDV.MaPhieuSDDV
GROUP BY
	PSDDV.MaPhieuDP
ORDER BY
	PSDDV.MaPhieuDP

--- Tính tiền bồi thường thiệt hại của 1 phiếu đặt phòng
SELECT
	PBTTH.MaPhieuDP,
	SUM((CTBTTH.SoLuong * Gia)) AS TongBoiThuongThietHai
FROM
	CHI_TIET_BOI_THUONG_THIET_HAI CTBTTH
INNER JOIN
	PHIEU_BOI_THUONG_THIET_HAI PBTTH ON CTBTTH.MaPhieuBTTH = PBTTH.MaPhieuBTTH
LEFT JOIN
	TIEN_NGHI TN ON CTBTTH.MaTN = TN.MaTN
GROUP BY
	PBTTH.MaPhieuDP

--- Tính tổng tiền phải thanh toán của 1 phiếu đặt phòng (sau khi apply các voucher và trừ đi tiền cọc)
WITH TongTienDatPhong AS (
    SELECT
        CTDP.MaPhieuDP,
        SUM((((LP.GiaLoai + HP.GiaHang) * DATEDIFF(day, CTDP.NgayDen, CTDP.NgayDi)) * (1 - (ISNULL(VC.PhanTram, 0) * 0.01)))) AS TongTienDatPhong
    FROM
        CHI_TIET_DAT_PHONG CTDP
    INNER JOIN
        PHIEU_DAT_PHONG PDP ON CTDP.MaPhieuDP = PDP.MaPhieuDP
    LEFT JOIN
        VOUCHER VC ON PDP.MaVoucher = VC.MaVoucher
    INNER JOIN
        PHONG P ON CTDP.SoPhong = P.SoPhong
    INNER JOIN
        LOAI_PHONG LP ON P.MaLoaiPhong = LP.MaLoaiPhong
    INNER JOIN
        HANG_PHONG HP ON P.MaHangPhong = HP.MaHangPhong
    GROUP BY
        CTDP.MaPhieuDP
),
TongTienDichVu AS (
    SELECT
        PSDDV.MaPhieuDP,
        SUM((CTSDDV.SoLuong * CTSDDV.GiaBan) * (1 - (ISNULL(VC.PhanTram, 0) * 0.01))) AS TongTienSDDV
    FROM
        PHIEU_SU_DUNG_DICH_VU PSDDV
    LEFT JOIN
        VOUCHER VC ON PSDDV.MaVoucher = VC.MaVoucher
    INNER JOIN
        CHI_TIET_SU_DUNG_DICH_VU CTSDDV ON PSDDV.MaPhieuSDDV = CTSDDV.MaPhieuSDDV
    GROUP BY
        PSDDV.MaPhieuDP
),
TongBoiThuongThietHai AS (
    SELECT
        PBTTH.MaPhieuDP,
        SUM((CTBTTH.SoLuong * Gia)) AS TongBoiThuongThietHai
    FROM
        CHI_TIET_BOI_THUONG_THIET_HAI CTBTTH
    INNER JOIN
        PHIEU_BOI_THUONG_THIET_HAI PBTTH ON CTBTTH.MaPhieuBTTH = PBTTH.MaPhieuBTTH
    LEFT JOIN
        TIEN_NGHI TN ON CTBTTH.MaTN = TN.MaTN
    GROUP BY
        PBTTH.MaPhieuDP
)
SELECT
    TTDP.MaPhieuDP,
    ISNULL(TTDP.TongTienDatPhong, 0)/2 + ISNULL(TTDV.TongTienSDDV, 0) + ISNULL(TBTTH.TongBoiThuongThietHai, 0) AS TongTienPhaiThanhToan
FROM
    TongTienDatPhong TTDP
LEFT JOIN
    TongTienDichVu TTDV ON TTDP.MaPhieuDP = TTDV.MaPhieuDP
LEFT JOIN
    TongBoiThuongThietHai TBTTH ON TTDP.MaPhieuDP = TBTTH.MaPhieuDP;

--- Thêm 1 khách hàng mới
INSERT INTO KHACH_HANG(MaKH, TenKH, CCCD, QuocTich, SDT, Email)
VALUES 
	('KH00000010', N'Fedor Gorst', '927364518', N'Mỹ', '4155550192', 'gorstfusa@gmail.com');

--- Liệt kê các khách hàng có quốc tịch không phải Việt Nam
SELECT * FROM KHACH_HANG KH
WHERE KH.QuocTich != N'Việt Nam'

--- Liệt kê lịch sử đặt phòng của khách hàng có mã khách hàng KH00000001
SELECT PDP.MaKH, PDP.MaPhieuDP, CTDP.SoPhong, CTDP.NgayDen, CTDP.NgayDi
FROM PHIEU_DAT_PHONG PDP JOIN CHI_TIET_DAT_PHONG CTDP ON PDP.MaPhieuDP = CTDP.MaPhieuDP
WHERE PDP.MaKH = 'KH00000001'

--- Cho biết các dịch vụ mà khách hàng KH00000001 sử dụng vào ngày 05/01/2024
SELECT PDP.MaKH, PSDDV.MaPhieuDP, PSDDV.MaPhieuSDDV, CTSDDV.MaDV, DV.TenDV, CTSDDV.SoLuong
FROM PHIEU_SU_DUNG_DICH_VU PSDDV JOIN CHI_TIET_SU_DUNG_DICH_VU CTSDDV ON PSDDV.MaPhieuSDDV = CTSDDV.MaPhieuSDDV
	JOIN DICH_VU DV ON CTSDDV.MaDV = DV.MaDV
	JOIN PHIEU_DAT_PHONG PDP ON PSDDV.MaPhieuDP = PDP.MaPhieuDP
WHERE PDP.MaKH = 'KH00000001'
AND PSDDV.NgayLap = '01/05/2024'

--- Đưa ra các phiếu đặt phòng phải bồi thường thiệt hại
SELECT PDP.MaPhieuDP
FROM PHIEU_DAT_PHONG PDP JOIN PHIEU_BOI_THUONG_THIET_HAI PBTTH ON PDP.MaPhieuDP = PBTTH.MaPhieuDP;

--- Đưa ra danh sách khách hàng sở hữu thẻ KHTT hạng kim cương
SELECT KH.MaKH, KH.TenKH, T.MaKHTT, T.Hang
FROM THE_KHTT T JOIN KHACH_HANG KH ON T.MaKH = KH.MaKH
WHERE T.Hang = N'Kim cương'

--- Liệt kê các Thẻ Khách hàng thân thiết hết hạn trước 2026
SELECT *
FROM THE_KHTT T
WHERE T.HSD < '01/01/2026'

--- Cộng thêm 5 điểm tích lũy cho những thẻ KHTT hạng vàng
UPDATE THE_KHTT
SET DiemTL = DiemTL + 5
WHERE Hang = N'Vàng'

--- Đưa ra các dịch vụ của khách sạn
SELECT * FROM DICH_VU

---- Liệt kê các phiếu đặt phòng có tổng hóa đơn sử dụng dịch vụ lớn hơn 100000 đồng
SELECT PSDDV.MaPhieuSDDV
FROM PHIEU_SU_DUNG_DICH_VU PSDDV 
JOIN (SELECT *,(SoLuong * GiaBan) AS ThanhTien
	  FROM CHI_TIET_SU_DUNG_DICH_VU) AS CTSDDV
		 ON PSDDV.MaPhieuSDDV = CTSDDV.MaPhieuSDDV
WHERE ThanhTien > 100000

--- Thêm nhân viên mới
INSERT INTO NHAN_VIEN(MaNV, HoTen, CCCD, GioiTinh, SDT, Email, DiaChi, NgayVao)
VALUES 
	('NV011', N'Nguyễn Anh Hào', '004574630123', 1, '0901207537', 'mikehao@gmail.com', N'Thái Nguyên', '19/01/2024');

--- Liệt kê các nhân viên Nam vào làm trước 05/01/2024
SELECT * FROM NHAN_VIEN
WHERE GioiTinh = 1 AND NgayVao < '01/05/2024'

--- Liệt kê các nhân viên làm ca sáng ngày 02/01/2024
SELECT NHAN_VIEN.MaNV, HoTen 
FROM (SELECT * FROM SO_CHAM_CONG
	  WHERE TenCa = N'Sáng' AND NgayCham = '01/02/2024') AS SCC 
JOIN NHAN_VIEN ON SCC.MaNV = NHAN_VIEN.MaNV

--- Tính lương tháng 01/2024 của tất cả nhân viên với mức lương 300k/1 ca
SELECT MaNV, (COUNT(*) * 300000) AS Luong FROM SO_CHAM_CONG
WHERE NgayCham >= '01/01/2024' AND NgayCham <= '02/01/2024'
GROUP BY MaNV

--- Liệt kê các tiện nghi được nhập từ nhà cung cấp có mã nhà cung cấp là NCC03
SELECT TenTN
FROM 
	TIEN_NGHI
WHERE MaNCC = 'NCC03'

--- Liệt kê các tiện nghi cần phải bồi thường ngày 05/01/2024
SELECT 
	TN.MaTN,
	TN.TenTN,
	CTBTTH.SoLuong,
	CTBTTH.DVTinh
FROM 
	TIEN_NGHI TN
JOIN
	CHI_TIET_BOI_THUONG_THIET_HAI CTBTTH ON TN.MaTN = CTBTTH.MaTN
JOIN 
	PHIEU_BOI_THUONG_THIET_HAI PBTTH ON CTBTTH.MaPhieuBTTH = PBTTH.MaPhieuBTTH
WHERE PBTTH.NgayLap = '2024-01-05';

--- Tính tổng thiệt hại
SELECT
	SUM(CTBTTH.SoLuong * TN.Gia) AS TongThietHai
FROM 
	TIEN_NGHI TN
JOIN
	CHI_TIET_BOI_THUONG_THIET_HAI CTBTTH ON TN.MaTN = CTBTTH.MaTN
JOIN 
	PHIEU_BOI_THUONG_THIET_HAI PBTTH ON CTBTTH.MaPhieuBTTH = PBTTH.MaPhieuBTTH

--- Thống kê doanh thu tháng 01/2024(doanh thu = tiền phòng + tiền dịch vụ)
WITH TongTienPhong AS (
	SELECT
		SUM((HP.GiaHang + LP.GiaLoai) * (1 - (ISNULL(VC.PhanTram, 0) * 0.01))) AS TongTienPhong
	FROM
		CHI_TIET_DAT_PHONG CTDP
	INNER JOIN
		PHIEU_DAT_PHONG PDP ON PDP.MaPhieuDP = CTDP.MaPhieuDP
	INNER JOIN
		PHONG P ON CTDP.SoPhong = P.SoPhong
	LEFT JOIN
		LOAI_PHONG LP ON LP.MaLoaiPhong = P.MaLoaiPhong
	LEFT JOIN
		HANG_PHONG HP ON HP.MaHangPhong = P.MaHangPhong
	INNER JOIN
		VOUCHER VC ON PDP.MaVoucher = VC.MaVoucher
	WHERE
		MONTH(CTDP.NgayDi) = 1 AND YEAR(CTDP.NgayDi) = 2024
),
TongTienDichVu AS (
	SELECT
		SUM((CTSDDV.SoLuong * DV.GiaNY) * (1 - ISNULL(VC.PhanTram, 0) * 0.01)) AS TongTienDichVu
	FROM
		CHI_TIET_SU_DUNG_DICH_VU CTSDDV
	INNER JOIN
		PHIEU_SU_DUNG_DICH_VU PSDDV ON PSDDV.MaPhieuSDDV = CTSDDV.MaPhieuSDDV
	LEFT JOIN
		DICH_VU DV ON CTSDDV.MaDV = DV.MaDV
	LEFT JOIN
		VOUCHER VC ON VC.MaVoucher = PSDDV.MaVoucher
	WHERE
		MONTH(PSDDV.NgayLap) = 1 AND YEAR(PSDDV.NgayLap) = 2024
)
SELECT
	(SELECT TongTienPhong FROM TongTienPhong) + (SELECT TongTienDichVu FROM TongTienDichVu) AS TongDoanhThuThang

--- Cho biết hạng phòng có tỷ lệ đặt cao nhất trong tháng 01/2024
WITH ThongKeHangPhong AS (
    SELECT
        HP.TenHangPhong,
        COUNT(*) AS SoLuong
    FROM
        CHI_TIET_DAT_PHONG CTDP
    INNER JOIN
        PHONG P ON CTDP.SoPhong = P.SoPhong
    INNER JOIN
        HANG_PHONG HP ON HP.MaHangPhong = P.MaHangPhong
    WHERE
        MONTH(CTDP.NgayDi) = 1 AND YEAR(CTDP.NgayDi) = 2024
    GROUP BY
        HP.TenHangPhong
)
SELECT TOP 1
    TenHangPhong
FROM
    ThongKeHangPhong
ORDER BY
    SoLuong DESC