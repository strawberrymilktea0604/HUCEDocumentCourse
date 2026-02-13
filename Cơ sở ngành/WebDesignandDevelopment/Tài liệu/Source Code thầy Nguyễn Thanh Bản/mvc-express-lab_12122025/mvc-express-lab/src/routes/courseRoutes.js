const express = require('express');
const router = express.Router(); // Khởi tạo Router

// Import Controller để dùng
const courseController = require('../controllers/courseController');
// Import khiên bảo vệ vào
const { protect } = require('../middleware/authMiddleware');
// Định nghĩa các đường dẫn
// Gọn gàng hơn nhiều so với viết trong server.js

router.get('/', courseController.getAllCourses);
router.post('/', protect,courseController.createCourse);

router.get('/:id', courseController.getCourseById);
router.put('/:id', protect, courseController.updateCourse);
router.delete('/:id',protect, courseController.deleteCourse);

// Xuất router ra để server.js dùng
module.exports = router;