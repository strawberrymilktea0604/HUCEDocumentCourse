import numpy as np

# Tạo dữ liệu giả lập 1000 cảm biến (nhiệt độ từ 20-100°C)
temperatures = np.random.uniform(20, 100, 1000)

# Mission 1: Tìm nhiệt độ trung bình
avg_temp = np.mean(temperatures)
print(f"🌡️ Nhiệt độ trung bình: {avg_temp:.2f}°C")

# Mission 2: Tìm các cảm biến NGUY HIỂM (>80°C)
dangerous_sensors = temperatures > 80
print("dangerous_sensors:", dangerous_sensors)
hot_count = np.sum(dangerous_sensors)
print(f"🔥 Số cảm biến quá nóng: {hot_count}")

# Mission 3: Lấy chính xác giá trị của các cảm biến nguy hiểm
critical_temps = temperatures[dangerous_sensors]
print(f"⚠️ Nhiệt độ nguy hiểm: {critical_temps[:5]}...")  # In 5 cái đầu

# Mission 4: Tìm cảm biến HOT nhất
max_temp_index = np.argmax(temperatures)
max_temp = temperatures[max_temp_index]
print(f"🚨 Cảm biến #{max_temp_index} nóng nhất: {max_temp:.2f}°C")