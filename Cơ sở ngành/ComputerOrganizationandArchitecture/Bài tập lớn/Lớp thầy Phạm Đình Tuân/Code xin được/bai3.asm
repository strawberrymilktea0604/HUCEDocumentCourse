.data  

  Nhap: .asciiz "Nhap vao ky tu hoa: "
  KytuHoa: .asciiz " Ky tu thuong: "

.text  

main:  

  la $a0, Nhap  
  li $v0,4
  syscall             #cum nay de in ra Nhap
  
  li $v0,12           #nhap vao ky tu in hoa, gia tri ky tu duoc dua vao $v0
  syscall  

  addi $s0, $v0, 0    #gan gia tri ky tu in hoa vua nhap vao $s0
  
  la $a0, KytuHoa     
  li $v0,4
  syscall             #cum nay de in ra KytuHoa
  
  addi $a0, $s0,32    #tinh ky tu thuong
  li   $v0, 11        #in ra ky tu thuong
  syscall 
