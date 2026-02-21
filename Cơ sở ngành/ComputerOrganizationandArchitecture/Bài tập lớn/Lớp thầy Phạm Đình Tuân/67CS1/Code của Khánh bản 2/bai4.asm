.data
string1: .asciiz "Nhap so thu nhat: "
string2: .asciiz "Nhap so thu hai: "
tong: .asciiz "Tong: "
hieu: .asciiz "\nHieu: "
tich: .asciiz "\nTich: "
thuong: .asciiz "\nThuong: "
du: .asciiz " du "

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
	
	#In chuỗi "Tổng"
	li $v0,4
	la $a0,tong
	syscall
	
	#Xử lý dữ liệu tổng	
	add $t3,$t0,$t1
	move $a0,$t3
	
	#In tổng
	li $v0,1
	syscall
	
	#In chuỗi "Hiệu"
	li $v0,4
	la $a0,hieu
	syscall
	
	#Xử lý dữ liệu hiệu	
	sub $t3,$t0,$t1
	move $a0,$t3
	
	#In hiệu
	li $v0,1
	syscall
	
	#In chuỗi "Tích"
	li $v0,4
	la $a0,tich
	syscall
	
	#Xử lý dữ liệu tích		
	mul $t3,$t0,$t1
	move $a0,$t3
	
	#In tích
	li $v0,1
	syscall
	
	#In chuỗi "Thương"
	li $v0,4
	la $a0,thuong
	syscall
	
	#Xử lý dữ liệu thương		
	div $t0,$t1
	mflo $a0
	
	#In thương	
	li $v0,1
	syscall
	
	#In chuỗi "dư"
	li $v0,4
	la $a0,du
	syscall

	#Xử lý dữ liệu dư	
	rem $t3,$t0,$t1
	move $a0,$t3
	
	#In dư
	li $v0,1
	syscall
	
	# Kết thúc chương trình
        li $v0, 10
        syscall