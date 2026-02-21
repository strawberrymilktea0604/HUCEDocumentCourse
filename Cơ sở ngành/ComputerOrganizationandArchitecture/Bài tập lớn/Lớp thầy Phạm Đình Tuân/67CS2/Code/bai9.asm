    .data
    prompt:   .asciiz "Nhap chuoi: "
    result:   .asciiz "Chieu dai cua chuoi la: "
    newline:  .asciiz "\n"
    buffer:   .space 100

    .text
    .globl main

main:
    # Hiển thị thông báo "Nhập chuỗi: " và đợi người dùng nhập chuỗi
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 8
    la $a0, buffer
    li $a1, 100
    syscall

    # Tính chiều dài của chuỗi
    la $t0, buffer
    li $t1, 0    # Đếm số ký tự trong chuỗi

    LOOP:
        lb $t2, 0($t0)    # Đọc ký tự từ chuỗi
        beqz $t2, END     # Nếu gặp ký tự '\0' (kết thúc chuỗi) thì thoát khỏi vòng lặp
        
        addi $t0, $t0, 1  # Di chuyển con trỏ đến phần tử kế tiếp trong chuỗi
        addi $t1, $t1, 1  # Tăng biến đếm lên 1

        j LOOP

    END:
    # Hiển thị kết quả
    li $v0, 4
    la $a0, result
    syscall
    sub $t1,$t1, 1

    move $a0, $t1   # Di chuyển giá trị chiều dài vào thanh ghi $a0
    li $v0, 1
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall
