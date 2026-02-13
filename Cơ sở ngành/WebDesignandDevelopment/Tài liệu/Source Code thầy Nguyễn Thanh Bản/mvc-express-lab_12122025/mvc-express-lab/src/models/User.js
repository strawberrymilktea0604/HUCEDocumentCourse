const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');

const UserSchema = new mongoose.Schema({
    username: { type: String, required: true },
    email: { type: String, required: true, unique: true },
    password: { type: String, required: true }
}, {
    timestamps: true // Tự động tạo createdAt và updatedAt
});

// --- MIDDLEWARE: Mã hóa mật khẩu trước khi Lưu ---
UserSchema.pre('save', async function (next) {
    // Nếu password không bị sửa đổi thì bỏ qua bước này (để tránh băm đi băm lại)
    if (!this.isModified('password')) {
        return next();
    }
    
    // Tạo muối (salt) và băm (hash)
    const salt = await bcrypt.genSalt(10);
    this.password = await bcrypt.hash(this.password, salt);
    next();
});

// --- METHOD: Kiểm tra mật khẩu khi đăng nhập ---
UserSchema.methods.matchPassword = async function (enteredPassword) {
    // So sánh mật khẩu người dùng nhập vào với mật khẩu đã mã hóa trong DB
    return await bcrypt.compare(enteredPassword, this.password);
};

module.exports = mongoose.model('User', UserSchema);