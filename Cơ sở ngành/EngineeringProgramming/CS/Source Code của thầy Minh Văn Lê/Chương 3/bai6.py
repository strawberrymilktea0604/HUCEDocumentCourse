"""
Yêu cầu tính trung bình cộng điểm từ file score2.csv,
Lưu ý bỏ qua dòng tiêu đề
"""
total = 0
count = 0
is_first_line = True
with open("score2.csv", "r") as f:
    for line in f:
        if is_first_line:
            is_first_line = False
            continue
        parts = line.strip().split(",")
        score = float(parts[1])
        total += score
        count += 1
average = total/count
print(f"diem trung binh tat ca cac mon: {average:.2f}")