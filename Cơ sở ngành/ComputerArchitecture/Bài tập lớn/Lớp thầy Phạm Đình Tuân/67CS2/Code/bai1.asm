.data
input_message: .asciiz "Nhap mot chuoi: "
output_message: .asciiz "Chuoi da nhap: "
buffer: .space 100

.text
.globl main
main:
  # Xuất thông báo "Nhap mot chuoi:"
  li $v0, 4
  la $a0, input_message
  syscall

  # Đọc chuỗi từ người dùng
  li $v0, 8
  li $a1, 100
  la $a0, buffer
  syscall

  # Xuất thông báo "Chuoi da nhap:"
  li $v0, 4
  la $a0, output_message
  syscall

  # Xuất chuỗi vừa nhập
  li $v0, 4
  la $a0, buffer
  syscall

  # Kết thúc chương trình
  li $v0, 10
  syscall
 