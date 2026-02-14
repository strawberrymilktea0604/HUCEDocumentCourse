.data
string1: .asciiz "Nhap so thu nhat: "
string2: .asciiz "Nhap so thu hai: "
sosanh: .asciiz "\nSo lon hon la: "

.text
      #In chuỗi "Nhập số thứ nhất"
	li $v0,4
	la $a0,string1
	syscall
	
	#Nhập bàn phím số thứ nhất
	li $v0,5
	syscall
	move $t0,$v0
	
	#In chuỗi "Nhập số thứ hai"
	li $v0,4
	la $a0,string2
	syscall
	
	#Nhập bàn phím số thứ hai
	li $v0,5
	syscall
	move $t1,$v0
	
	# So sánh số lớn hơn và in kết quả ra màn hình
        bgt $t0, $t1, t0_larger
        bne $t0, $t1, t1_larger

        t0_larger:
          move $t2, $t0
          j done

        t1_larger:
          move $t2, $t1
          
          
     done:
        
        #In chuỗi "Số lớn hơn là"
	li $v0,4
	la $a0,sosanh
	syscall


	#In số lớn hơn
	li $v0, 1
        move $a0, $t2
        syscall
	
	# Kết thúc chương trình
        li $v0, 10
        syscall