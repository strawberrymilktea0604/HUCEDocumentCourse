    .data
    prompt:   .asciiz "Nhap vao phan tu thu "
    message:  .asciiz " "
    newline:  .asciiz "\n"
    size:     .word 0
    array:    .space 100
    
    .text
    .globl main

main:
    # Nhập kích thước mảng từ người dùng
    li $v0, 4
    la $a0, prompt
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0   # Lưu kích thước mảng vào $t0
    
    # In ra màn hình chuỗi "Nhập phần tử thứ i: " và đợi người dùng nhập giá trị
    li $v0, 4
    la $a0, newline
    syscall
    
    li $t1, 0  # Đếm số phần tử đã nhập
    la $t2, array  # Địa chỉ bắt đầu của mảng
    LOOP:
        addi $t1, $t1, 1
        
        li $v0, 4
        la $a0, prompt
        syscall
        
        move $a0, $t1
        li $v0, 1
        syscall
        
        li $v0, 4
        la $a0, message
        syscall
        
        li $v0, 5
        syscall
        
        sw $v0, 0($t2)
        addi $t2, $t2, 4
        
        bne $t1, $t0, LOOP  # Lặp lại nếu số phần tử đã nhập chưa đủ
    
    # In ra mảng đã nhập
    la $t2, array  # Địa chỉ bắt đầu của mảng
    li $t1, 0  # Đếm số phần tử đã in
    
    LOOP2:
        addi $t1, $t1, 1
        
        lw $a0, 0($t2)
        li $v0, 1
        syscall
        
        li $v0, 4
        la $a0, newline
        syscall
        
        addi $t2, $t2, 4
        
        bne $t1, $t0, LOOP2   # Lặp lại cho đến khi đã in hết mảng
    
    # Kết thúc chương trình
    li $v0, 10
    syscall
