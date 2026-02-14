.data								
prompt_size: .asciiz "Nhap so mang: "
prompt_input: .asciiz "Nhap so tren mang: "
prompt_space: .asciiz " "
prompt_line: .asciiz "\n"
prompt_max: .asciiz "So cao nhat trong mang la: "
prompt_min: .asciiz "So thap nhat trong mang la: "
ray_size: .word 0
array: .space 100

.text								
main:								
	la $a0, prompt_size
	li $v0, 4                      #in "Nhap so mang: "
	syscall

	li $v0, 5						#nhập số lượng trong mảng, lưu vào biến $v0
	syscall

	la $t0, array					#địa chỉ mảng đó sẽ được load dữ liệu ở biến $t0
	move $t1, $v0					#sao chép biến $v0 sang $t1
	move $t2, $v0					#sao chép biến $v0 sang $t2


	input_loop:
		beq $t1, 0, exit_input_loop	#nếu số lượng mảng = 0, kết thúc vòng lặp


		la $a0, prompt_input #in "Nhap so tren mang:  "
		li $v0, 4
		syscall

		li $v0, 5        #nhập số trên  mảng, lưu vào biến $v0
		syscall

		add $t4, $t0, $t3			#thêm offset (giá trị của $t3) vào địa chỉ của mảng
		sw $v0, ($t4)				#lưu số nguyên vào đầu mảng
		addi $t3, $t3, 4			#thêm 4 bit vào phần bù

		subu $t1, $t1, 1			#size = size - 1
		j input_loop				#quay lại và bắt đầu vòng lặp
	exit_input_loop:

	#in so mang 
	addi $t1, $zero, 0				#khởi tạo $t1
	lw $a0, 0($t0)                         #tải số nguyên từ mảng
	add $t1, $zero, $a0  			#thêm phần tử đầu tiên của mảng vào $t1
	addi $t3, $zero, 0                     #khởi tạo tiếp các địa chỉ mảng
	addi $t6, $zero, 0
	output_loop:
		#nếu số lượng mảng = 0, kết thúc vòng lặp
		beq $t2, $zero, exit_output_loop

		#tìm số lớn nhất
		lw $a0, ($t4)				#tải phần tử chỉ mục vào $a0
		slt $t7, $t6, $a0			#nếu mức tối đa hiện tại nhỏ hơn phần tử: ($t7 là giá trị bool)
		beq $t7, $zero, else		#nếu giá trị bool của $t7 == 0 thì chuyển sang giá trị khác
			move $t6, $a0				#làm cho phần tử mới trở nên tối đa
		j endif						#sang hàm endif
		else:
		#tìm số nhỏ nhất
			slt $t8, $a0, $t1		#nếu phần tử nhỏ hơn mức tối thiểu hiện tại
			beq $t8, $zero, endif
				move $t1, $a0		#làm cho phần tử mới ở mức tối thiểu
		endif:


		addi $t3, $t3, 4			#tăng offset thêm 4 byte

		subu $t2, $t2, 1			#size = size - 1
		j output_loop				#quay lại và bắt đầu vòng lặp
	exit_output_loop:

	la $a0, prompt_line
	li $v0, 4
	syscall

        #in giá trị lớn nhất:
	la $a0, prompt_max
	li $v0, 4
	syscall
	la $a0, ($t6)					#nạp giá trị tại địa chỉ $t6 vào $a0
	li $v0, 1
	syscall

	la $a0, prompt_line
	li $v0, 4
	syscall


       #in giá trị nhỏ nhất:
	la $a0, prompt_min
	li $v0, 4
	syscall
	la $a0, ($t1)      #nạp giá trị tại địa chỉ $t1 vào $a0
	li $v0, 1
	syscall


	li $v0, 10                 #kết thúc chương trình
	syscall

