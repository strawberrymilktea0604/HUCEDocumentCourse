const jwt = require('jsonwebtoken');
const User = require('../models/User'); // Gọi Model User để kiểm tra tồn tại

const protect = async (req, res, next) => {
    let token;

    // --- BƯỚC 1: TÌM TOKEN (Ưu tiên Header, sau đó đến Cookie) ---
    
    // Kiểm tra 1: Lấy từ Header (Chuẩn Bearer Token - Dùng cho Mobile/SPA)
    if (
        req.headers.authorization &&
        req.headers.authorization.startsWith('Bearer')
    ) {
        try {
            // Header có dạng: "Bearer eyJhbGci..." -> Cắt lấy phần token phía sau
            token = req.headers.authorization.split(' ')[1];
        } catch (error) {
            console.error("Lỗi lấy token từ Header:", error);
        }
    }
    
    // Kiểm tra 2: Nếu Header không có, thử tìm trong Cookie (Dùng cho Web bảo mật)
    // (Yêu cầu phải cài thư viện 'cookie-parser' ở server.js mới đọc được req.cookies)
    else if (req.cookies && req.cookies.jwt_token) {
        token = req.cookies.jwt_token;
    }

    // --- BƯỚC 2: KIỂM TRA TỒN TẠI ---
    if (!token) {
        return res.status(401).json({
            success: false,
            message: 'Không có quyền truy cập! Vui lòng đăng nhập.'
        });
    }

    // --- BƯỚC 3: XÁC THỰC TOKEN (VERIFY) ---
    try {
        // Giải mã Token: Lấy ra payload (chứa id user)
        const decoded = jwt.verify(token, process.env.JWT_SECRET);

        // Tìm User trong Database dựa vào ID trong token
        // .select('-password'): Loại bỏ trường password ra khỏi kết quả trả về (để bảo mật)
        req.user = await User.findById(decoded.id).select('-password');

        // Nếu token hợp lệ nhưng User đã bị xóa khỏi Database thì cũng chặn luôn
        if (!req.user) {
            return res.status(401).json({
                success: false,
                message: 'Token không hợp lệ hoặc tài khoản không còn tồn tại.'
            });
        }

        // --- BƯỚC 4: CHO QUA ---
        // Gán thông tin user vào biến req để Controller phía sau có thể dùng
        next(); 

    } catch (error) {
        console.error(error);
        return res.status(401).json({
            success: false,
            message: 'Phiên đăng nhập hết hạn hoặc Token không hợp lệ.'
        });
    }
};

module.exports = { protect };