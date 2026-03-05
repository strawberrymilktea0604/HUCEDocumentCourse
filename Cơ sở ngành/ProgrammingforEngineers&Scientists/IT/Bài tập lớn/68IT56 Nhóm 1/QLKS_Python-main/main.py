# main.py
from ManageRoom import ManageRoom
import os

def main():
    manager = ManageRoom()
    filename = "rooms.txt"
    if not os.path.exists(filename):
        with open(filename, 'w', encoding='utf-8') as f:
            pass

    print("Bạn có muốn đọc dữ liệu phòng từ file? (y/n): ")
    load = input().strip().lower()
    if load == 'y':
        manager.loadFromFile(filename)

    while True:
        print("\n========== QUẢN LÝ PHÒNG KHÁCH SẠN ==========")
        print("1. Thêm mới phòng")
        print("2. Sửa thông tin phòng")
        print("3. Xóa phòng")
        print("4. Tìm kiếm phòng theo mã hoặc loại")
        print("5. Hiển thị danh sách phòng theo phân loại và doanh thu")
        print("6. Thống kê phòng trống")
        print("7. Lưu dữ liệu vào file")
        print("0. Thoát chương trình")

        choice = input("Nhập lựa chọn của bạn: ").strip()

        if choice == "1":
            print("\n--- Thêm mới phòng ---")
            room_type = input("Chọn loại phòng (Standard / Deluxe): ").strip().lower()
            rid = input("Mã phòng: ").strip()

            try:
                price = int(input("Giá mỗi đêm: "))
                area = float(input("Diện tích (m2): "))
                beds = int(input("Số giường: "))
            except ValueError:
                print("Giá, diện tích, hoặc số giường không hợp lệ.")
                continue

            while True:
                status = input("Tình trạng (available/booked): ").strip().lower()
                if status in ['available', 'booked']:
                    break
                print("Tình trạng không hợp lệ. Vui lòng nhập lại (available hoặc booked).")

            if room_type == "standard":
                manager.addStandardRoom(rid, price, status, area, beds)
            elif room_type == "deluxe":
                services = input("Nhập danh sách dịch vụ (cách nhau bởi dấu phẩy): ").split(",")
                services = [s.strip() for s in services if s.strip()]
                manager.addDeluxeRoom(rid, price, status, area, beds, services)
            else:
                print("Loại phòng không hợp lệ!")

        elif choice == "2":
            print("\n--- Sửa thông tin phòng ---")
            manager.editRoom()

        elif choice == "3":
            print("\n--- Xóa phòng ---")
            rid = input("Nhập mã phòng cần xóa: ").strip()
            manager.deleteRoom(rid)

        elif choice == "4":
            print("\n--- Tìm kiếm phòng ---")
            rid = input("Nhập mã phòng (bỏ trống nếu không tìm theo mã): ").strip()
            rtype = input("Nhập loại phòng (StandardRoom / DeluxeRoom, bỏ trống nếu không tìm theo loại): ").strip()
            status = input("Nhập tình trạng phòng (available / booked, bỏ trống nếu không tìm theo tình trạng): ").strip()
            manager.searchRoom(rid=rid or None, room_type=rtype or None, status=status or None)

        elif choice == "5":
            print("\n--- Hiển thị danh sách phòng và doanh thu ---")
            rtype = input("Hiển thị loại phòng nào? (StandardRoom / DeluxeRoom / để trống để xem tất cả): ").strip()
            manager.displayRoomList(rtype if rtype else None)

        elif choice == "6":
            print("\n--- Thống kê phòng trống ---")
            rtype = input("Nhập loại phòng (StandardRoom / DeluxeRoom / để trống để xem tất cả): ").strip()
            manager.listAvailableRooms(rtype if rtype else None)

        elif choice == '7':
            manager.saveToFile(filename)

        elif choice == "0":
            print("Đã thoát chương trình.")
            break

        else:
            print("Lựa chọn không hợp lệ, vui lòng thử lại.")

if __name__ == "__main__":
    main()
