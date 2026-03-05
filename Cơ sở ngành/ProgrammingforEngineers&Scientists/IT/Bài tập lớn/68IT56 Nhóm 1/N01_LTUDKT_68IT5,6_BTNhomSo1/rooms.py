class Room:
    def __init__(self, rid, type, price, status):
        self.rid = rid
        self.type = type
        self.price = price
        self.status = status


class StandardRoom(Room):
    def __init__(self, rid, price, status, area, bed_count):
        super().__init__(rid, "Phòng thường", price, status)
        self.area = area
        self.bed_count = bed_count


class DeluxeRoom(Room):
    def __init__(self, rid, price, status, area, bed_count, services):
        super().__init__(rid, "Phòng cao cấp", price, status)
        self.area = area
        self.bed_count = bed_count
        self.services = services
