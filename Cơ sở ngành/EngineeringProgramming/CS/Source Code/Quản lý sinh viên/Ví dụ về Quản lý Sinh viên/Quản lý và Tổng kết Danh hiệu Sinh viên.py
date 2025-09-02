import numpy



class Student:
    def __init__(self, name: str, id: str, home_town: str, grades: int):
        self.name               = name
        self.id                 = id
        self.home_town          = home_town
        self.grades             = grades

        self.avarage_grade      = numpy.array(grades).mean()
        if self.avarage_grade >= 8.:
            self.label              = 'Giỏi'
        elif self.avarage_grade >= 6.5:
            self.label              = 'Khá'
        elif self.avarage_grade >= 5.:
            self.label              = 'Trung bình'
        else:
            self.label              = 'Kém'
            
            
class StudentsManager:
    def __init__(self):
        n_str                   = input('Input number of students: ')
        assert n_str.isnumeric(), 'Number of students must be a number'
        self.n                  = int(n_str)

        k_str                   = input('Input number of subjects: ')
        assert n_str.isnumeric(), 'Number of subjects must be a number'
        self.k                  = int(k_str)

        self.students           = []
        for student_index in range(self.n):
            # name
            name                = input(f'Input name of student at index {student_index}: ')
            assert              name != '', 'Student name must not be empty'

            # hometown
            home_town           = input(f'Input hometown of student at index {student_index}: ')

            # student id with leading zeros: 001, 011, ...
            id                      = f'{student_index:03d}'

            # student grades
            grades                  = []
            while grades == []:
                grades                  = self.input_student_grades(name)

            # student object
            student                 = Student(name, id, home_town, grades)
            self.students.append(student)



    def input_student_grades(self, name):
        k_grades_str            = input(f'Input grades for {self.k} subjects of {name}, splitted by a space character: \n')
        k_grades_strs           = k_grades_str.split()

        flags_0                 = [k_str.isnumeric() for k_str in k_grades_strs]
        cond_0                  = all(flags_0)
        if not cond_0:
            print('Error: Grades must be numbers')
            return []

        flags_1                 = [0 <= int(k_str) <= 10 for k_str in k_grades_strs]
        cond_1                  = all(flags_1)
        if not cond_1:
            # only works on terminal, not on colab
            # false_idxs                  = np.argwhere(~np.array(cond_1)).flatten()
            # k_grades_strs               = np.array(k_grades_strs, dtype='<U100')
            # k_grades_strs[false_idxs]   = np.array([turn_red(s) for s in k_grades_strs[false_idxs]])
            # print(' '.join(k_grades_strs.tolist()))

            print('Error: Grades must be in the range of 0 to 10')
            return []

        if len(k_grades_strs) != self.k:
            print(f'Error: Number of grades must be exactly {self.k}')
            return []

        k_grades                = [int(k_str) for k_str in k_grades_strs]
        return                  k_grades



    def print_student_info(self):
        print('Students info: \n')
        for student in self.students:
            print(student.__dict__)



    def filter_students(self, label='Giỏi', home_town='Hà Nội'):
        filtered_students       = list(filter(lambda student: (student.label == label) & (student.home_town == home_town), self.students))
        print(f'Students labeled {label} and come from {home_town}: \n')
        for student in filtered_students:
            print(student.__dict__)
            
            
# driver code

n, k            = 3, 5
manager         = StudentsManager()

# a. b.
manager.print_student_info()

# c.
manager.filter_students()