from book import Book
from member import Member

class Library:
    def __init__(self, name):
        self.name = name
        self.books = []
        self.members = []

    def add_book(self, book):
        self.books.append(book)
        print(f"Da them sach: {book.title}")

    def register_member(self, member):
        self.members.append(member)
        print(f"Da dang ky thanh vien: {member.name}")

    def display_available_books(self):
        print(f"\nSach con trong tai {self.name}:")
        for book in self.books:
            if not book.is_borrowed:
                print(f" - {book}")

# Sử dụng hệ thống
library = Library("Thu vien HUCE")
# Thêm sách
book1 = Book("Python Programming", "John Smith", "ISBN001")
book2 = Book("Data Structures", "Jane Doe", "ISBN002")
book3 = Book("Algorithms", "Bob Johnson", "ISBN003")
library.add_book(book1)
library.add_book(book2)
library.add_book(book3)

# Đăng ký thành viên
member1 = Member("Nguyen Van An", "M001")
member2 = Member("Tran Thi Binh", "M002")
library.register_member(member1)
library.register_member(member2)

# Mượn sách
print("\n--- Muon sach ---")
member1.borrow_book(book1)
member1.borrow_book(book2)
member2.borrow_book(book1) # Sách đã được mượn
# Hiển thị sách còn trống
library.display_available_books()
# Trả sách
print("\n--- Tra sach ---")
member1.return_book(book1)
# Hiển thị lại
library.display_available_books()


member2.borrow_book_by_name("Algorithms", library)

library.display_available_books()

