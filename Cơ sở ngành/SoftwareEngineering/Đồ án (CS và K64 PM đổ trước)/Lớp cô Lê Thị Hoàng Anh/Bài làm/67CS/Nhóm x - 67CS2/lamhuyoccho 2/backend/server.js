const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const app = express();
const port = 3000;

// Middleware
app.use(cors());

// Kết nối MySQL
const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'Grocery_drink'
});

db.connect(err => {
  if (err) throw err;
  console.log('MySQL Connected...');
});
// Middleware
app.use(express.json()); // Để xử lý body dữ liệu JSON từ frontend
app.use(express.urlencoded({ extended: true })); // Để xử lý dữ liệu urlencoded nếu cần


// API lấy sản phẩm
app.get('/api/sanpham', (req, res) => {
  const sql = 'SELECT ID_San_pham, Ten_san_pham, Gia_nhap, So_Luong, Anh_san_pham FROM San_pham';
  db.query(sql, (err, results) => {
    if (err) {
      console.error('Lỗi truy vấn MySQL:', err);
      return res.status(500).send('Lỗi truy vấn CSDL');
    }

    // Chuyển dữ liệu nhị phân của ảnh sang Base64
    const modifiedResults = results.map(row => {
      if (row.Anh_san_pham) {
        row.Anh_san_pham = `data:image/jpeg;base64,${row.Anh_san_pham.toString('base64')}`;
      }
      return row;
    });

    res.json(modifiedResults);
  });
});

// API thêm sản phẩm
app.post('/api/them-san-pham', (req, res) => {
  const { Ten_san_pham, Gia_nhap, So_Luong, ID_Loai, Anh_san_pham } = req.body;

  const sql = 'INSERT INTO San_pham (Ten_san_pham, Gia_nhap, So_Luong, ID_Loai, Anh_san_pham) VALUES (?, ?, ?, ?, ?)';

  db.query(sql, [Ten_san_pham, Gia_nhap, So_Luong, ID_Loai, Buffer.from(Anh_san_pham.split(',')[1], 'base64')], (err, result) => {
    if (err) {
      console.error('Lỗi khi thêm sản phẩm:', err);
      return res.status(500).send('Lỗi khi thêm sản phẩm');
    }
    res.json({ message: 'Sản phẩm đã được thêm thành công!' });
  });
});
// API để lấy danh sách khách hàng
app.get('/api/customers', (req, res) => {
  const query = 'SELECT * FROM Khach_hang';
  db.query(query, (err, results) => {
    if (err) {
      console.error('Error fetching data:', err);
      res.status(500).json({ error: 'Failed to fetch data' });
      return;
    }
    res.json(results);
  });
});
// API cập nhật thông tin khách hàng
app.put("/api/customers/:id", (req, res) => {
  const { id } = req.params;
  const { Ten_khach_hang, Tuoi, Dia_chi, SDT } = req.body;

  const query = `
    UPDATE Khach_hang 
    SET Ten_khach_hang = ?, Tuoi = ?, Dia_chi = ?, SDT = ? 
    WHERE ID_Khach_hang = ?`;

  db.query(query, [Ten_khach_hang, Tuoi, Dia_chi, SDT, id], (err, result) => {
    if (err) return res.status(500).send(err);
    res.json({ message: "Thông tin khách hàng đã được cập nhật thành công!" });
  });
});
app.post("/api/add-customer", (req, res) => {
  const { Ten_khach_hang, Tuoi, Dia_chi, SDT } = req.body;

  if (!Ten_khach_hang || !Tuoi || !Dia_chi || !SDT) {
    return res.status(400).json({
      success: false,
      message: "Vui lòng cung cấp đầy đủ thông tin khách hàng!",
    });
  }

  const sql = "INSERT INTO Khach_hang (Ten_khach_hang, Tuoi, Dia_chi, SDT) VALUES (?, ?, ?, ?)";
  const values = [Ten_khach_hang, Tuoi, Dia_chi, SDT];

  db.query(sql, values, (err, result) => {
    if (err) {
      console.error("Lỗi khi thêm khách hàng:", err);
      return res.status(500).json({
        success: false,
        message: "Lỗi khi thêm khách hàng. Vui lòng thử lại!",
      });
    }

    res.status(201).json({
      success: true,
      message: "Thêm khách hàng thành công!",
      customerId: result.insertId, // ID tự động tạo của khách hàng
    });
  });
});
// API để xóa khách hàng theo ID
app.delete('/api/customers/:id', (req, res) => {
  const customerId = req.params.id; // Lấy ID từ URL

  // SQL query để xóa khách hàng
  const query = 'DELETE FROM Khach_hang WHERE ID_Khach_hang = ?';

  db.query(query, [customerId], (err, result) => {
    if (err) {
      console.error('Lỗi khi xóa khách hàng:', err);
      return res.status(500).json({ message: 'Lỗi khi xóa khách hàng' });
    }

    // Kiểm tra xem có khách hàng nào bị xóa không
    if (result.affectedRows === 0) {
      return res.status(404).json({ message: 'Không tìm thấy khách hàng để xóa' });
    }

    res.status(200).json({ message: 'Khách hàng đã được xóa thành công' });
  });
});
// API để lấy tất cả hóa đơn
app.get('/api/invoices', (req, res) => {
  const query = `SELECT * FROM Hoa_don`;
  db.query(query, (err, results) => {
      if (err) {
          res.status(500).send('Lỗi khi lấy dữ liệu hóa đơn');
          return;
      }
      res.json(results);
  });
});
// API để sửa dữ liệu hóa đơn
app.put('/api/invoices/:id', (req, res) => {
  const invoiceId = req.params.id;
  const { thoiGianLap, tongTien, idNV, idKhachHang } = req.body;

  // Log để kiểm tra dữ liệu nhận được từ client
  console.log('Data received:', req.body);

  // Kiểm tra xem tất cả thông tin có tồn tại trong body request
  // if (!thoiGianLap || !tongTien || !idNV || !idKhachHang) {
  //     return res.status(400).json({ message: 'Thiếu thông tin cần thiết để cập nhật hóa đơn.' });
  // }

  // Câu lệnh SQL để cập nhật hóa đơn
  const query = `UPDATE Hoa_don SET Thoi_gian_lap = ?, Tong_tien = ?, ID_NV = ?, ID_Khach_hang = ? WHERE ID_Hoa_don = ?`;

  // Thực hiện câu lệnh cập nhật
  connection.query(query, [thoiGianLap, tongTien, idNV, idKhachHang, invoiceId], (err, results) => {
      if (err) {
          console.error('Lỗi khi cập nhật hóa đơn:', err);
          return res.status(500).json({ message: 'Lỗi khi cập nhật hóa đơn.' });
      }

      if (results.affectedRows === 0) {
          return res.status(404).json({ message: 'Không tìm thấy hóa đơn với ID này.' });
      }

      res.json({ message: 'Cập nhật hóa đơn thành công!' });
  });
});

