-- Lịch giao hàng chi tiết theo từng hợp đồng
SELECT 
    HD.MaHD,
    KH.TenNhaHang,
    MH.TenMH,
    LGH.ThuTrongTuan,
    LGH.GioGiao,
    LGH.ChuKy
FROM LICH_GIAO_HANG LGH
JOIN HOP_DONG HD ON LGH.MaHD = HD.MaHD
JOIN KHACHHANG KH ON HD.MaKH = KH.MaKH
JOIN MAT_HANG MH ON HD.MaMH = MH.MaMH;