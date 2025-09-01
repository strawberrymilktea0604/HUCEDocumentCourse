#in ra tất cả các phần tử của một list
myList = [1,"Hello",5, 5.7]
length = len(myList)
print("Các phần tử của list: ")
# range(n) gồm các số từ 0 tới (n-1)
for index in range(length):
    print(myList[index])