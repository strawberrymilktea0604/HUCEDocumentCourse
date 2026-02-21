# Câu 1: Đếm tần số từ và in ra từ có tần suất lớn nhất

from collections import Counter

# Đường dẫn file, ví dụ: 'input.txt'
file_path = 'input.txt'

with open(file_path, 'r', encoding='utf-8') as f:
    text = f.read().lower()

# Tách từ, bỏ ký tự đặc biệt
import re
words = re.findall(r'\b\w+\b', text)

# Đếm tần suất
freq = Counter(words)

# Tìm tần suất lớn nhất
max_freq = max(freq.values())

print("Các từ có tần suất cao nhất:")
for word, count in freq.items():
    if count == max_freq:
        print(f"{word}: {count}")
