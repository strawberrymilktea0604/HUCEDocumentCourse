USE quanlycungcapthucpham;

-- KHACHHANG
INSERT INTO KHACHHANG (TenNhaHang, NguoiDaiDien, DiaChi, SDT, Email) VALUES
('Nhà hàng A', 'Nguyễn Văn A', '123 Lê Lợi, Quận 1', '0912345678', 'a@example.com'),
('Nhà hàng B', 'Trần Thị B', '456 Nguyễn Trãi, Quận 5', '0987654321', 'b@example.com');

-- MAT_HANG
INSERT INTO MAT_HANG (TenMH, MoTa, DonViTinh, GiaBan) VALUES
('Thịt bò Úc', 'Thịt bò nhập khẩu loại 1', 'kg', 250000),
('Cá hồi Nauy', 'Cá hồi tươi nguyên con', 'kg', 400000);

-- NHA_CUNG_CAP
INSERT INTO NHA_CUNG_CAP (TenNCC, DiaChi, SDT) VALUES
('Công ty Thịt Nhập Khẩu', '789 Phạm Văn Đồng', '0909123456'),
('Công ty Hải Sản Biển', '321 Trường Chinh', '0934567890');

-- NHAP_KHO
INSERT INTO NHAP_KHO (MaMH, MaNCC, NgayNhap, SoLuong, HanSuDung) VALUES
(1, 1, '2025-06-01', 100, '2025-07-01'),
(2, 2, '2025-06-01', 50, '2025-06-25');

-- TON_KHO
INSERT INTO TON_KHO (MaMH, SoLuongTon, HanSuDungGanNhat) VALUES
(1, 100, '2025-07-01'),
(2, 50, '2025-06-25');

-- HOP_DONG
INSERT INTO HOP_DONG (MaKH, MaMH, NgayBatDau, NgayKetThuc, DiaChiGiao) VALUES
(1, 1, '2025-06-01', '2025-06-30', '123 Lê Lợi, Quận 1'),
(2, 2, '2025-06-01', '2025-07-15', '456 Nguyễn Trãi, Quận 5');

-- LICH_GIAO_HANG
INSERT INTO LICH_GIAO_HANG (MaHD, ThuTrongTuan, GioGiao, ChuKy) VALUES
(1, 'Thứ 2', '07:00:00', 'Sáng'),
(1, 'Thứ 2', '17:00:00', 'Chiều'),
(2, 'Thứ 4', '08:00:00', 'Sáng');

-- NHANVIEN_GIAO_HANG
INSERT INTO NHANVIEN_GIAO_HANG (HoTen, SDT) VALUES
('Nguyễn Giao Hàng', '0901122334'),
('Trần Giao Hàng', '0909988776');

-- XUAT_KHO
INSERT INTO XUAT_KHO (MaHD, NgayXuat, SoLuong, MaNV) VALUES
(1, '2025-06-03', 10, 1),
(2, '2025-06-05', 5, 2);

-- THANH_TOAN
INSERT INTO THANH_TOAN (MaHD, TongTien, TinhTrang, HinhThuc) VALUES
(1, 2500000, 'Đã thanh toán', 'Chuyển khoản'),
(2, 2000000, 'Chưa thanh toán', 'Tiền mặt');