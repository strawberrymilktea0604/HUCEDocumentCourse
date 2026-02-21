str = input("nhap chuoi: ")
str = str + "abc"
# for index in range(len(str)):
#     print(str[index])

#n g u y e n   v a n    a
#0 1 2 3 4 5 6 7 8 9 10 11

print("\nDuyệt ngược (chỉ mục):")
for i in range(len(str) - 1, -1, -1):
    print(f"Chỉ mục {i}: {str[i]}")


print("do dai chuoi:", len(str))

print("chuoi in hoa:", str.upper())

print("chuoi in thuong:", str.lower())

str2 = str[::-1] # dao nguoc chuoi

if str == str2:
    print("chuoi doi xung")
else:
    print("chuoi khong doi xung")

str_replaced = str.replace(" ", "_")
print("chuoi sau khi thay the khoang trang bang dau gach duoi:", str_replaced)

print("vi tri cua chu 'a' trong chuoi:", str.find('a'))

print("chuoi cat tu vi tri 2 den vi tri 5:", str[2:6])

print("Chuoi sau khi cat bang khoang trang ", str.split(" "))

