const mongoose = require('mongoose');

const connectDB = async () => {
    try {
        // Kết nối đến Cloud thông qua chuỗi URI trong file .env
        const conn = await mongoose.connect(process.env.MONGO_URI);
        
        console.log('MongoDB Atlas Connected: ${conn.connection.host}');
    } catch (error) {
        console.error('Lỗi kết nối: ${error.message}');
        // Nếu lỗi này xảy ra, kiểm tra lại Network Access (IP) trên Atlas
        process.exit(1); 
    }
};

module.exports = connectDB;