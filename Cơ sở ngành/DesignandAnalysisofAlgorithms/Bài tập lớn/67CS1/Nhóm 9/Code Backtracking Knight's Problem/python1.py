import time
def printSolution(n, board):
    for i in range(n):
        for j in range(n):
            print(board[i][j] + 1, end=' ')
        print()

def knight_tour(n, x, y):
    board = [[-1 for i in range(n)] for j in range(n)]
    if not knight_tour_helper(n = n, board = board, x = x, y = y, counter = 0):
        print("Khong tim thay duong di")
    else:
        printSolution(n, board)
    
def knight_tour_helper(n, board, x, y, counter):
    if counter == n * n:
        return True
    if (x < 0) or (x >= n) or (y < 0) or (y >= n) or board[y][x] != -1:
        return False
    board[y][x] = counter
    for x_move, y_move in zip([-2, -2, -1, -1, 1, 1, 2, 2], [-1, 1, -2, 2, -2, 2, -1, 1]):
        if knight_tour_helper(n, board, x + x_move, y + y_move, counter + 1):
            return True
    board[y][x] = -1
    return False

def main():
   
    a = int(input("Nhap n: "))
    while (a < 0) or (a > 11):
        print("So luong ban co phai dung quy chuan! Nhap lai!")
        a = int(input("Nhap n: "))
    else:
        print("Quy tac nhap : dem tu 0")
        b = int(input("Nhap toa do x: "))     
        while (b < 0) or (b > a - 1):
           print("Nhap lai toa do!")
           b = int(input("Nhap toa do x: "))
        else:
            c = int(input("Nhap toa do y: "))
            while (c < 0) or (c > a - 1):
                print("Nhap lai toa do!")
                c = int(input("Nhap toa do y: "))
            else:
                start_time = time.time()
                knight_tour(a, b, c)
    end_time= time.time()
    thoi_gian = end_time - start_time
    print("thoi gian: {0}".format(thoi_gian)+"[ses]")
                       
if __name__ == "__main__":
    main()
