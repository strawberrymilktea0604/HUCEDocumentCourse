-- Tổng tiền mỗi hợp đồng đã giao
SELECT 
    HD.MaHD,
    KH.TenNhaHang,
    MH.TenMH,
    SUM(XK.SoLuong * MH.GiaBan) AS TongTien
FROM HOP_DONG HD
JOIN KHACHHANG KH ON HD.MaKH = KH.MaKH
JOIN MAT_HANG MH ON HD.MaMH = MH.MaMH
JOIN XUAT_KHO XK ON HD.MaHD = XK.MaHD
GROUP BY HD.MaHD, KH.TenNhaHang, MH.TenMH;