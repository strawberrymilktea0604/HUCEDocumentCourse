import sys

def print_line_sum_of_line(filename):
    except FileNotFoundError:
       print("The file couldn't be found. " + "This program stops here.")
       return
    
    lines = open.readlines()
    print(lines)
    open.close() 
    
    
    for line in lines:
        tongphantutungdong = 0
        k = line.split()
        for i in k:
            if(i.isdemical()):
               tongphantutungdong += int(i);
    print(tongphantutungdong)
    
print_line_sum_of_line("test.txt")