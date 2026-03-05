import csv
from StandardRoom import StandardRoom
from DeluxeRoom import DeluxeRoom

class ManageRoom:
    def __init__(self):
        self.rooms = []

    def isRoomExists(self, rid):
        return any(room.rid == rid for room in self.rooms)

    def addStandardRoom(self, rid, price, status, area, beds):
        if not rid or not price or not area or not beds:
            print("Mã phòng, giá, diện tích và số giường là bắt buộc.")
            return
        if self.isRoomExists(rid):
            print(f"Phòng với mã {rid} đã tồn tại.")
            return
        room = StandardRoom(rid, price, status, area, beds)
        self.rooms.append(room)
        print(f"Đã thêm phòng thường mã {rid}.")

    def addDeluxeRoom(self, rid, price, status, area, beds, services):
        if not rid or not price or not area or not beds:
            print("Mã phòng, giá, diện tích và số giường là bắt buộc.")
            return
        if self.isRoomExists(rid):
            print(f"Phòng với mã {rid} đã tồn tại.")
            return
        room = DeluxeRoom(rid, price, status, area, beds, services)
        self.rooms.append(room)
        print(f"Đã thêm phòng cao cấp mã {rid}.")

    def editRoom(self):
        rid = input("Nhập mã phòng cần sửa: ").strip()
        room_to_edit = None
        for room in self.rooms:
            if room.rid == rid:
                room_to_edit = room
                break

        if room_to_edit is None:
            print(f"Không tìm thấy phòng với mã {rid}.")
            return

        print("\nThông tin hiện tại của phòng:")
        room_to_edit.display()

        try:
            price_input = input("Giá mới (bỏ trống nếu không đổi): ")
            price = int(price_input) if price_input else None

            status_input = input("Tình trạng mới (bỏ trống nếu không đổi): ")
            status = status_input if status_input else None

            area_input = input("Diện tích mới (bỏ trống nếu không đổi): ")
            area = float(area_input) if area_input else None

            beds_input = input("Số giường mới (bỏ trống nếu không đổi): ")
            beds = int(beds_input) if beds_input else None
        except ValueError:
            print("Giá, diện tích hoặc số giường không hợp lệ.")
            return

        if isinstance(room_to_edit, DeluxeRoom):
            services_input = input("Dịch vụ mới (cách nhau bởi dấu phẩy, bỏ trống nếu không đổi): ")
            services = [s.strip() for s in services_input.split(",")] if services_input else None
        else:
            services = None

        if price is not None:
            room_to_edit.price = price
        if status is not None:
            room_to_edit.status = status
        if area is not None:
            room_to_edit.area = area
        if beds is not None:
            room_to_edit.beds = beds
        if services is not None:
            room_to_edit.services = services

        print(f"Đã cập nhật thông tin cho phòng {rid}.")

    def deleteRoom(self, rid):
        room_to_delete = None
        for room in self.rooms:
            if room.rid == rid:
                room_to_delete = room
                break
        if room_to_delete:
            self.rooms.remove(room_to_delete)
            print(f"Phòng với mã {rid} đã được xóa.")
        else:
            print(f"Không tìm thấy phòng với mã {rid}.")

    def searchRoom(self, rid=None, room_type=None, status=None):
        found_rooms = []
        for room in self.rooms:
            if rid and room.rid != rid:
                continue
            if room_type and room.type != room_type:
                continue
            if status and room.status != status:
                continue
            found_rooms.append(room)

        if found_rooms:
            print(f"Tìm thấy {len(found_rooms)} phòng:")
            for room in found_rooms:
                room.display()
        else:
            print("Không tìm thấy phòng nào khớp với yêu cầu.")

    def displayRoomList(self, room_type=None):
        total_revenue = 0
        standard_revenue = 0
        deluxe_revenue = 0
        if room_type is None:
            print("Danh sách tất cả các phòng:")
            for room in self.rooms:
                room.display()
                if room.status == "booked":
                    total_revenue += room.price
                    if isinstance(room, StandardRoom):
                        standard_revenue += room.price
                    elif isinstance(room, DeluxeRoom):
                        deluxe_revenue += room.price
        else:
            print(f"Danh sách phòng loại {room_type}:")
            for room in self.rooms:
                if room_type == "StandardRoom" and isinstance(room, StandardRoom):
                    room.display_info()
                    if room.status == "booked":
                        standard_revenue += room.price
                elif room_type == "DeluxeRoom" and isinstance(room, DeluxeRoom):
                    room.display_info()
                    if room.status == "booked":
                        deluxe_revenue += room.price
        print("\nTổng doanh thu của khách sạn:", total_revenue, "VND")
        print(f"Tổng doanh thu phòng thường: {standard_revenue} VND")
        print(f"Tổng doanh thu phòng cao cấp: {deluxe_revenue} VND")

    def listAvailableRooms(self, room_type=None):
        available_rooms = []
        for room in self.rooms:
            if room.status == "available":
                if room_type is None:
                    available_rooms.append(room)
                elif room_type == "StandardRoom" and isinstance(room, StandardRoom):
                    available_rooms.append(room)
                elif room_type == "DeluxeRoom" and isinstance(room, DeluxeRoom):
                    available_rooms.append(room)

        if available_rooms:
            print(f"Danh sách phòng trống:")
            for room in available_rooms:
                room.display_info()
        else:
            print("Không có phòng trống.")

    def saveToFile(self, filename):
        try:
            with open(filename, 'w', encoding='utf-8') as f:
                for room in self.rooms:
                    if isinstance(room, StandardRoom):
                        f.write(f"Standard,{room.rid},{room.price},{room.status},{room.area},{room.beds}\n")
                    elif isinstance(room, DeluxeRoom):
                        services_str = ';'.join(room.services) if room.services else ''
                        f.write(f"Deluxe,{room.rid},{room.price},{room.status},{room.area},{room.beds},{services_str}\n")
            print(f"Đã lưu danh sách phòng vào file '{filename}'.")
        except Exception as e:
            print(f"Đã xảy ra lỗi khi lưu file: {e}")

    def loadFromFile(self, filename):
        try:
            with open(filename, 'r', encoding='utf-8') as f:
                reader = csv.reader(f)
                for parts in reader:
                    if not parts:
                        continue
                    room_type = parts[0]
                    if room_type == 'Standard' and len(parts) == 6:
                        _, rid, price, status, area, beds = parts
                        room = StandardRoom(rid, int(price), status, float(area), int(beds))
                        self.rooms.append(room)
                    elif room_type == 'Deluxe' and len(parts) == 7:
                        _, rid, price, status, area, beds, services_str = parts
                        services = services_str.split(';') if services_str else []
                        room = DeluxeRoom(rid, int(price), status, float(area), int(beds), services)
                        self.rooms.append(room)
            print(f"Đã đọc dữ liệu phòng từ file '{filename}'.")
        except FileNotFoundError:
            print(f"Không tìm thấy file '{filename}'.")