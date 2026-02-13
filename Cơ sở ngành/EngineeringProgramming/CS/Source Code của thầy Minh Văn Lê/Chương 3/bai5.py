total =0
count =0
with open("score.txt","r") as f:
    for line in f:
        score = float(line.strip())
        total += score
        count += 1
average = total / count
print(f"Tong tat ca cac so: {total:.2f}")
print(f"Diem trung binh tat ca cac so: {average:.2f}")