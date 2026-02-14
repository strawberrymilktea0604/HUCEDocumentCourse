.data
input_message: .asciiz "Nhap mot ky tu: "
prev_char_message: .asciiz "Ky tu lien truoc: "
next_char_message: .asciiz "Ky tu lien sau: "

.text
.globl main
main:
  # Xuất thông báo "Nhap mot ky tu:"
  li $v0, 4
  la $a0, input_message
  syscall

  # Đọc ký tự từ người dùng
  li $v0, 12
  syscall
  move $t0, $v0  # Lưu trữ ký tự được nhập vào thanh ghi $t0

  # In ký tự liền trước
  li $v0, 4
  la $a0, prev_char_message
  syscall
  addi $t1, $t0, -1  # Tính ký tự liền trước
  move $a0, $t1
  li $v0, 11
  syscall

  # In ký tự liền sau
  li $v0, 4
  la $a0, next_char_message
  syscall
  addi $t2, $t0, 1   # Tính ký tự liền sau
  move $a0, $t2
  li $v0, 11
  syscall

  # Kết thúc chương trình
  li $v0, 10
  syscall