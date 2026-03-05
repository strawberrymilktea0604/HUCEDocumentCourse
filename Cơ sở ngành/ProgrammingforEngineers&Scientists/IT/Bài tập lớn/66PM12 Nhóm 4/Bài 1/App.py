import datetime

# Constants for fees and fines
BICYCLE_DAY_FEE = 2000
BICYCLE_NIGHT_FEE = 4000
BICYCLE_OVERNIGHT_FEE = 15000
BICYCLE_LOST_TICKET_FINE = 30000
MOTORCYCLE_DAY_FEE = 3000
MOTORCYCLE_NIGHT_FEE = 6000
MOTORCYCLE_OVERNIGHT_FEE = 35000
MOTORCYCLE_LOST_TICKET_FINE = 60000

class Vehicle:
    def __init__(self, vehicle_type, check_in_time, license_plate, ticket_id):
        self.vehicle_type = vehicle_type
        self.check_in_time = check_in_time
        # Xe đạp thì không có biển số
        self.license_plate = license_plate
        self.ticket_id = ticket_id

    def calculate_fee(self, check_out_time, lost_ticket) -> int:
        raise NotImplementedError("Subclasses must implement this method")

    def __str__(self):
        return f"""Loại xe: {self.vehicle_type}, 
        Thời gian đậu: {self.check_in_time},
        Biển số xe: {self.license_plate},
        Mã vé: {self.ticket_id}"""

class Bicycle(Vehicle):
    def __init__(self, check_in_time, ticket_id):
        super().__init__('Xe đạp', check_in_time, None, ticket_id)

    def calculate_fee(self, check_out_time, lost_ticket) -> int:
        fee = 0
        hours_parked = (check_out_time - self.check_in_time).total_seconds() / 3600

        # Xe gửi trong ngày
        if hours_parked <= 12:  
            if 8 <= check_out_time.hour < 18:
                fee += BICYCLE_DAY_FEE
            elif 18 <= check_out_time.hour < 22:
                fee += BICYCLE_NIGHT_FEE
        else:  
        # Xe gửi qua ngày
            fee += BICYCLE_OVERNIGHT_FEE
        
        return fee

class Motorcycle(Vehicle):
    def __init__(self, check_in_time, license_plate, ticket_id):
        super().__init__('Xe máy', check_in_time, license_plate, ticket_id)

    def calculate_fee(self, check_out_time, lost_ticket):
        fee = 0
        hours_parked = (check_out_time - self.check_in_time).total_seconds() / 3600

        if hours_parked <= 12:  # Xe gửi trong ngày
            if 8 <= check_out_time.hour < 18:
                fee += MOTORCYCLE_DAY_FEE
            elif 18 <= check_out_time.hour < 22:
                fee += MOTORCYCLE_NIGHT_FEE
        else:  # Xe gửi qua ngày
            fee += MOTORCYCLE_OVERNIGHT_FEE

        return fee

# Parking lot management
class ParkingLot:
    def __init__(self):
        self.vehicles = []
        self.lost_ticket_vehicles = []  # Lost ticket vehicles list
        self.alert_list = []  # List of vehicles that need alert
        self.daily_vehicles = []  # List of vehicles for daily statistics
        self.doanh_thu = 0  # Doanh thu initialization

        # thêm dữ liệu ( ngày hôm nay là ngày 25)
        # xe đạp

        xedapsang = Bicycle(datetime.datetime(2024, 2, 26, 10, 0), "xedapsang")
        self.vehicles.append(xedapsang)

        xedaptoi = Bicycle(datetime.datetime(2024, 2, 26, 20, 0), "xedaptoi")
        self.vehicles.append(xedaptoi)

        xedaphomqua = Bicycle(datetime.datetime(2024, 2, 25, 21, 0), "xedaphomqua")
        self.vehicles.append(xedaphomqua)
        xedapcanhbao = Bicycle(datetime.datetime(2024, 2, 20, 11, 0), "xedapcanhbao")
        self.vehicles.append(xedapcanhbao)
        
        
        # xe máy
        xemay1 = Motorcycle(datetime.datetime(2024, 2, 26, 9, 0), "123", "xemaysang")
        self.vehicles.append(xemay1) # danh sach xe dang đậu
        self.daily_vehicles.append(xemay1) # danh sach thong ke


        xemay2 = Motorcycle(datetime.datetime(2024, 2, 26, 21, 0), "456", "xemaytoi")
        self.vehicles.append(xemay2)
        self.daily_vehicles.append(xemay2)

        xemay3 = Motorcycle(datetime.datetime(2024, 2, 25, 9, 0), "789", "xemayhomqua")
        self.vehicles.append(xemay3)
        self.daily_vehicles.append(xemay3)

        xemay4 = Motorcycle(datetime.datetime(2024, 2, 17, 9, 0), "1122", "xemaycanhbao")
        self.vehicles.append(xemay4)
    def add_lost_ticket_vehicle(self, vehicle):
        self.lost_ticket_vehicles.append(vehicle)

    def add_daily_vehicle(self, vehicle):
        self.daily_vehicles.append(vehicle)

    def add_alert_vehicles(self):
        current_time = datetime.datetime.now()
        for vehicle in self.vehicles:
            entry_time = vehicle.check_in_time
            if isinstance(vehicle, Bicycle) and (current_time - entry_time).days >= 3:
                print("\n=====================================\n")
                print(vehicle)  # In thông tin xe đạp cần cảnh báo
            elif isinstance(vehicle, Motorcycle) and (current_time - entry_time).days >= 5:
                print("\n=====================================\n")
                print(vehicle)  # In thông tin xe máy cần cảnh báo


    def add_vehicle(self, vehicle):
        if any(existing_vehicle.ticket_id == vehicle.ticket_id for existing_vehicle in self.vehicles):
            print("\n=====================================\n")
            print("Mã vé đã tồn tại trong hệ thống. Không thể thêm phương tiện mới.")
            return
        if any(existing_vehicle.license_plate == vehicle.license_plate for existing_vehicle in self.vehicles):
            print("\n=====================================\n")
            print("Biển số xe đã tồn tại trong hệ thống. Không thể thêm phương tiện mới.")
            return
        self.vehicles.append(vehicle)
        print("\n=====================================\n")
        print("Thêm phương tiện đậu vào thành công.")

   
        # Các phần còn lại của lớp không thay đổi

    def remove_vehicle(self, ticket_id, has_paid_fee=None, has_ticket=None, license_plate=None):
        current_time = datetime.datetime.now().time()

        # Kiểm tra nếu thời gian hiện tại nằm trong khoảng không cho phép lấy xe ra
        if (datetime.time(22, 5) <= current_time <= datetime.time(23, 59)) or (datetime.time(0, 0) <= current_time <= datetime.time(8, 0)):
            print("\n=====================================\n")
            print("Hiện tại không thể lấy xe ra.")
        else:
            vehicle_to_remove = None
            for vehicle in self.vehicles:
                if vehicle.ticket_id == ticket_id:
                    vehicle_to_remove = vehicle
                    break

            if vehicle_to_remove is None:
                print("\n=====================================\n")
                print("Không tìm thấy phương tiện với mã vé đã nhập.")
            else:
                if vehicle_to_remove.vehicle_type == 'Xe máy':
                    license_plate = input("Nhập biển số xe: ")
                    if license_plate != vehicle_to_remove.license_plate:
                        print("\n=====================================\n")
                        print("Biển số xe không khớp với dữ liệu trong hệ thống. Không thể lấy phương tiện ra.")
                        return

                has_ticket = input("Có vé xe (Y/N): ").upper() == 'Y'
                if has_ticket:
                    fee = vehicle_to_remove.calculate_fee(datetime.datetime.now(), False)
                    print("Chi phí:", fee)
                    has_paid_fee = input("Đã nộp tiền phí (Y/N): ").upper() == 'Y'
                    if has_paid_fee:
                        print("\n=====================================\n")
                        print("Phương tiện đã được lấy ra thành công.")
                        self.vehicles.remove(vehicle_to_remove)  # Loại bỏ phương tiện khỏi danh sách sau khi lấy ra thành công
                    else:
                        print("\n=====================================\n")
                        print("Phương tiện Không được phép lấy.")
                else:
                    if vehicle_to_remove.vehicle_type == 'Xe đạp':
                        fee = BICYCLE_LOST_TICKET_FINE
                    elif vehicle_to_remove.vehicle_type == 'Xe máy':
                        fee = MOTORCYCLE_LOST_TICKET_FINE
                    print("Chi phí:", fee)
                    has_signed_document = input("Xác nhận người gửi xe đã nộp phí và biên bản (Y/N): ").upper() == 'Y'
                    if has_signed_document:
                        print("\n=====================================\n")
                        print("Phương tiện đã được lấy ra thành công.")
                        self.vehicles.remove(vehicle_to_remove)  # Loại bỏ phương tiện khỏi danh sách sau khi lấy ra thành công
                    else:
                        print("\n=====================================\n")
                        print("Phương tiện Không được phép lấy ra.")


    def display_sorted_vehicles(self):
        print("\n=====================================\n")
        vehicle_type = input("Nhập loại phương tiện (1: Xe đạp, 2: Xe máy): ")

        if vehicle_type not in ['1', '2']:
            print("Lựa chọn không hợp lệ!")
            return

        sort_order = input("Chọn thứ tự sắp xếp (1: Tăng dần, 2: Giảm dần): ")
        if sort_order not in ['1', '2']:
            print("Lựa chọn không hợp lệ!")
            return

        # Lọc danh sách theo loại phương tiện
        filtered_list = [vehicle for vehicle in self.vehicles if (vehicle_type == '1' and isinstance(vehicle, Bicycle)) or (vehicle_type == '2' and isinstance(vehicle, Motorcycle))]

        # Sắp xếp danh sách
        sorted_list = sorted(filtered_list, key=lambda x: x.check_in_time, reverse=(sort_order == '2'))

        # In danh sách
        for vehicle in sorted_list:
            print("\n=====================================\n")
            print(vehicle)



    def get_alert_list(self):
        alert_list = []
        current_date = datetime.datetime.now().date()
        for vehicle in self.vehicles:
            entry_date = vehicle.check_in_time.date()
            if vehicle.vehicle_type == "Xe đạp":
                if (current_date - entry_date).days >= 3:
                    alert_list.append(vehicle)
            elif vehicle.vehicle_type == "Xe máy":
                if (current_date - entry_date).days >= 5:
                    alert_list.append(vehicle)
        return alert_list


    def get_lost_ticket_vehicles(self):
        lost_ticket_vehicles = []
        current_date = datetime.datetime.now().date()
        for vehicle in self.vehicles:
            entry_hour = vehicle.check_in_time.hour
            if entry_hour >= 8 and entry_hour <= 22:
                if vehicle.ticket_id == "":
                    lost_ticket_vehicles.append(vehicle)
        return lost_ticket_vehicles

    def get_motorcycles_with_multiple_entries(self):
        motorcycle_counts = {}
        for vehicle in self.vehicles:
            if vehicle.vehicle_type == "Xe máy":
                entry_date = vehicle.check_in_time.date()
                if entry_date == datetime.datetime.now().date():
                    license_plate = vehicle.license_plate
                    if license_plate in motorcycle_counts:
                        motorcycle_counts[license_plate] += 1
                    else:
                        motorcycle_counts[license_plate] = 1
        multiple_entry_motorcycles = [vehicle for vehicle, count in motorcycle_counts.items() if count >= 2]
        return [vehicle for vehicle in self.vehicles if vehicle.license_plate in multiple_entry_motorcycles]

    def get_motorcycles_with_multiple_entries_today(self):
        motorcycle_counts = {}
        for vehicle in self.vehicles:
            if isinstance(vehicle, Motorcycle):
                entry_date = vehicle.check_in_time.date()
                if entry_date == datetime.datetime.now().date():
                    license_plate = vehicle.license_plate
                    if license_plate in motorcycle_counts:
                        motorcycle_counts[license_plate] += 1
                    else:
                        motorcycle_counts[license_plate] = 1
        multiple_entry_motorcycles = [license_plate for license_plate, count in motorcycle_counts.items() if count >= 2]
        return [vehicle for vehicle in self.vehicles if isinstance(vehicle, Motorcycle) and vehicle.license_plate in multiple_entry_motorcycles]

    def display_daily_vehicles(self, daily_vehicles):
        print("\n=====================================\n")
        print("\nDanh sách thống kê lượt gửi xe trong ngày:")
        for vehicle in daily_vehicles:
            print("\n=====================================\n")
            print(vehicle)

