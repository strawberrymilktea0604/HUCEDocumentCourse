str = "123456789" #input("nhap chuoi: ") #nguyen van a

index = str.find('3')

print("index = ", index)

last_index = str.find('6')

print("last_index = ", last_index)

result = str[index:last_index + 1]

print("result = ", result)