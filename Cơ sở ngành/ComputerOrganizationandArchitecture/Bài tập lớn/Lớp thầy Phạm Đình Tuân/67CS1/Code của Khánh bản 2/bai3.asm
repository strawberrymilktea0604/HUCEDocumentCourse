.data
prompt:     .asciiz "Nhap mot ky tu hoa: "
result:     .asciiz "\nKy tu thuong: "

.text
.globl main

main:
    # In ra chuỗi "Nhap mot ky tu hoa: "
    li $v0, 4
    la $a0, prompt
    syscall

    # Nhập một ký tự hoa từ bàn phím
    li $v0, 12
    syscall
    move $t0, $v0  # Lưu vào $t0

    # Kiểm tra xem ký tự có nằm trong khoảng hoa (A-Z) không
    li $t1, 65  # ASCII cho 'A'
    li $t2, 90  # ASCII cho 'Z'


    # Nếu ký tự là hoa (nằm trong khoảng A-Z), chuyển thành thường
    bge $t0, $t1, check_lower
    j done

check_lower:
    ble $t0, $t2, convert_to_lower
    j done

convert_to_lower:
    # Chuyển đổi ký tự hoa thành ký tự thường bằng cách tăng giá trị ASCII lên 32
    li $t3, 32
    add $t0, $t0, $t3

done:
    # In ra chuỗi "Ky tu thuong: "
    li $v0, 4
    la $a0, result
    syscall


    # In ky tu sau khi chuyen
    li $v0, 11
    move $a0, $t0
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall
