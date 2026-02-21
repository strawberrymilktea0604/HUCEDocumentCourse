# Khai báo các hằng số
.data
prompt1: .asciiz "Nhập số nguyên thứ nhất: "
prompt2: .asciiz "Nhập số nguyên thứ hai: "
result: .asciiz "Số lớn hơn là "

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

    # So sánh hai số nguyên
    beq $s0, $s1, equal    # nếu số thứ nhất bằng số thứ hai, nhảy đến nhãn "equal"

    bgt $s0, $s1, greater  # nếu số thứ nhất lớn hơn số thứ hai, nhảy đến nhãn "greater"

    move $t0, $s1          # đưa số thứ hai vào $t0 nếu không thoả các điều kiện trên
    j end                  # nhảy đến nhãn "end"

equal:
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, result
    syscall

    move $a0, $s0          # in ra số thứ nhất
    li $v0, 1              # hiển thị số nguyên
    syscall
    j end                  # nhảy đến nhãn "end"

greater:
    li $v0, 4              # hệ thống hiển thị chuỗi
    la $a0, result
    syscall

    move $a0, $s1          # in ra số thứ hai
    li $v0, 1              # hiển thị số nguyên
    syscall

end:
    # Kết thúc chương trình
    li $v0, 10             # kết thúc chương trình
    syscall
