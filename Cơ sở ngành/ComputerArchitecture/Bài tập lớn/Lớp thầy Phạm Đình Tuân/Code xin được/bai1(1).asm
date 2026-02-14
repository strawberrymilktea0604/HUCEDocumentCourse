.data

Nhapn: .asciiz "Nhap n: "
ngoac: .asciiz "["
ngoac1: .asciiz "]="
Inra: .asciiz "Mang vua nhap: "
space: .asciiz " "
array: .word 0:100

.text

li $v0,4
la $a0,Nhapn
syscall         #in ra Nhapn

li $v0,5        #nhap so phan tu, gia tri n duoc luu vao $v0
syscall

move $s0,$v0    #gan gia tri $t0=$v0

li $t1,0
la $t2,array
Nhap:
li $v0,4
la $a0,ngoac
syscall		    #in ra str

li $v0,1
addi $a0,$t1,0     #in ra chi so cua mang
syscall

li $v0,4
la $a0,ngoac1        #in ra str1
syscall

li $v0,5           #nhap phan tu, gia tri cua phan tu luu vao $v0
syscall

sw $v0,($t2)       #luu gia tri mang vao $t2

addi $t1,$t1,1
addi $t2,$t2,4
blt $t1,$s0,Nhap   #vong lap


li $v0,4
la $a0,Inra
syscall

li $t3,0
la $t2,array
In:
lw $t4,($t2)      #doc va luu du lieu o thanh $t2 vao thanh $t4
li $v0,1
move $a0,$t4
syscall           #in phan tu

li $v0,4
la $a0,space
syscall          #in dau cach giua cac phan tu

addi $t3,$t3,1     
addi $t2,$t2,4     #tang chi so
blt $t3,$s0,In   #vong lap