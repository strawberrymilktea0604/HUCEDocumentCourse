import sys
try:
    mofile = open("in.txt", 'r')
except FileNotFoundError:
    print("Khong tim thay file")
    sys.exit(1)
    
    
lines = mofile.readlines()
mofile.close()
xuatfile = open('output.txt', 'tw')
    
for line in lines:
    k = line.split(";")
    x = eval(k[1])
    xuatfile.write("{}\n".format(eval(k[0])))
xuatfile.close()