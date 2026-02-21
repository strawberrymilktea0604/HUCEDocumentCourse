.data  

  Nhap: .asciiz "Nhap vao ky tu: "
  Kytutruoc: .asciiz "\nKy tu dung truoc "
  Kytusau: .asciiz "\nKy tu dung sau "
  
.text  

main:  

  li $v0,4            
  la $a0, Nhap   
  syscall              #cum nay de in ra Nhap
  
  li $v0,12            #nhap vao ky tu, gia tri ky tu duoc dua vao $v0
  syscall          

  addi $s0, $v0, 0     #gan gia tri ky tu vua nhap vao $s0
  
  li $v0,4
  la $a0, Kytutruoc
  syscall              #cum nay de in ra Kytutruoc
  
  addi $a0, $s0, -1    #tinh ky tu lien truoc
  li   $v0,11          #in ra ky tu lien truoc
  syscall  

  li $v0,4
  la $a0, Kytusau  
  syscall             #cum nay de in ra Kytusau

  addi $a0, $s0, 1    #tinh ky tu lien sau
  li   $v0,11         #in ra ky tu lien sau
  syscall         

 

