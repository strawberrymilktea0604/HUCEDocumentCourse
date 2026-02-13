const express = require('express');
const router = express.Router(); // Khởi tạo Router

// Import Controller để dùng
const courseController = require('../controllers/courseController');

// Định nghĩa các đường dẫn
// Gọn gàng hơn nhiều so với viết trong server.js

router.get('/', courseController.getAllCourses);
router.post('/', courseController.createCourse);

router.get('/:id', courseController.getCourseById);
router.put('/:id', courseController.updateCourse);
router.delete('/:id', courseController.deleteCourse);

// Xuất router ra để server.js dùng
module.exports = router;