class Room:
    def __init__(self, rid, type, price, status):
        self.rid = rid
        self.type = type
        self.price = price
        self.status = status

    def display(self):
        print(f"Mã phòng: {self.rid}")
        print(f"Loại phòng: {self.type}")
        print(f"Giá mỗi đêm: {self.price} VND")
        print(f"Tình trạng: {self.status}")
