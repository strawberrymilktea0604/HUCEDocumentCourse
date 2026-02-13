const express = require('express');
const dotenv = require('dotenv');
const connectDB = require('./src/config/db');


// Cấu hình môi trường và kết nối DB
dotenv.config();
connectDB();
//
const app = express();
const port = 3000;

// Import Routes
const courseRoutes = require('./src/routes/courseRoutes');
const authRoutes = require('./src/routes/authRoutes');
//
var cors = require('cors');// Thêm thư viện cors
//cors là gì? CORS (Cross-Origin Resource Sharing) là một cơ chế bảo mật của trình duyệt web cho phép hoặc chặn các yêu cầu từ một nguồn (domain) khác với nguồn của trang web hiện tại. Mặc định, trình duyệt sẽ chặn các yêu cầu này để ngăn chặn các cuộc tấn công như Cross-Site Scripting (XSS) và Cross-Site Request Forgery (CSRF).
// Sử dụng middleware cors
app.use(cors());
// Middleware đọc JSON
app.use(express.json());

// --- ROUTES ---
// Mount (gắn) route vào đường dẫn gốc /api/courses
app.use('/api/courses', courseRoutes);
app.use('/api/auth', authRoutes);
//
// Route mặc định trang chủ
app.get('/', (req, res) => {
    res.send('Chào mừng đến với API quản lý khóa học (MVC)');
});

// Chạy server
app.listen(port, () => {
    console.log(`Server chạy tại: http://localhost:${port}`);
});