-- Ngôn ngữ SQL
-- 1. Ngôn ngữ định nghĩa dữ liệu (DDL)
-- 2. Ngôn ngữ thao tác dữ liệu (DML)
-- 3. Ngôn ngữ điều khiển dữ liệu (DCL)
Phạm vi môn học : Học nhóm câu lệnh trong 1, 2
-- Buổi học tuần trước
-- Ngôn ngữ định nghĩa dữ liệu DDL 
--1. Tạo CSDL CREATE DATABASE
--2. Tạo bảng CREATE TABLE (tìm hiểu cách thức đ/n thuộc tính, datatype, ràng buộc cơ bản)
--3. Ràng buộc cần thiết lập trong bảng CONSTRAINT
-- Cú pháp
      CONSTRAINT <Tên ràng buộc> Kiểu ràng buộc 
	--3.1 Ràng buộc khóa chính (PRIMARY KEY) - phân biệt giữa các dòng trong 1 bảng
	-- Một dòng ~ thực thể cụ thể (thực tế)
	-- Khóa chính : 1 thuộc tính, kết hợp nhiều thuộc tính 
	-- Việc đặt tên cho các ràng buộc
	--3.2 Ràng buộc khóa ngoài (FOREIGN KEY) - kiểm tra tính phụ thuộc tồn tại
	-- cú pháp:
		CONSTRAINT <tên ràng buộc khóa ngoại> FOREIGN KEY <Thuộc tính được chỉ định làm khóa ngoại> 
													REFERENCES <Tên bảng tham chiếu> (Tên cột tham chiếu)
	-- 3.3 Ràng buộc kiểm tra CHECK (kiểm tra giá trị miền)
	-- Cú pháp: CONSTRAINT <Tên ràng buộc> CHECK( Điều kiện kiểm tra tính chính xác và phù hợp của dữ liệu)
	-- 3.4 Ràng buộc DEFAULT 
	-- 3.5 Ràng buộc tính duy nhất giá trị UNIQUE
-- 4. Các câu lệnh sửa đổi thông tin trên bảng
	--Cú pháp: ALTER TABLE <bảng nào> 
				<Hành động sửa đổi trên bảng đó>
	-- Hành động:

		--4.1. Thêm cột mới vào bảng
			ALTER TABLE <tên bảng> 
			ADD COLUMN <tên cột> <kiểu dữ liệu> [NOT NULL];
		--4.2 Xoá cột trong 1 bảng
			ALTER TABLE <tên bảng> 
			DROP COLUMN <tên cột>; 
		--4.3 Sửa kiểu dữ liệu của một bảng
			ALTER TABLE <tên bảng> 
			CHANGE COLUMN <tên cột> TO <kiểu dữ liệu mới>;
		--4.4 Thêm ràng buộc
			ALTER TABLE <tên bảng> 
			ADD CONSTRAINT <tên ràng buộc> <kiểu ràng buộc>
		--4.5 Xóa ràng buộc
			ALTER TABLE <tên bảng> 
      		DROP CONSTRAINT <tên ràng buộc>


Go

CREATE TABLE t_SV(
	[MaSV] [char](10) NOT NULL,
	[TenSV] [nvarchar](50) NULL,
	[GT] [bit] NULL,
	[NS] [date] NULL,
	[QQ] [nvarchar](30) DEFAULT N'Hà Nội',
	[DiemTT] [float] CONSTRAINT Ktra_DiemTT CHECK(DiemTT>=20 AND DiemTT <=30),
	[NgayNT] [date] DEFAULT Getdate(),
	[HB] [int] CONSTRAINT Ktra_HB CHECK ([HB] IN(0,1000000,2000000,5000000,6000000)),
	SoCCCD char(12) CONSTRAINT CCCD_NoDUP UNIQUE(SoCCCD),
	[ML] [char](3) NULL,
CONSTRAINT KC PRIMARY KEY ([MaSV]),
CONSTRAINT KN_SV FOREIGN KEY (ML) REFERENCES t_Lop (MaL),
CONSTRAINT Ktra CHECK(Year(NgayNT) >Year(NS))
)
--
Go

 DROP TABLE t_KQHT
 -- Chỉ định khóa ngoại cho bảng t_KQHT:
 CREATE TABLE [t_KQHT](
	[MaSV] [char](10) NOT NULL,
	[MaMHoc] [char](6) NOT NULL,
	[NgayDK] [date] NOT NULL,
	[DQT] [float] CONSTRAINT KtraDQT CHECK(DQT>=0 AND DQT <=10),
	[DKT] [float] CONSTRAINT KtraDKT CHECK(DKT>=0 AND DKT <=10),
 CONSTRAINT [KV_KQHT] PRIMARY KEY([MaSV],[MaMHoc],[NgayDK]),
 CONSTRAINT FK_KQHT_MaSV FOREIGN KEY (MaSV) REFERENCES t_SV(MaSV), CONSTRAINT FK_KQHT_MaMHoc FOREIGN KEY (MaMHoc) REFERENCES t_MonHoc(MaMH)
 )
 DROP TABLE t_SV
 -- Câu lệnh để xóa ràng buộc
 ALTER TABLE <Tên bảng> DROP CONSTRAINT <Tên ràng buộc>
 ALTER TABLE t_KQHT DROP CONSTRAINT FK_KQHT_MaSV

 -- Ví dụ các câu lệnh sửa đổi
 ALTER TABLE t_Lop
 ADD Ghichu nvarchar(200) null 
 --
 ALTER TABLE t_Lop
 ALTER COLUMN Khoa char(13)
 --
 ALTER TABLE t_Lop
 DROP COLUMN Ghichu




