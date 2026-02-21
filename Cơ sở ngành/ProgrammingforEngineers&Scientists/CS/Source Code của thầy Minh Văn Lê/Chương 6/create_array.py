import numpy as np

# Ma trận không (zeros)
zeros = np.zeros((3, 4))
print("Ma tran khong 3x4:")
print(zeros)
# Ma trận một (ones)
ones = np.ones((2, 3))
print("\nMa tran mot 2x3:")
print(ones)
# Ma trận đơn vị (identity matrix)
identity = np.eye(4)
print("\nMa tran don vi 4x4:")
print(identity)
# Ma trận với giá trị cụ thể
full = np.full((3, 3), 7)
print("\nMa tran toan gia tri 7:")
print(full)
# Ma trận đường chéo
diag = np.diag([1, 2, 3, 4])
print("\nMa tran duong cheo:")
print(diag)
