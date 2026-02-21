import sys
with open('TELECOM.INP', 'r') as f:
    f = open("TELECOM.INP", 'r')
    n = int(f.readline().rstrip('\n'))
    print(n)
    lines = f.readlines()
    lines = [item.rstrip("\n") for item in lines]
    newList = list()
    for item in lines:
            item = item.split()
            item = tuple(int(items) for items in item)
            newList.append(item)                
    f.close()
    print(newList)