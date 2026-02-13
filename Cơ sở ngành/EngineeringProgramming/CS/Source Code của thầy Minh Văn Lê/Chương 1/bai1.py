cannang = input("Nhập cân nặng (kg): ")
chieucao = input("Nhập chiều cao (m): ")
bmi = float(cannang) / (float(chieucao) ** 2)
print(f"Chỉ số BMI của bạn là: {bmi:.2f}")
if bmi < 18.5:
    print("thiếu cân")
elif bmi > 18.5 and bmi < 25:
    print("bình thường")
elif bmi >= 25 and bmi < 30:
    print("thừa cân")
elif bmi > 30 :
    print("béo phì")