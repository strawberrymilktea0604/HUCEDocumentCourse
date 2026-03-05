class StandardRoom:
    def __init__(self, rid, price, status, area, beds):
        self.rid = rid
        self.price = price
        self.status = status
        self.area = area
        self.beds = beds
        self.room_type = "StandardRoom"  # Đặt mặc định loại phòng là StandardRoom

    def display(self):
        print(f"Phòng {self.rid} - {self.room_type}")
        print(f"Giá: {self.price} VND")
        print(f"Tình trạng: {self.status}")
        print(f"Diện tích: {self.area} m2")
        print(f"Số giường: {self.beds}")

    def display_info(self):
        print(f"Phòng {self.rid} (Loại: {self.room_type}) - Tình trạng: {self.status} - Giá: {self.price} VND")

    def set_status(self, status):
        if status in ["available", "booked"]:
            self.status = status
        else:
            print("Tình trạng không hợp lệ.")
