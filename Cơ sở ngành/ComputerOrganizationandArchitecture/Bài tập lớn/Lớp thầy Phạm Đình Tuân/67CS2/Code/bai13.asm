.data
    input1: .asciiz "Nhap so nguyen thu nhat: "
    input2: .asciiz "Nhap so nguyen thu hai: "
    output1: .asciiz "Tong bang: "
    output2: .asciiz "Hieu bang: "
    output3: .asciiz "Tich bang: "
    output4: .asciiz "Thuong bang: "
    output5: .asciiz ", du: "
    output6: .asciiz "Loi chia cho 0!"
    newline: .asciiz "\n"

.text
.globl main
j main
#t0 la so thu nhat, $t1 la so thu hai
Sum:
    #In ra thong bao xuat output1
    li $v0, 4
    la $a0, output1
    syscall
    
    #Tinh tong
    li $v0, 1
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $a0, 16($sp)
    syscall
    
    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
    jr $ra
    
Sub:
    #In ra thong bao xuat output1
    li $v0, 4
    la $a0, output2
    syscall
    
    #Tinh tong
    li $v0, 1
    sub $t2, $t0, $t1
    sw $t2, 12($sp)
    lw $a0, 12($sp)
    syscall
    
    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
    jr $ra
    
Mult:
    #In ra thong bao xuat output1
    li $v0, 4
    la $a0, output3
    syscall
    
    #Tinh tong
    li $v0, 1
    mul $t2, $t0, $t1
    sw $t2, 8($sp)
    lw $a0, 8($sp)
    syscall
    
    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
    jr $ra
    
Div:
    #In ra thong bao xuat output4
    li $v0, 4
    la $a0, output4
    syscall
    
    #Tinh thuong
    li $v0, 1
    div $t2, $t0, $t1
    sw $t2, 4($sp)
    lw $a0, 4($sp)
    syscall
    
    #In ra thong bao xuat output5
    li $v0, 4
    la $a0, output5
    syscall
    
    #Tinh so du
    li $v0, 1
    mfhi $t2
    sw $t2, 0($sp)
    lw $a0, 0($sp)    
    syscall
    
    #Tra bo nho cho stack
    addu $sp, $sp, 20
    
    j Exit
     
main:
    #Cap bo nho cho stack
    subu $sp, $sp, 20
    
    #In ra thong bao nhap input1
    li $v0, 4
    la $a0, input1
    syscall
    
    #Nhap so nguyen thu nhat
    li $v0, 5
    syscall
    move $t0, $v0
   
    #In ra thong bao nhap input2
    li $v0, 4
    la $a0, input2
    syscall
    
    #Nhap so nguyen thu hai
    li $v0, 5
    syscall
    move $t1, $v0 
    
    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
    jal Sum
    jal Sub 
    jal Mult
     
    #Kiem tra so thu 2 co = 0 khong?
    beq $t1, $zero, Loi
    jal Div

Loi:
    #Loi chia cho 0
    li $v0, 4
    la $a0, output6
    syscall    
     
Exit:    
    #Ket thuc chuong trinh
    li $v0, 10
    syscall
