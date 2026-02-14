.data
   nhapKyTu: .asciiz "Nhap ky tu: "
   KT: .asciiz " \nKy tu vua nhap "
   cso: .asciiz " la so "
   ihoa: .asciiz " la chu hoa "
   cthuong: .asciiz " la chu thuong "
   
.text
   li $v0,4
   la $a0,nhapKyTu
   syscall
   
   li $v0,12
   syscall 
   
   move $s0,$v0
   
   add $s1,$0,10
   add $s2,$0,-1
   
   slt $t0,$s0,$s1
   slt $t1,$s2,$s0
   beq $t0,$t1,SO
   
   add $s1,$0,91
   add $s2,$0,64
   
   slt $t0,$s2,$s0
   slt $t1,$s0,$s1
   beq $t0,$t1,HOA
   
   add $s1,$0,123
   add $s2,$0,96
   
   slt $t0,$s2,$s0
   slt $t1,$s0,$s1
   beq $t0,$t1,THUONG
   

   
  
   
 SO:    li $v0,4
        la $a0,KT
        syscall
        
        li $v0,11
        add $a0,$0,$s0
        syscall
        
        li $v0,4
        la $a0,cso
        syscall
        j Exit
        

HOA:    li $v0,4
        la $a0,KT
        syscall
        
        li $v0,11
        add $a0,$0,$s0
        syscall
        
        li $v0,4
        la $a0,ihoa
        syscall
        j  Exit


THUONG: 
        li $v0,4
        la $a0,KT
        syscall
        
        li $v0,11
        add $a0,$0,$s0
        syscall
        
        li $v0,4
        la $a0,cthuong
        syscall     
        j Exit  
             
Exit:        
        
   
   
   
