-- Kiểm tra tồn kho hiện tại
SELECT 
    MH.TenMH,
    TK.SoLuongTon,
    TK.HanSuDungGanNhat
FROM TON_KHO TK
JOIN MAT_HANG MH ON TK.MaMH = MH.MaMH;