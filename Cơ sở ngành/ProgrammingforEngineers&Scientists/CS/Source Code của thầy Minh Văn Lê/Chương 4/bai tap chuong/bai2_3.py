# gợi ý: sử dụng tu[::-1] để đảo ngược chuỗi và split chuỗi bằng hàm split()
# txt.split(" ") sẽ tách chuỗi txt thành các từ riêng biệt dựa trên dấu cách

def dao_nguoc_tu(chuoi):
    list = chuoi.split(" ")
    result = " ".join([s[::-1] for s in list])
    return result

a = dao_nguoc_tu("Hello World")
print(a)