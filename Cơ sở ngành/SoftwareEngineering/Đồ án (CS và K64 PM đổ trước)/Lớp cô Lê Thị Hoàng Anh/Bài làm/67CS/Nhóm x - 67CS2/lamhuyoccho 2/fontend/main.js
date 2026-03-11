// Ví dụ: Hiển thị thông báo khi nhấn nút "Thêm"
document.querySelectorAll('.btn-danger').forEach(button => {
  button.addEventListener('click', () => {
    alert('Bạn đã thêm sản phẩm vào giỏ hàng!');
  });
});
// Load header từ header.html
document.addEventListener("DOMContentLoaded", function () {
  fetch("components/header.html")
    .then(response => response.text())
    .then(data => {
      document.getElementById("header-placeholder").innerHTML = data;
    });
});


// Gắn sự kiện scroll để theo dõi vị trí trang
window.addEventListener("scroll", () => {
  const sections = document.querySelectorAll("section"); // Các phần tương ứng (Ưu đãi, Món mới,...)
  const navLinks = document.querySelectorAll(".navbar-nav .nav-link");

  let current = "";

  sections.forEach((section) => {
    const sectionTop = section.offsetTop;
    if (window.scrollY >= sectionTop - 60) {
      current = section.getAttribute("id"); // Lấy ID của phần hiện tại
    }
  });

  // Gỡ bỏ lớp active khỏi tất cả các nav-link
  navLinks.forEach((link) => {
    link.classList.remove("active");
    if (link.getAttribute("href") === `#${current}`) {
      link.classList.add("active");
    }
  });
});

function toggleMenu() {
  const sidebarMenu = document.getElementById("sidebarMenu");
  const overlay = document.getElementById("overlay");

  // Toggle trạng thái của sidebar và overlay
  sidebarMenu.classList.toggle("active");
  overlay.classList.toggle("active");
}

let currentSlide = 0; // Slide hiện tại
const banners = document.querySelectorAll(".banner"); // Lấy danh sách các ảnh
const totalSlides = banners.length; // Tổng số ảnh

function changeSlide(direction) {
  // Ẩn ảnh hiện tại
  banners[currentSlide].style.display = "none";

  // Cập nhật chỉ số ảnh
  currentSlide = (currentSlide + direction + totalSlides) % totalSlides;

  // Hiển thị ảnh mới
  banners[currentSlide].style.display = "block";
}

// Hiển thị ảnh đầu tiên khi trang tải
document.addEventListener("DOMContentLoaded", () => {
  banners.forEach((banner, index) => {
    banner.style.display = index === 0 ? "block" : "none";
  });
});


// Hàm render menu
function renderMenu(sectionId, items) {
  const section = document.querySelector(`#${sectionId} .row`);

  if (!section) {
    console.error("Không tìm thấy container với id 'danhMucContainer'");
    return;
  }
  items.forEach(item => {
    const card = `
        <div class="col">
          <div class="card">
            <img src="${item.image}" alt="${item.name}">
            <div class="card-body text-center">
              <h5 class="card-title">${item.name}</h5>
              <p class="text-danger fw-bold">${item.price.toLocaleString()} 
                <span class="text-muted"><s>${item.originalPrice.toLocaleString()}</s></span>
              </p>
              <button class="btn btn-danger">Thêm</button>
            </div>
          </div>
        </div>`;
    section.innerHTML += card;
  });
}

// Gọi hàm render cho từng phần


fetch('http://localhost:3000/api/sanpham')
  .then(response => response.json())
  .then(data => {

    danhsachsanpham = data;
    renderMenu("uudai", danhsachsanpham);
    renderMenu("monmoi", danhsachsanpham);
    renderMenu("banchay", danhsachsanpham);
    renderMenu("douong", danhsachsanpham);
    renderMenu("coffee", danhsachsanpham);
    renderMenu("doanmua", danhsachsanpham);




    renderMenu("danhmucmonan", danhsachsanpham);
    renderMenu("cothebansethich", danhsachsanpham);



  })
  .catch(error => console.error('Lỗi khi lấy dữ liệu:', error));
// Danh sách đồ uống

// Thêm dòng vào bảng

function renderMenu(sectionId, products) {
  const section = document.querySelector(`#${sectionId} .row`);


  products.forEach(product => {


    const card = `
        <div class="col">
          <div class="card">
            <img src="${product.Anh_san_pham}" alt="${product.Ten_san_pham}">
            <div class="card-body text-center">
              <h5 class="card-title">${product.Ten_san_pham}</h5>
              <p class="text-danger fw-bold">${parseFloat(product.Gia_nhap).toLocaleString()} 
                <span class="text-muted"><s>${parseFloat(product.Gia_nhap).toLocaleString()}</s></span>
              </p>
              <button class="btn btn-danger">Thêm</button>
            </div>
          </div>
        </div>`;
    section.innerHTML += card;
  });
}



// Khởi tạo bảng








