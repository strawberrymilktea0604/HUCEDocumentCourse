.data
s1:    .asciiz "Nhap mot ky tu: "
s2:    .asciiz "\nKy tu lien truoc: "
s3:   .asciiz "\nKy tu lien sau: "

.text
    # In ra chuỗi "Nhap mot ky tu: "
    li $v0, 4
    la $a0, s1
    syscall

    # Nhập một ký tự từ bàn phím
    li $v0, 12
    syscall
    move $t0, $v0

    # In ra chuỗi "Ky tu lien truoc: "
    li $v0, 4
    la $a0, s2
    syscall

    # In ra ký tự liền trước
    subi $t1, $t0, 1
    li $v0, 11
    move $a0, $t1
    syscall

    # In ra chuỗi "Ky tu lien sau: "
    li $v0, 4
    la $a0, s3
    syscall

    # In ra ký tự liền sau
    addi $t2, $t0, 1
    li $v0, 11
    move $a0, $t2
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall