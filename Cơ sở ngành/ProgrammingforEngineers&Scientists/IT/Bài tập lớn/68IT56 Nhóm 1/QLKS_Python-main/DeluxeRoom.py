class DeluxeRoom:
    def __init__(self, rid, price, status, area, beds, services):
        self.rid = rid
        self.price = price
        self.status = status
        self.area = area
        self.beds = beds
        self.services = services if services else []
        self.room_type = "DeluxeRoom"  # Đặt mặc định loại phòng là DeluxeRoom

    def display(self):
        print(f"Phòng {self.rid} - {self.room_type}")
        print(f"Giá: {self.price} VND")
        print(f"Tình trạng: {self.status}")
        print(f"Diện tích: {self.area} m2")
        print(f"Số giường: {self.beds}")
        print(f"Dịch vụ: {', '.join(self.services) if self.services else 'Không có dịch vụ'}")

    def display_info(self):
        print(f"Phòng {self.rid} (Loại: {self.room_type}) - Tình trạng: {self.status} - Giá: {self.price} VND - Dịch vụ: {', '.join(self.services) if self.services else 'Không có dịch vụ'}")

    def set_status(self, status):
        if status in ["available", "booked"]:
            self.status = status
        else:
            print("Tình trạng không hợp lệ.")

    def add_service(self, service):
        if service not in self.services:
            self.services.append(service)
            print(f"Đã thêm dịch vụ: {service}")
        else:
            print(f"Dịch vụ {service} đã tồn tại.")
