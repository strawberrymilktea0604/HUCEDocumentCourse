// 1. KIỂM TRA ĐĂNG NHẬP NGAY KHI MỞ TRANG
// Nếu không có token trong túi, không cho đứng ở trang này
const token = localStorage.getItem('token');

if (!token) {
    alert("Vui lòng đăng nhập trước!");
    window.location.href = 'signin.html';
}

const form = document.getElementById('addCourseForm');
const btnSave = document.getElementById('btnSave');

// 2. XỬ LÝ SỰ KIỆN SUBMIT FORM
form.addEventListener('submit', async function(e) {
    e.preventDefault(); // Chặn load lại trang

    // Lấy dữ liệu từ ô input
    const name = document.getElementById('name').value.trim();
    const price = document.getElementById('price').value;
    const description = document.getElementById('description').value.trim();

    // UX: Chuyển nút sang trạng thái đang xử lý
    const originalBtnText = btnSave.innerText;
    btnSave.innerText = "Đang lưu...";
    btnSave.disabled = true;

    try {
        // Gửi Request lên API
        const response = await fetch('http://localhost:3000/api/courses', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                // --- QUAN TRỌNG: Gắn vé vào cửa (Token) ---
                'Authorization': `Bearer ${token}` 
            },
            body: JSON.stringify({
                name: name,
                price: price,
                description: description
            })
        });

        const data = await response.json();

        // Xử lý kết quả trả về
        if (response.ok) { // Status 200-299
            alert("Thêm khóa học thành công!");
            // xóa các trường nhập liệu
            document.getElementById('name').value = '';
            document.getElementById('price').value = '';
            document.getElementById('description').value = ''; 
        } else {
            // Xử lý các lỗi từ Server trả về
            if (response.status === 401) {
                alert("Phiên đăng nhập hết hạn. Vui lòng đăng nhập lại.");
                localStorage.removeItem('authToken'); // Xóa token rác
                window.location.href = 'login.html';
            } else {
                alert(`Lỗi: ${data.message}`);
            }
        }

    } catch (error) {
        console.error("Lỗi mạng:", error);
        alert("Không thể kết nối đến Server!");
    } finally {
        // Dù thành công hay thất bại cũng mở lại nút bấm
        btnSave.innerText = originalBtnText;
        btnSave.disabled = false;
    }
});