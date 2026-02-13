class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.is_borrowed = False

    def borrow(self):
        if not self.is_borrowed:
            self.is_borrowed = True
            return True
        return False

    def return_book(self):
        self.is_borrowed = False
    
    def __str__(self):
        status = "Da muon" if self.is_borrowed else "Con trong"
        return f"{self.title} - {self.author} ({status})"