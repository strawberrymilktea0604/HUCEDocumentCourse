def calculate_average(scores):
    sum = 0
    for score in scores:
        sum += score
    return sum / len(scores)

def classify_grade(average):
    if average >= 8:
        return "Xuất sắc"
    elif average >= 6.5:
        return "Tốt"
    elif average >= 5:
        return "Khá"
    else:
        return "Chưa đạt"

def count_grades(students_data):
    grandes = {
        "Xuất sắc": 0,
        "Tốt": 0,
        "Khá": 0,
        "Chưa đạt": 0
    }
    
    for student in students_data:
        # if student["grade"] == "Xuất sắc":
        #     grandes["Xuất sắc"] += 1
        # elif 
        grandes[student["grade"]] += 1
    return grandes

print("=== HỆ THỐNG QUẢN LÝ ĐIỂM ===")
num_stu = int(input("Nhập số lượng sinh viên: "))

students = []
for index in range(num_stu):
    print(f"Sinh viên {index + 1}:")
    name = input("Tên: ")
    str_scores = input("Nhập điểm các môn (cách nhau bởi dấu phẩy): ")
    scores = list(map(float, str_scores.split(',')))
    # tính điểm tb
    avg_score = calculate_average(scores)
    # xét xếp loại
    grade = classify_grade(avg_score)
    # in kết quả
    print(f"Điểm TB: {avg_score} - Xếp loại: {grade}")
    students.append({
        "name": name,
        "grade": grade
    })

print("=== THỐNG KÊ LỚP ===")
grades = count_grades(students)
print(f"Xuất sắc: {grades['Xuất sắc']} sinh viên")
print(f"Tốt: {grades['Tốt']} sinh viên")
print(f"Khá: {grades['Khá']} sinh viên")
print(f"Chưa đạt: {grades['Chưa đạt']} sinh viên")