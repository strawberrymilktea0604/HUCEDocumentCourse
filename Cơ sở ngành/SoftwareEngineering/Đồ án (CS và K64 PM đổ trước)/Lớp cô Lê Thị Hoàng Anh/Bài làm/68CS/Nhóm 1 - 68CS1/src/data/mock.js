export const currentUser = {
  userId: "0203568",
  fullName: "Ngô Thị Quế Anh",
  role: "Quản lý",
  username: "queanhngo",
  phone: "0912345678",
  email: "queanhngo@nutmilk.com",
  status: "Hoạt động",
};

export const notifications = [
  {
    from: "Nhà cung cấp",
    title: "Điều chỉnh thời gian giao hàng (NCC Sữa tươi)",
    sub: "Từ ngày 1/12, thời gian giao hàng chuyển thành 17h.",
  },
  {
    from: "Quản lý",
    title: "Thay đổi hạn sử dụng với các loại hạt đã mở gói",
    sub: "Từ ngày 1/12, các loại hạt đã mở gói yêu cầu hút chân không.",
  },
  {
    from: "Nhân viên Kho",
    title: "Hết hàng Hạt Mắc ca",
    sub: "Do bão, nên quá trình nhập hàng bị ảnh hưởng, hạt mắc...",
  },
];

export const expiring = [
  { name: "Hạt điều Bình Phước lô #A234", qty: "50 kg", hsd: "13/12/2025", days: 3 },
  { name: "Hạt hạnh nhân Mỹ lô #B567", qty: "30 kg", hsd: "14/12/2025", days: 4 },
  { name: "Hạt óc chó Úc lô #C890", qty: "20 kg", hsd: "16/12/2025", days: 6 },
];

export const todayMoves = [
  { dir: "in", name: "Hạt điều nguyên liệu", qty: "Số lượng: 300 kg", time: "08:30" },
  { dir: "out", name: "Sữa tươi Vinamilk", qty: "Số lượng: 10 hộp", time: "09:15" },
  { dir: "in", name: "Hạt hạnh nhân Mỹ", qty: "Số lượng: 200 kg", time: "10:45" },
  { dir: "in", name: "Hạt Mắc ca", qty: "Số lượng: 300 kg", time: "12:30" },
];

export const newMaterials = [
  { code: "VI12", name: "Hộp nhựa vuông", unit: "Hộp" },
  { code: "D134", name: "Đường ăn kiêng", unit: "Hộp" },
  { code: "H235", name: "Mè đen", unit: "Kg" },
  { code: "H236", name: "Gừng tươi", unit: "Kg" },
];

export const materialNVL01 = {
  code: "NVL01",
  name: "Hạt điều",
  category: "Hạt",
  supplier: "Công ty hạt điều BP",
  unit: "Kg",
  minStock: "100 Kg",
  totalStock: "450 Kg",
  location: "Hàng 2 - Kệ A",
  storage: "Sau khi bóc bao bì, sử dụng trong 3 ngày",
  lots: [
    {
      lot: "LO202511",
      mfg: "12/11/2025",
      exp: "12/11/2026",
      initQty: "500 Kg",
      currentQty: "0 Kg",
      location: "Hàng 2 - Kệ A",
      status: "Hết hàng",
    },
    {
      lot: "LO202512",
      mfg: "01/12/2025",
      exp: "01/12/2026",
      initQty: "500 Kg",
      currentQty: "450 Kg",
      location: "Hàng 2 - Kệ A",
      status: "Còn hàng",
    },
  ],
};
export const mockUsers = [
  {
    userId: "0203568",
    fullName: "Ngô Thị Quế Anh",
    username: "queanhngo",
    role: "Quản lý",
    email: "queanhngo@nutmilk.com",
    phone: "0912345678",
    status: "Hoạt động",
  },
  {
    userId: "0211268",
    fullName: "Đinh Xuân Nam",
    username: "dinhnam211",
    role: "Nhân viên kho",
    email: "dinhnam@nutmilk.com",
    phone: "0812345678",
    status: "Hoạt động",
  },
  {
    userId: "0210768",
    fullName: "Nguyễn Tất Mạnh",
    username: "tatmanh",
    role: "Nhân viên kho",
    email: "manhnt@nutmilk.com",
    phone: "0972345678",
    status: "Hoạt động",
  },
  {
    userId: "4002168",
    fullName: "Lê Việt Anh",
    username: "vietanhle",
    role: "Bộ phận sản xuất",
    email: "anhvle@nutmilk.com",
    phone: "0962345678",
    status: "Hoạt động",
  },
  {
    userId: "0215468",
    fullName: "Phan Tân Việt",
    username: "ptviet",
    role: "Bộ phận sản xuất",
    email: "vietpt@nutmilk.com",
    phone: "0312345678",
    status: "Ngừng hoạt động",
  },
  {
    userId: "0215068",
    fullName: "Lê Đỗ Việt Tùng",
    username: "viettung",
    role: "Bộ phận sản xuất",
    email: "tungldv@nutmilk.com",
    phone: "0981234567",
    status: "Hoạt động",
  },
];
export const mockSuppliers = [
  {
    code: "NCC01",
    name: "Công ty Hạt điều BP",
    address: "Số 123 Thanh Nhàn, HBT, HN",
    phone: "0271 3856 789",
    email: "hatdieu.bp@gmail.com",
    taxId: "0123456789",
    totalValue: 100000000,
    status: "Đang hợp tác",
    note: "",
  },
  {
    code: "NCC02",
    name: "Công ty Nuts VN",
    address: "Số 12 Yên Hòa, CG, HN",
    phone: "0251 3856 789",
    email: "nuts.vn@gmail.com",
    taxId: "0234567890",
    totalValue: 30900000,
    status: "Đang hợp tác",
    note: "",
  },
  {
    code: "NCC03",
    name: "Công ty Nhựa EPS",
    address: "Số 3 Hàng Buồm, BĐ, HN",
    phone: "0272 3856 789",
    email: "nhua.eps@gmail.com",
    taxId: "0345678920",
    totalValue: 20000000,
    status: "Đang hợp tác",
    note: "",
  },
  {
    code: "NCC04",
    name: "Công ty Vinamilk",
    address: "Số 45 Nguyễn Trãi, TX, HN",
    phone: "0273 3856 789",
    email: "hatdieu.bp@gmail.com",
    taxId: "0134567892",
    totalValue: 98000000,
    status: "Đang hợp tác",
    note: "",
  },
  {
    code: "NCC05",
    name: "Công ty Đường BH",
    address: "Số 14 Trần Phú, HĐ, HN",
    phone: "0253 3856 789",
    email: "sugar.bh@gmail.com",
    taxId: "0456789221",
    totalValue: 18000000,
    status: "Đang hợp tác",
    note: "",
  },
  {
    code: "NCC06",
    name: "Công ty Hạt AN",
    address: "Số 78 Xuân Thủy, CG, HN",
    phone: "0237 3856 789",
    email: "nut.an@gmail.com",
    taxId: "0156789243",
    totalValue: 198000000,
    status: "Đang hợp tác",
    note: "",
  },
];

export const mockSupplierTx = {
  NCC01: [
    {
      date: "28/11/2025",
      type: "Nhập kho",
      doc: "PNK28112025",
      item: "Hạt điều",
      qty: "500 Kg",
      value: 25000000,
      status: "Hoàn thành",
    },
    {
      date: "10/10/2025",
      type: "Nhập kho",
      doc: "PNK10112025",
      item: "Hạt điều",
      qty: "1200 Kg",
      value: 75000000,
      status: "Hoàn thành",
    },
  ],
};
