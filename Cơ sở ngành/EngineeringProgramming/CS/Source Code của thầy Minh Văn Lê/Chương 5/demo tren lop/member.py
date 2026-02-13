class Member:
    def __init__(self, name, member_id):
        self.name = name
        self.member_id = member_id
        self.borrowed_books = []

    def borrow_book(self, book):
        if book.borrow():
            self.borrowed_books.append(book)
            print(f"{self.name} da muon: {book.title}")
            return True
        else:
            print(f"Sach '{book.title}' khong co san")
        return False
    
    def borrow_book_by_name(self, book_title, library):
        for book in library.books:
            if book.title == book_title:
                return self.borrow_book(book)
        print(f"Sach '{book_title}' khong ton tai trong thu vien")
        return False

    def return_book(self, book):
        if book in self.borrowed_books:
            book.return_book()
            self.borrowed_books.remove(book)
            print(f"{self.name} da tra: {book.title}")
        else:
            print(f"{self.name} khong muon sach nay")