// API lấy danh sách nhân viên

app.get('/api/nhan-vien', (req, res) => {
  const query = 'SELECT * FROM Nhan_vien';
  db.query(query, (err, results) => {
      if (err) {
          console.error('Lỗi truy vấn:', err);
          res.status(500).send('Lỗi máy chủ');
          return;
      }
      res.json(results);
  });
});
// API cập nhật thông tin nhân viên theo ID
app.put('/api/nhan-vien/:id', (req, res) => {
  const id = req.params.id;
  const { Ho_Ten, Dia_Chi, Gioi_Tinh, Tuoi, So_Dien_Thoai } = req.body;

  // Kiểm tra dữ liệu đầu vào
  if (!Ho_Ten || !Gioi_Tinh || !So_Dien_Thoai) {
      return res.status(400).json({ message: 'Họ tên, giới tính và số điện thoại là bắt buộc' });
  }

  const sql = `UPDATE Nhan_vien 
               SET Ho_Ten = ?, Dia_Chi = ?, Gioi_Tinh = ?, Tuoi = ?, So_Dien_Thoai = ? 
               WHERE ID_NV = ?`;

  const values = [Ho_Ten, Dia_Chi, Gioi_Tinh, Tuoi, So_Dien_Thoai, id];

  db.query(sql, values, (err, result) => {
      if (err) {
          console.error('Lỗi khi cập nhật dữ liệu:', err);
          res.status(500).json({ message: 'Có lỗi xảy ra khi cập nhật dữ liệu' });
      } else if (result.affectedRows === 0) {
          res.status(404).json({ message: 'Không tìm thấy nhân viên với ID đã cho' });
      } else {
          res.json({ message: 'Cập nhật thông tin nhân viên thành công' });
      }
  });
});


// Khởi động server
app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
