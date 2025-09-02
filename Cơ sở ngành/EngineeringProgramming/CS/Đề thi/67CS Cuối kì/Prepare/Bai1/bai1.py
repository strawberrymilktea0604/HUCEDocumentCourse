f = open("muvodoi.txt", 'r')
lines = f.readlines()
f.close()

for line in lines:
    k = line.split()
    sortedWord = sorted(k)
    demchu = set(k)
    print(sortedWord)
    for i in demchu:
        print(k.count(i))