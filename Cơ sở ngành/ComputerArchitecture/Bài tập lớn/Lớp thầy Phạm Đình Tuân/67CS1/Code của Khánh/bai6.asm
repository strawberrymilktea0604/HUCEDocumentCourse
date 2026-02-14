.data
prompt: .asciiz "Nhập vào một ký tự: "
output: .asciiz "Ký tự vừa nhập: "
number_msg: .asciiz "là số"
lowercase_msg: .asciiz "là chữ thường"
uppercase_msg: .asciiz "là chữ hoa"
invalid_msg: .asciiz "không nằm trong [0-9], [a-z], [A-Z]"

.text
.globl main

main:
    # In ra thông báo nhập ký tự
    li $v0, 4
    la $a0, prompt
    syscall

    # Đọc ký tự từ bàn phím
    li $v0, 12
    syscall

    # Kiểm tra xem ký tự có nằm trong [0-9], [a-z], [A-Z] không
    # Nếu nằm trong một trong các phạm vi này, chúng ta sẽ in ra loại của ký tự
    li $t0, 48     # Giá trị ASCII của '0'
    li $t1, 57     # Giá trị ASCII của '9'
    li $t2, 97     # Giá trị ASCII của 'a'
    li $t3, 122    # Giá trị ASCII của 'z'
    li $t4, 65     # Giá trị ASCII của 'A'
    li $t5, 90     # Giá trị ASCII của 'Z'

    # So sánh ký tự với các giá trị ASCII
    beq $a0, $t0, is_number
    beq $a0, $t1, is_number
    beq $a0, $t2, is_lowercase
    beq $a0, $t3, is_lowercase
    beq $a0, $t4, is_uppercase
    beq $a0, $t5, is_uppercase

    # Ký tự không thuộc các phạm vi nêu trên
    li $v0, 4
    la $a0, invalid_msg
    syscall
    j end

is_number:
    li $v0, 4
    la $a0, output
    syscall

    li $v0, 11
    move $a0, $a1
    syscall

    li $v0, 4
    la $a0, number_msg
    syscall
    j end

is_lowercase:
    li $v0, 4
    la $a0, output
    syscall

    li $v0, 11
    move $a0, $a1
    syscall

    li $v0, 4
    la $a0, lowercase_msg
    syscall
    j end

is_uppercase:
    li $v0, 4
    la $a0, output
    syscall

    li $v0, 11
    move $a0, $a1
    syscall

    li $v0, 4
    la $a0, uppercase_msg
    syscall
    j end

end:
    # Kết thúc chương trình
    li $v0, 10
    syscall