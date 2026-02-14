.data
    input:        .asciiz "Nhap n: "
    output1:      .asciiz "Nhap phan tu: "
    output2:      .asciiz "Mang vua nhap: "
    output3:      .asciiz " "
    output4:      .asciiz "Gia tri nho nhat: "
    output5:      .asciiz "Gia tri lon nhat: "
    newline: 	  .asciiz "\n"
    
    input_buffer: .space 100

.text
.globl main

main:
    #In ra thong bao nhap n
    li $v0, 4
    la $a0, input
    syscall
    
    #Nhap n
    li $v0, 5	 
    syscall
    move $s0, $v0
    
    mul $t1, $s0, 4		#Luong words dung cho stack   		
    sub $sp, $sp, $t1		#Cap cho stack n words
    
    #Tao cac gia tri lien quan
    addi $t0, $s0, -1 		#$t0 = i = n - 1
    
Loop_Nhap:   
    #Nhap phan tu thu i
    li $v0, 4
    la $a0, output1 		#In ra dong thong bao nhap phan tu
    syscall
    
    li $v0, 5			#Nhap phan tu thu i
    syscall
    
    sll $t2, $t0, 2
    add $t2, $sp, $t2
    sw $v0, 0($t2)		#Luu phan tu thu i vao stack
    
    addi $t0, $t0, -1		#i++
    
    bge $t0, $0, Loop_Nhap 	#Neu i < n thi lap tiep
    
    #In ra thong bao xuat mang
    li $v0, 4
    la $a0, output2
    syscall    
    
    addi $t0, $s0, -1 		#Dat lai $t0 = i = n - 1
    
Loop_Xuat:
    sll $t2, $t0, 2
    add $t2, $sp, $t2
    lw $a0, 0($t2) 		#Luu gia tri thu i vao $a0
    
    #In ra phan tu thu i
    li $v0, 1
    syscall
    
    #In ra khoang trong
    li $v0, 4
    la $a0, output3		#In ra khoang trong giua cac phan tu
    syscall
    
    addi $t0, $t0, -1		#i--
    
    bge $t0, $0, Loop_Xuat 	#Neu i < 5 thi lap tiep
    
    #Tim Min
    and $t0, $t0, $0 		#Dat lai $t0 = 0
    add $t2, $sp, $t0
    lw $t4, 0($t2)		#Dat gia tri dau tien cua mang la Min 
    
Loop_Min:
    sll $t2, $t0, 2
    add $t2, $sp, $t2
    lw $t3, 0($t2) 		#Luu gia tri thu i vao $t1
    
    bge $t3, $t4, Continue_Min	#Neu gia tri dang duyet be hon Min
    la $t4, ($t3)		#thi dat gia tri hien tai la Min
    
Continue_Min:    
    addi $t0, $t0, 1		#i++
    bne $t0, $s0, Loop_Min 	#Neu i < 5 thi lap tiep
    
    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
    #In ra Min
    li $v0, 4
    la $a0, output4
    syscall
    
    li $v0, 1
    move $a0, $t4		#In ra Min trong $t4
    syscall
    
    #Tim Max
    and $t0, $t0, $0 		#Dat lai $t0 = 0
    add $t2, $sp, $t0
    lw $t5, 0($t2)		#Dat gia tri dau tien cua mang la Max 
    
Loop_Max:
    sll $t2, $t0, 2
    add $t2, $sp, $t2
    lw $t3, 0($t2) 		#Luu gia tri thu i vao $t1
    
    ble $t3, $t5, Continue_Max	#Neu gia tri dang duyet lon hon Max
    la $t5, ($t3)		#thi dat gia tri hien tai la Max
    
Continue_Max:    
    addi $t0, $t0, 1		#i++
    bne $t0, $s0, Loop_Max 	#Neu i < 5 thi lap tiep 
    
    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
    #In ra Max
    li $v0, 4
    la $a0, output5
    syscall
    
    li $v0, 1
    move $a0, $t5		#In ra Min trong $t5
    syscall
    
    #Tra lai bo nho stack
    add $sp, $sp, $t1
    
    #Ket thuc chuong trinh
    li $v0, 10          
    syscall
