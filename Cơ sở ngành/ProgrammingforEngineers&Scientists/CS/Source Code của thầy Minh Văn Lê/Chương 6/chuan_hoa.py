import numpy as np

# Dữ liệu mẫu
data = np.array([[100, 200, 300],
[150, 250, 350],
[200, 300, 400]])
print("Du lieu goc:")
print(data)
# Chuẩn hóa Min-Max về [0, 1]
data_min = np.min(data)
data_max = np.max(data)
normalized = (data - data_min) / (data_max - data_min)
print("\nChuan hoa Min-Max:")
print(normalized)
# Chuẩn hóa Z-score (mean=0, std=1)
mean = np.mean(data)
std = np.std(data)
z_normalized = (data - mean) / std
print("\nChuan hoa Z-score:")
print(z_normalized)
# Chuẩn hóa theo từng cột
col_means = np.mean(data, axis=0)
print("\nTrung binh theo cot:")
print(col_means)
col_stds = np.std(data, axis=0)
print("\nDo lech chuan theo cot:")
print(col_stds)
col_normalized = (data - col_means) / col_stds
print("\nChuan hoa theo cot:")
print(col_normalized)