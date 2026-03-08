CREATE DATABASE QLDiemSV_67ITCS
Go
USE QLDiemSV_67ITCS
Go

Create table DMKHOA (
MaKhoa char(2) constraint PK_Khoa primary key, 
TenKhoa nVarChar(20)
)
Go
Create  table DMMH (
MaMH char(2) constraint PK_DMMH primary key, 
TenMH nVarchar(30),
SoTiet Tinyint,
)
Go
create table DMSV (
MaSV char(3) constraint PK_DMSV primary key, 
HoSV nvarchar(30),
TenSV Nvarchar(10), 
Phai bit,
NgaySinh Datetime, 
NoiSinh nvarchar(25), 
MaKH char(2) constraint  FK_DMSV_DMKHOA  foreign  key(MaKH) references  DMKHOA(MaKhoa),
HocBong float,
)
Go
Create table KETQUA (
MaSV char (3),
MaMH char (2), LanThi Tinyint, 
Diem  Decimal(4,2),
constraint  PK_KetQua  primary  key  (MaSV,MaMH,LanThi),
constraint FK_KetQua_SinhVien foreign  key(masv) references  DMSV(MaSV), 
constraint FK_KetQua_DMMH foreign  key(MaMH)  references DMMH(MaMH)
)
Go

--
-- Thêm dữ liệu
INSERT INTO DMKHOA 
VALUES ('AV', N'Anh Văn'),('TH',N'Tin Học'),('TR',N'Triết'),('VL',N'Vật lý')
Go
INSERT INTO DMMH VALUES
('01',N'Cơ sở dữ liệu',45),('02',N'Trí tuệ nhân tạo',45),
('03',N'Lý thuyết truyền tin',45),('04',N'Đồ họa',60),
('05',N'Văn phạm',60),('06',N'Kỹ thuật lập trình',45)
INSERT INTO DMSV VALUES
('A01',	N'Nguyễn Thị', N'Hải',0,'02/23/1993',N'Hà Nội','TH',130000),	
('A02',	N'Trần Văn', N'Chính',1,'12/24/1992',N'Bình Định','VL',150000),
('A03',	N'Lê Thu Bạch', N'Yến',0,'02/21/1993',N'TPHCM','TH',170000),
('A04',	N'Trần Anh', N'Tuấn',1,'12/20/1994',N'Hà Nội','AV',80000),
('B01',	N'Trần Thanh', N'Mai',0,'08/12/1993',N'Hải Phòng','TR',0),
('B02',	N'Trần Thị Thu', N'Thủy',0,'01/02/1994',N'TPHCM','AV',0)
INSERT INTO KETQUA VALUES
('A01',	'01',1,3),
('A01',	'01',2,6),
('A01',	'02',2,6),
('A01',	'03',1,5),
('A02',	'01',1,4.5),
('A02',	'01',2,7),
('A02',	'03',1,10),
('A02',	'05',1,9),
('A03',	'01',1,2),
('A03',	'01',2,5),
('A03',	'03',1,2.5),
('A03',	'03',2,4),
('A04',	'05',2,10),
('B01',	'01',1,7),
('B01',	'03',1,2.5),
('B01',	'03',2,5),
('B02',	'02',1,6),
('B02',	'04',1,10)
Go
sp_tables
sp_columns KETQUA
sp_pkeys KETQUA
sp_helpconstraint KETQUA
