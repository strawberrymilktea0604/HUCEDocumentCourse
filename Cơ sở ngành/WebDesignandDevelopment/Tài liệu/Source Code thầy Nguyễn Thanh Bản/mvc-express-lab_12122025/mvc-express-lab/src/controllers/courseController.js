// 1. Import dữ liệu từ Model
const courses = require('../models/courseModel');

// 2. Viết các hàm xử lý logic

// [GET] /api/courses
exports.getAllCourses = (req, res) => {
    res.status(200).json({
        success: true,
        count: courses.length,
        data: courses
    });
};

// [GET] /api/courses/:id
exports.getCourseById = (req, res) => {
    const id = parseInt(req.params.id);
    const course = courses.find(c => c.id === id);

    if (!course) {
        return res.status(404).json({ success: false, message: 'Không tìm thấy khóa học' });
    }

    res.status(200).json({ success: true, data: course });
};

// [POST] /api/courses
exports.createCourse = (req, res) => {
    const { name, price, description } = req.body;

    // Validate đơn giản
    if (!name || !price) {
        return res.status(400).json({ success: false, message: 'Vui lòng nhập tên và giá' });
    }
// Ép kiểu sang số (dù nhận vào là string hay number đều thành number)
        // price = Number(price);
    // Tạo ID tự tăng
    const newId = courses.length > 0 ? courses[courses.length - 1].id + 1 : 1;

    const newCourse = {
        id: newId,
        name,
        price,
        description: description || 'Chưa có mô tả'
    };

    courses.push(newCourse);

    res.status(201).json({ success: true, data: newCourse });
};

// [PUT] /api/courses/:id
exports.updateCourse = (req, res) => {
    const id = parseInt(req.params.id);
    const course = courses.find(c => c.id === id);

    if (!course) {
        return res.status(404).json({ success: false, message: 'Không tìm thấy khóa học để sửa' });
    }

    // Cập nhật dữ liệu
    course.name = req.body.name || course.name;
    course.price = req.body.price || course.price;
    course.description = req.body.description || course.description;

    res.status(200).json({ success: true, message: 'Cập nhật thành công', data: course });
};

// [DELETE] /api/courses/:id
//Cộng 1 điểm quá trình cho sv Nghiêm Trường An 69CS1
exports.deleteCourse = (req, res) => {
    const id = parseInt(req.params.id);
    const index = courses.findIndex(c => c.id === id);

    if (index === -1) {
        return res.status(404).json({ success: false, message: 'Không tìm thấy khóa học để xóa' });
    }

    courses.splice(index, 1);
    res.status(200).json({ success: true, message: 'Đã xóa thành công' });
};