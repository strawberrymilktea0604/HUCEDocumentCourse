const User = require('../models/User');
const jwt = require('jsonwebtoken');

// Hàm tạo Token (Vé vào cửa)
const generateToken = (id) => {
    return jwt.sign({ id }, process.env.JWT_SECRET, {
        expiresIn: '1d', // Token sống trong 1 ngày
    });
};

// --- 1. XỬ LÝ ĐĂNG KÝ ---
exports.registerUser = async (req, res) => {
    const { username, email, password } = req.body;

    try {
        // Kiểm tra xem email đã có người dùng chưa
        const userExists = await User.findOne({ email });
        if (userExists) {
            return res.status(400).json({ message: 'Email này đã được đăng ký!' });
        }

        // Tạo User mới (Password sẽ tự động được mã hóa nhờ Model)
        const user = await User.create({
            username,
            email,
            password
        });

        if (user) {
            res.status(201).json({
                _id: user._id,
                username: user.username,
                email: user.email,
                token: generateToken(user._id), // Trả token ngay để user login luôn
                message: "Đăng ký thành công!"
            });
        }
    } catch (error) {
        res.status(500).json({ message: "Lỗi Server: " + error.message });
    }
};

// --- 2. XỬ LÝ ĐĂNG NHẬP ---
exports.loginUser = async (req, res) => {
    const { email, password } = req.body;

    try {
        // Tìm user trong DB Atlas
        const user = await User.findOne({ email });

        // Kiểm tra: Có user đó không? VÀ Mật khẩu có khớp không?
        if (user && (await user.matchPassword(password))) {
            res.json({
                _id: user._id,
                username: user.username,
                email: user.email,
                token: generateToken(user._id), // CẤP VÉ (TOKEN)
                message: "Đăng nhập thành công!"
            });
        } else {
            res.status(401).json({ message: 'Sai thông tin đăng nhập!' });
        }
    } catch (error) {
        res.status(500).json({ message: "Lỗi Server: " + error.message });
    }
};