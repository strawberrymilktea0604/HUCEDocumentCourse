# ===== XỬ LÝ CHUỖI TRONG PYTHON =====
# Demo các chức năng xử lý chuỗi thường gặp

# 1. TẠO VÀ GẮNG GIÁ TRỊ CHUỖI
print("=" * 50)
print("1. TẠO VÀ GẮNG GIÁ TRỊ CHUỖI")
print("=" * 50)

str1 = "Hello World"
str2 = 'Python Programming'
str3 = """Chuỗi nhiều dòng
có thể viết thế này"""
str4 = '''Hoặc dùng dấu nháy đơn'''

print(f"str1: {str1}")
print(f"str2: {str2}")
print(f"str3: {str3}")
print(f"str4: {str4}")
print()

# 2. TRUY CẬP KÝ TỰ VÀ SLICE
print("=" * 50)
print("2. TRUY CẬP KÝ TỰ VÀ SLICE")
print("=" * 50)

text = "Python Programming"
print(f"Chuỗi gốc: {text}")
print(f"Ký tự đầu tiên: {text[0]}")
print(f"Ký tự cuối cùng: {text[-1]}")
print(f"5 ký tự đầu: {text[0:5]}")
print(f"Từ vị trí 7 đến hết: {text[7:]}")
print(f"5 ký tự cuối: {text[-5:]}")
print(f"Lấy mỗi ký tự thứ 2: {text[::2]}")
print(f"Đảo ngược chuỗi: {text[::-1]}")
print()

# 3. NỐI CHUỖI
print("=" * 50)
print("3. NỐI CHUỖI")
print("=" * 50)

first_name = "Nguyễn"
last_name = "Văn A"
full_name = first_name + " " + last_name
print(f"Nối bằng +: {full_name}")

greeting = "Xin chào, " * 3
print(f"Nhân chuỗi: {greeting}")

# Nối với join
words = ["Python", "là", "ngôn", "ngữ", "tuyệt", "vời"]
sentence = " ".join(words)
print(f"Nối bằng join: {sentence}")
print()

# 4. ĐỊNH DẠNG CHUỖI
print("=" * 50)
print("4. ĐỊNH DẠNG CHUỖI")
print("=" * 50)

name = "An"
age = 20
height = 1.75

# f-string (Python 3.6+)
print(f"Tên: {name}, Tuổi: {age}, Chiều cao: {height:.2f}m")

# format()
print("Tên: {}, Tuổi: {}, Chiều cao: {:.2f}m".format(name, age, height))

# % formatting (cũ)
print("Tên: %s, Tuổi: %d, Chiều cao: %.2f m" % (name, age, height))
print()

# 5. CHUYỂN ĐỔI CHỮ HOA/THƯỜNG
print("=" * 50)
print("5. CHUYỂN ĐỔI CHỮ HOA/THƯỜNG")
print("=" * 50)

text = "Python Programming Language"
print(f"Gốc: {text}")
print(f"upper(): {text.upper()}")
print(f"lower(): {text.lower()}")
print(f"capitalize(): {text.capitalize()}")
print(f"title(): {text.title()}")
print(f"swapcase(): {text.swapcase()}")
print()

# 6. LOẠI BỎ KHOẢNG TRẮNG
print("=" * 50)
print("6. LOẠI BỎ KHOẢNG TRẮNG")
print("=" * 50)

text = "   Python Programming   "
print(f"Gốc: '{text}'")
print(f"strip(): '{text.strip()}'")
print(f"lstrip(): '{text.lstrip()}'")
print(f"rstrip(): '{text.rstrip()}'")
print()

# 7. TÌM KIẾM VÀ THAY THẾ
print("=" * 50)
print("7. TÌM KIẾM VÀ THAY THẾ")
print("=" * 50)

text = "Python is easy. Python is powerful. Python is popular."
print(f"Gốc: {text}")
print(f"find('Python'): {text.find('Python')}")
print(f"find('Java'): {text.find('Java')}")  # Trả về -1 nếu không tìm thấy
print(f"count('Python'): {text.count('Python')}")
print(f"replace('Python', 'Java'): {text.replace('Python', 'Java')}")
print(f"replace('Python', 'Java', 1): {text.replace('Python', 'Java', 1)}")  # Chỉ thay thế 1 lần
print()

# 8. KIỂM TRA CHUỖI
print("=" * 50)
print("8. KIỂM TRA CHUỖI")
print("=" * 50)

text1 = "Python"
text2 = "12345"
text3 = "Python123"
text4 = "   "

print(f"'{text1}' startswith('Py'): {text1.startswith('Py')}")
print(f"'{text1}' endswith('on'): {text1.endswith('on')}")
print(f"'{text1}' isalpha(): {text1.isalpha()}")
print(f"'{text2}' isdigit(): {text2.isdigit()}")
print(f"'{text3}' isalnum(): {text3.isalnum()}")
print(f"'{text4}' isspace(): {text4.isspace()}")
print(f"'{text1}' islower(): {text1.islower()}")
print(f"'{text1}' isupper(): {text1.isupper()}")
print()

# 9. TÁCH CHUỖI
print("=" * 50)
print("9. TÁCH CHUỖI")
print("=" * 50)

text = "Python,Java,C++,JavaScript"
print(f"Gốc: {text}")
print(f"split(','): {text.split(',')}")