# Test
vehicle_manager = ParkingLot()
choice = ''
while choice != '0':
    print("\n=====================================\n")
    print("\nChọn chức năng:")
    print("1. Thêm phương tiện đậu vào")
    print("2. Lấy phương tiện ra")
    print("3. Hiển thị số lượng phương tiện đang đậu")
    print("4. Hiển thị danh sách phương tiện đang đậu")
    print("5. Tính doanh thu của ngày hiện tại")
    print("6. Hiển thị danh sách phương tiện cần cảnh báo")
    print("7. Hiển thị danh sách phương tiện bị mất vé trong ngày")
    print("8. Hiển thị danh sách xe máy có lượt gửi từ 2 lần trong ngày hiện tại")
    print("9. Hiển thị danh sách thống kê lượt gửi xe máy")
    print("0. Thoát")
    choice = input("Nhập lựa chọn của bạn: ")

    if choice == '1':
        vehicle_type = input("Nhập loại phương tiện (1: Xe đạp, 2: Xe máy): ")
        if vehicle_type not in ['1', '2']:
            print("Lựa chọn không hợp lệ!")
            continue

        ticket_id = input("Nhập mã vé: ")
        if not ticket_id:
            print("Vui lòng nhập mã vé!")
            continue

        if vehicle_type == '2':
            license_plate = input("Nhập biển số xe: ")
            if not license_plate:
                print("Vui lòng nhập biển số xe!")
                continue

        if vehicle_type == '1':
            bicycle = Bicycle(datetime.datetime.now(), ticket_id)
            vehicle_manager.add_vehicle(bicycle)
        elif vehicle_type == '2':
            check_in_time = datetime.datetime.now()
            motorcycle = Motorcycle(check_in_time, license_plate, ticket_id)
            vehicle_manager.add_vehicle(motorcycle)
            # Thêm xe máy vào danh sách thống kê
            vehicle_manager.add_daily_vehicle(motorcycle)


    # trong th lấy xe từ 22h 05 - đến 8h ngày hôm sau không đc lấy xe
    elif choice == '2':
        current_time = datetime.datetime.now().time()
        
        # Kiểm tra nếu thời gian hiện tại nằm trong khoảng không cho phép lấy xe ra
        if (datetime.time(22, 5) <= current_time <= datetime.time(23, 59)) or (datetime.time(0, 0) <= current_time <= datetime.time(8, 0)):
            print("Hiện tại không thể lấy xe ra.")
        else:
            vehicle_type = input("Nhập loại phương tiện (1: Xe đạp, 2: Xe máy): ")
            if vehicle_type not in ['1', '2']:
                print("Lựa chọn không hợp lệ!")
                continue

            ticket_id = input("Nhập mã vé: ")

            # Tìm kiếm phương tiện với mã vé
            vehicle_to_remove = None
            for vehicle in vehicle_manager.vehicles:
                if vehicle.ticket_id == ticket_id:
                    vehicle_to_remove = vehicle
                    break

            if vehicle_to_remove is None:
                print("\n=====================================\n")
                print("Không tìm thấy phương tiện với mã vé đã nhập.")
            else:
                if (vehicle_type == '1' and isinstance(vehicle_to_remove, Bicycle)) or \
                (vehicle_type == '2' and isinstance(vehicle_to_remove, Motorcycle)):
                    if vehicle_type == '2':
                        license_plate = input("Nhập biển số xe: ")
                        if license_plate != vehicle_to_remove.license_plate:
                            print("\n=====================================\n")
                            print("Biển số xe không khớp với dữ liệu trong hệ thống. Không thể lấy phương tiện ra.")
                            continue

                    # Kiểm tra có vé hay không
                    has_ticket = input("Có vé xe (Y/N): ").upper() == 'Y'
                    if has_ticket:
                        # In chi phí nếu có vé
                        fee = vehicle_to_remove.calculate_fee(datetime.datetime.now(), False)
                        print("Chi phí:", fee)
                        has_paid_fee = input("Đã nộp tiền phí (Y/N): ").upper() == 'Y'
                        if has_paid_fee:
                            print("\n=====================================\n")
                            print("Phương tiện đã được lấy ra thành công.")
                            vehicle_manager.doanh_thu += fee  # Cộng vào biến doanh thu
                            vehicle_manager.vehicles.remove(vehicle_to_remove)  # Loại bỏ phương tiện khỏi danh sách sau khi lấy ra thành công
                        else:
                            print("\n=====================================\n")
                            print("Phương tiện Không được phép lấy.")
                    else:
                        # In chi phí nếu không có vé
                        if isinstance(vehicle_to_remove, Bicycle):
                            fee = BICYCLE_LOST_TICKET_FINE
                        elif isinstance(vehicle_to_remove, Motorcycle):
                            fee = MOTORCYCLE_LOST_TICKET_FINE
                        print("Chi phí:", fee)
                        # Xác nhận đã nộp phí và biên bản nếu không có vé
                        has_signed_document = input("Xác nhận người gửi xe đã nộp phí và biên bản (Y/N): ").upper() == 'Y'
                        if has_signed_document:
                            print("\n=====================================\n")
                            print("Phương tiện đã được lấy ra thành công.")
                            vehicle_manager.doanh_thu += fee  # Cộng vào biến doanh thu
                            vehicle_manager.vehicles.remove(vehicle_to_remove)  # Loại bỏ phương tiện khỏi danh sách sau khi lấy ra thành công
                        else:
                            print("\n=====================================\n")
                            print("Phương tiện Không được phép lấy ra.")
                else:
                    print("\n=====================================\n")
                    print("Loại phương tiện không khớp với dữ liệu trong hệ thống.")

    elif choice == '3':
        print("\n=====================================\n")
        print("\nSố lượng phương tiện đang đậu:", len(vehicle_manager.vehicles))

    elif choice == '4':
        vehicle_manager.display_sorted_vehicles()

    ## do đã thêm diềud kiện không đc lấy xe ra trong trường hợp 22h05 đến 8h hôm sau nên doanh thu sẽ là 8h sáng đến 22h05 cùng ngày
    elif choice == '5':
        print("\n=====================================\n")
        print("Doanh thu của ngày hiện tại:", vehicle_manager.doanh_thu)


    elif choice == '6':
        print("Danh sách phương tiện cần cảnh báo:")
        vehicle_manager.add_alert_vehicles()


    elif choice == '7':
        lost_ticket_vehicles = vehicle_manager.lost_ticket_vehicles
        print("\n=====================================\n")
        print("\nDanh sách phương tiện bị mất vé trong ngày:")
        for vehicle in lost_ticket_vehicles:
            print("\n=====================================\n")
            print(vehicle)

    elif choice == '8':
        # Tạo một từ điển để đếm số lần xuất hiện của mỗi biển số xe
        motorcycle_counts = {}
        today = datetime.datetime.now().date()
        start_of_day = datetime.datetime.combine(today, datetime.time.min)
        end_of_day = datetime.datetime.combine(today, datetime.time.max)
        for motorcycle in vehicle_manager.daily_vehicles:
            if isinstance(motorcycle, Motorcycle):
                entry_time = motorcycle.check_in_time
                if start_of_day <= entry_time <= end_of_day:
                    license_plate = motorcycle.license_plate
                    if license_plate in motorcycle_counts:
                        motorcycle_counts[license_plate] += 1
                    else:
                        motorcycle_counts[license_plate] = 1

        # Lọc ra các xe máy đã gửi từ 2 lần trở lên
        motorcycles_multiple_entries = [license_plate for license_plate, count in motorcycle_counts.items() if count >= 2]

        # In ra thông tin của các xe máy đã gửi từ 2 lần trở lên
        print("\n=====================================\n")
        print("\nDanh sách xe máy đã gửi từ 2 lần trở lên trong ngày:")
        for license_plate in motorcycles_multiple_entries:
            count = motorcycle_counts[license_plate]
            print("\n=====================================\n")
            print(f"Biển số xe: {license_plate}  số lần: {count}")





    elif choice == '9':
        print("\n=====================================\n")
        print("\nDanh sách thống kê lượt gửi xe máy :")
        for vehicle in vehicle_manager.daily_vehicles:
            print("\n=====================================\n")
            print(vehicle)

    elif choice == '0':
        print("Thoát")
    else:
        print("\n=====================================\n")
        print("Lựa chọn không hợp lệ!")
