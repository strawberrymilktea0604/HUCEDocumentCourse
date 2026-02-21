.data
	buffer: .space 30
	str1: .asciiz "Nhap mot chuoi: "
	str2: .asciiz "\nChieu dai cua chuoi la: "
	
.text
main:
	jal nhap		#goi ham de nhap
	jal dem			#goi ham de dem ky tu trong chuoi
	jal in			#goi ham de in
#Ket thuc chuong trinh
	li $v0, 10
	syscall
	
#tao ham de nhap
nhap:
	li $v0, 4		#goi de mo va in chuoi str1
	la $a0, str1
	syscall
	
	li $v0, 8		#nhap va doc chuoi 
	la $a0, buffer
	li $a1, 30
	syscall
	jr $ra			#tiep tuc chuong trinh chinh
	
#tao ham de dem	
dem:
    lap:
	lb $t0, ($a0)		#doc de dem so luong ky tu trong chuoi vua nhap
	beq $t0, 0, tiep		#neu $t0 = 0 thi goto "tiep"
		# neu $t0 != 0
	addi $a0, $a0, 1	#dich vi tri cua $a0 them 1 don vi de dem ky tu tiep theo
	addi $t1, $t1, 1	#so luong ky tu $t1 + 1
	j lap			#thuc hien vong lap
   tiep:	
	jr $ra			#tiep tuc chuong trinh chinh
in:
	li $v0, 4		#goi de mo va in ra chuoi str2	 
	la $a0, str2
	syscall
	
	li $v0, 1		#goi de in chieu dai cua chuoi 
	subi $a0, $t1, 1	#chieu dai chuoi = $a0 = $t1 - 1
	syscall
	jr $ra			#tiep tuc chuong trinh chinh	
