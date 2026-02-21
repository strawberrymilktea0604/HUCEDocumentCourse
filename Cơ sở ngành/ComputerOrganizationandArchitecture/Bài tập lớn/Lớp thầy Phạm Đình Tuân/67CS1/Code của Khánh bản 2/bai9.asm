.data
s1: .asciiz "Nhap mot chuoi: "
s2: .space 30
s3: .asciiz "Chieu dai chuoi: "

.text
   #nhập input chuỗi kĩ tự vào
   la $a0, s1
   li $v0, 4  
   syscall
   
   # Nhập một chuỗi từ bàn phím
   li $v0, 8
   la $a0, s2
   la $a1, 30
   syscall
   
   #in chuỗi "Chiều dài chuỗi"
   la $a0, s3
   li $v0, 4  
   syscall
   
   
   #Khởi tạo biến đếm chiều dài chuỗi s2
   la $a1, s2
   
   #Khởi tạo biến đếm
   li $t1, -2 #(nếu ta tính cả lần enter nữa)
   
   #bắt đầu tạo vòng lặp
   loop:
	lb $t0, ($a1) # Đọc ký tự tại địa chỉ $a1 và lưu vào $t0
	addi $a1, $a1, 1 # Di chuyển con trỏ đến ký tự tiếp theo
	addi $t1, $t1, 1 # Tăng biến đếm chiều dài lên 1
	bne $t0, $zero, loop # Lặp lại vòng lặp
   
   #In số chiều dài chuỗi
   move $a0, $t1
   li $v0, 1
   syscall
   
   #Kết thúc chương trình
   li $v0, 10
   syscall  