sentence = "Học Python rất thú vị"
print(f"\nGốc: {sentence}")
print(f"split(): {sentence.split()}")

text2 = "Python\nJava\nC++"
print(f"\nGốc: {repr(text2)}")
print(f"splitlines(): {text2.splitlines()}")

# Partition
email = "user@example.com"
print(f"\nEmail: {email}")
print(f"partition('@'): {email.partition('@')}")
print()

# 10. KIỂM TRA CHUỖI CON
print("=" * 50)
print("10. KIỂM TRA CHUỖI CON")
print("=" * 50)

text = "Python Programming Language"
print(f"Chuỗi: {text}")
print(f"'Python' in text: {'Python' in text}")
print(f"'Java' in text: {'Java' in text}")
print(f"'Java' not in text: {'Java' not in text}")
print()

# 11. CANH LỀ CHUỖI
print("=" * 50)
print("11. CANH LỀ CHUỖI")
print("=" * 50)

text = "Python"
print(f"Gốc: '{text}'")
print(f"ljust(20, '-'): '{text.ljust(20, '-')}'")
print(f"rjust(20, '-'): '{text.rjust(20, '-')}'")
print(f"center(20, '-'): '{text.center(20, '-')}'")
print(f"zfill(10): '{text.zfill(10)}'")
print()

# 12. MÃ HÓA VÀ GIẢI MÃ
print("=" * 50)
print("12. LÀM VIỆC VỚI UNICODE")
print("=" * 50)

# Lấy mã ASCII/Unicode
char = 'A'
print(f"ord('{char}'): {ord(char)}")
print(f"chr(65): {chr(65)}")
print(f"ord('Ä'): {ord('Ä')}")
print()

# 13. CÁC PHƯƠNG THỨC NÂNG CAO
print("=" * 50)
print("13. CÁC PHƯƠNG THỨC NÂNG CAO")
print("=" * 50)

# index() - tương tự find() nhưng raise exception nếu không tìm thấy
text = "Python Programming"
try:
    print(f"index('Python'): {text.index('Python')}")
    print(f"index('Java'): {text.index('Java')}")
except ValueError as e:
    print(f"Lỗi: {e}")

# expandtabs()
text_with_tabs = "Name\tAge\tCity"
print(f"\nGốc: {text_with_tabs}")
print(f"expandtabs(8): {text_with_tabs.expandtabs(8)}")

# translate() và maketrans()
text = "Hello 123"
trans_table = str.maketrans("elo", "310")
print(f"\nGốc: {text}")
print(f"translate(): {text.translate(trans_table)}")
print()

# 14. BIỂU THỨC CHÍNH QUY (REGEX) - CƠ BẢN
print("=" * 50)
print("14. BIỂU THỨC CHÍNH QUY (REGEX) - CƠ BẢN")
print("=" * 50)

import re

text = "Email: user@example.com, Phone: 0123456789"
print(f"Chuỗi: {text}")

# Tìm email
email_pattern = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b'
email = re.search(email_pattern, text)
if email:
    print(f"Email tìm thấy: {email.group()}")

# Tìm số điện thoại
phone_pattern = r'\d{10}'
phone = re.search(phone_pattern, text)
if phone:
    print(f"Số điện thoại: {phone.group()}")

# Thay thế số
text2 = "Tôi có 3 quả táo và 5 quả cam"
result = re.sub(r'\d+', 'X', text2)
print(f"\nGốc: {text2}")
print(f"Thay số bằng X: {result}")
print()

# 15. VÍ DỤ THỰC TẾ
print("=" * 50)
print("15. VÍ DỤ THỰC TẾ")
print("=" * 50)

# Kiểm tra mật khẩu mạnh
def check_password_strength(password):
    if len(password) < 8:
        return "Yếu: Mật khẩu phải có ít nhất 8 ký tự"
    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_digit = any(c.isdigit() for c in password)
    has_special = any(not c.isalnum() for c in password)
    
    if has_upper and has_lower and has_digit and has_special:
        return "Mạnh: Mật khẩu đủ điều kiện"
    else:
        return "Trung bình: Nên có chữ hoa, chữ thường, số và ký tự đặc biệt"

passwords = ["abc123", "Abc123", "Abc@123"]
for pwd in passwords:
    print(f"'{pwd}': {check_password_strength(pwd)}")

print()

# Định dạng số điện thoại
def format_phone(phone):
    # Loại bỏ tất cả ký tự không phải số
    digits = ''.join(c for c in phone if c.isdigit())
    if len(digits) == 10:
        return f"({digits[:3]}) {digits[3:6]}-{digits[6:]}"
    return "Số điện thoại không hợp lệ"

phones = ["0123456789", "012-345-6789", "(012)3456789"]
for phone in phones:
    print(f"{phone} -> {format_phone(phone)}")

print()

# Viết hoa chữ cái đầu tiên của mỗi từ
def capitalize_words(text):
    return ' '.join(word.capitalize() for word in text.split())

text = "học python thật thú vị và bổ ích"
print(f"Gốc: {text}")
print(f"Viết hoa: {capitalize_words(text)}")

print()
print("=" * 50)
print("HOÀN THÀNH DEMO XỬ LÝ CHUỖI")
print("=" * 50)
