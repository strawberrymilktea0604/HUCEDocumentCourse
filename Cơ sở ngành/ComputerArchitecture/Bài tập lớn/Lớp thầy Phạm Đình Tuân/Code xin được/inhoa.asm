.data
stn: .asciiz"Hay nhap vao 1 ki tu in hoa: "
sti: "\nKi tu in thuong cua no la: "
.text
main:
	la $a0,stn
	li $v0,4
	syscall
	jal nhap
	jal in
	li $v0,10
	syscall
	
nhap:
	li $v0,12
	syscall
	addi $s0,$v0,0
	jr $ra
in:
	la $a0,sti
	li $v0,4
	syscall
	addi $a0,$s0,0x20
	li $v0,11
	syscall
	jr $ra
