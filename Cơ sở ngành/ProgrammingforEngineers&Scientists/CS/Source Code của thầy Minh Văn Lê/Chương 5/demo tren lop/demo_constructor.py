from classroom import Classroom
from student import Student

# Tạo đối tượng với các giá trị ban đầu
sv1 = Student("Nguyen Van An", 20, "Computer Science")
sv2 = Student("Tran Thi Binh", 21, "Data Science")
print(f"Sinh vien 1: {sv1.name}, {sv1.age} tuoi")
print(f"Sinh vien 2: {sv2.name}, {sv2.age} tuoi")

cr = Classroom("A101", 30)
cr2 = Classroom("B202", 25)