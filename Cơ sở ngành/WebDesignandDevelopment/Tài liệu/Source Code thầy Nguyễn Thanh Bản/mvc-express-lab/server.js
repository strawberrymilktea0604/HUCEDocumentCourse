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