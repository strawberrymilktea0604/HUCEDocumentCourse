.data
s1: .asciiz "Nhap mot chuoi: "
s2: .space 30
s3: .asciiz "Chuoi da nhap: "

.text
   #nhập input chuỗi kĩ tự vào
   la $a0, s1
   li $v0, 4  
   syscall
   
   # Nhập một chuỗi từ bàn phím
   li $v0, 8
   la $a0, s2
   la $a1, 30
   syscall
   
   
   # In ra chuỗi "Chuoi da nhap: "
   li $v0, 4
   la $a0, s3
   syscall
   
   # In ra chuỗi đã nhập
   li $v0, 4
   la $a0, s2
   syscall
   
   # Kết thúc chương trình
   li $v0, 10
   syscall
   
   
