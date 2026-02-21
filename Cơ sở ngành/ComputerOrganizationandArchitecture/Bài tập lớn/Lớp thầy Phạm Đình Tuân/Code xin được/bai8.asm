.data
nhapSo: .asciiz "Nhap mot so: "
tongtu1den: .asciiz "\nTong tu 1 den "
la: .asciiz " la: "

.text
li $v0,4
la $a0,nhapSo
syscall              #in ra nhapSo

li $v0,5            #nhap so, gia tri so vua nhap duoc luu vao $v0
syscall

addi $s0,$v0,1      #tao gia tri $s0 de lam vong lap

li  $t1,1
li  $t2,0
slt $t0,$t1,$s0
bne $t0,$0,Tinhtong
Tinhtong:

add $t2,$t1,$t2
addi $t1,$t1,1
slt $t0,$t1,$s0
bne $t0,$0,Tinhtong   #vong lap de tinh tong

In:                                  #in ra ket qua
li $v0,4
la $a0,tongtu1den
syscall

li $v0,1
addi $a0,$s0,-1
syscall

li $v0,4
la $a0,la
syscall

li $v0,1
move $a0,$t2
syscall
