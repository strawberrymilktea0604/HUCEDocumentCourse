-- Tình trạng giao hàng và người giao hàng
SELECT 
    HD.MaHD,
    KH.TenNhaHang,
    MH.TenMH,
    XK.NgayXuat,
    XK.SoLuong,
    NV.HoTen AS NhanVienGiao,
    CASE 
        WHEN XK.MaXuat IS NOT NULL THEN 'Đã giao'
        ELSE 'Chưa giao'
    END AS TinhTrangGiao
FROM HOP_DONG HD
JOIN KHACHHANG KH ON HD.MaKH = KH.MaKH
JOIN MAT_HANG MH ON HD.MaMH = MH.MaMH
LEFT JOIN XUAT_KHO XK ON HD.MaHD = XK.MaHD
LEFT JOIN NHANVIEN_GIAO_HANG NV ON XK.MaNV = NV.MaNV;