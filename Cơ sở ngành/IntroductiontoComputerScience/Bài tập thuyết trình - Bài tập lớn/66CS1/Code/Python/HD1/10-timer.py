
import time
# start = thời điểm ban đầu
start = time.time()
for index in range(10000):
    print("hello")
# end = thời điểm kết thúc
end = time.time()
print(end - start)