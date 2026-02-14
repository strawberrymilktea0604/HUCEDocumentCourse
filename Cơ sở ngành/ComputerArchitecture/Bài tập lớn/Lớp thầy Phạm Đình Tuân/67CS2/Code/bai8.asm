    .data
    prompt:  .asciiz "Nhap so nguyen thu n: "
    result:  .asciiz "Tong tu 1 đen n la: "
    newline: .asciiz "\n"

    .text
    .globl main

main:
    # Hiển thị thông báo "Nhập số nguyên: " và đợi người dùng nhập giá trị
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0   # Lưu giá trị n vào $t0

    # Khởi tạo biến đếm và tổng
    li $t1, 1       # $t1: Biến đếm, ban đầu bằng 1
    li $t2, 0       # $t2: Tổng, ban đầu bằng 0

    LOOP:
        add $t2, $t2, $t1   # Cộng giá trị của $t1 vào tổng $t2
        addi $t1, $t1, 1    # Tăng biến đếm lên 1
        
        slt $t3, $t1, $t0   # So sánh biến đếm và giá trị nhập vào
        bne $t3, $zero, LOOP    # Lặp lại nếu biến đếm nhỏ hơn giá trị nhập vào

    # Hiển thị kết quả
    li $v0, 4
    la $a0, result
    syscall

    move $a0, $t2   # Di chuyển giá trị tổng vào thanh ghi $a0
    li $v0, 1
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall
