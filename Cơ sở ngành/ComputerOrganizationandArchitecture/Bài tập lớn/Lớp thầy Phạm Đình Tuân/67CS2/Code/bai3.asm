.data
input_prompt:   .asciiz "Nhap vao mot ky tu hoa: "
lowercase_letter:   .asciiz "Ky tu hoa duoc chuyen thanh chu thuong: "

.text
.globl main

main:
    # In ra một thông báo để nhập vào ký tự hoa
    li $v0, 4
    la $a0, input_prompt
    syscall

    # Nhập ký tự từ bàn phím
    li $v0, 12
    syscall
    move $t0, $v0

    # Chuyển đổi ký tự hoa thành ký tự thường
    addi $t0, $t0, 32

    # In ra kết quả chuyển đổi
    li $v0, 4
    la $a0, lowercase_letter
    syscall

    li $v0, 11
    move $a0, $t0
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall
