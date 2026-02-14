# Khai báo các hằng số
.data
prompt1: .asciiz "Nhap vao so nguyen thu nhat: "
prompt2: .asciiz "Nhap vao so nguyen thu hai: "
result_sum: .asciiz "Tong = "
result_diff: .asciiz "Hieu = "
result_prod: .asciiz "Tich = "
result_div: .asciiz "Thuong = "
newline: .asciiz "\n"

# Khai báo các biến
.text
.globl main
main:
    # In prompt1 và đọc số nguyên thứ nhất
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, prompt1
    syscall

    li $v0, 5              # đọc số nguyên
    syscall
    move $s0, $v0          # lưu số nguyên thứ nhất vào $s0

    # In prompt2 và đọc số nguyên thứ hai
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, prompt2
    syscall

    li $v0, 5              # đọc số nguyên
    syscall
    move $s1, $v0          # lưu số nguyên thứ hai vào $s1

    # Tính tổng
    add $t0, $s0, $s1      # $t0 = $s0 + $s1

    # In tổng ra màn hình
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, result_sum
    syscall

    li $v0, 1              # hiển thị số nguyên
    move $a0, $t0
    syscall

    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, newline
    syscall
    
    # Tính hiệu
    sub $t0, $s0, $s1      # $t0 = $s0 - $s1

    # In hiệu ra màn hình
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, result_diff
    syscall

    li $v0, 1              # hiển thị số nguyên
    move $a0, $t0
    syscall
    
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, newline
    syscall
    
    # Tính tích
    mult $s0, $s1          # $s0 * $s1
    mflo $t0               # lưu kết quả vào $t0

    # In tích ra màn hình
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, result_prod
    syscall

    li $v0, 1              # hiển thị số nguyên
    move $a0, $t0
    syscall
    
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, newline
    syscall
    
    # Tính thương
    div $s0, $s1           # $s0 / $s1
    mflo $t0               # lưu kết quả vào $t0

    # In thương ra màn hình
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, result_div
    syscall

    li $v0, 1              # hiển thị số nguyên
    move $a0, $t0
    syscall

    # Xuống dòng sau khi hoàn thành
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, newline
    syscall

    # Kết thúc chương trình
    li $v0, 10             # kết thúc chương trình
    syscall
