total = 0
count = 0
with open("scores.csv", "r") as f:
    for line in f:
        parts = line.strip().split(",")
        score = float(parts[2])
        total += score
        count += 1
average = total / count
print(f"Diem trung binh tat ca cac mon: {average:.2f}")