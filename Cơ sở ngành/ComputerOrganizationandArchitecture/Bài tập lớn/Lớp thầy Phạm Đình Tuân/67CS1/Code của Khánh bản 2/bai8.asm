.data
s1:     .asciiz "Nhap mot so: "
s2:     .asciiz "Tong tu 1 den "
s3:    .asciiz " la: "

.text
.globl main

main:
    #In ra chuỗi "Nhap mot so: "
    li $v0, 4
    la $a0, s1
    syscall

    #Nhập số nguyên từ bàn phím
    li $v0, 5
    syscall
    move $t0, $v0  #Lưu giá trị n vào $t0

    #Khởi tạo tổng
    li $t1, 0  # tổng = 0

    #Khởi tạo biến đếm
    li $t2, 1  # i = 1

loop:
    #So sánh i với n
    bgt $t2, $t0, done

    #Cộng giá trị của i vào tổng
    add $t1, $t1, $t2

    #Tăng biến đếm i lên 1
    addi $t2, $t2, 1

    #Lặp lại vòng lặp
    j loop

done:
    #In ra chuỗi "Tổng từ 1 đến n là"
    li $v0, 4
    la $a0, s2  #In ra chuỗi "Tổng từ 1 đến"
    syscall

    li $v0, 1
    move $a0, $t0  #In ra giá trị n
    syscall

    li $v0, 4
    la $a0, s3    #In ra chuỗi "la: "
    syscall

    # In ra tổng
    li $v0, 1
    move $a0, $t1
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall