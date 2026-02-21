.data
input_message:  .asciiz "Nhap mot chuoi: "    	
output_message: .asciiz "Chuoi da nhap: "    	

input_string:   .space 100   	
output_string:  .space 100   	

.text
main:
    #In ra chuoi nhap
    li $v0, 4            	#Su dung dich vu in chuoi
    la $a0, input_message  	#Dua dia chi cua chuoi nhap vao $a0
    syscall 

    #Nhap chuoi tu ban phim
    li $v0, 8            	#Doc chuoi tu ban phim
    la $a0, input_string 	#Dia chi cua chuoi
    li $a1, 100          	#Do dai chuoi
    syscall

    #Luu dia chi input va output
    la $t0, input_string   
    la $t1, output_string  

store_loop:
    lb $t2, 0($t0)        	#Luu ki tu vao $t2
    beq $t2, 10, reverse_loop  	#Neu gap ki tu "\n" thi nhay den reverse_loop
    subi $sp, $sp, 1      	#Giam $sp di 1 byte
    sb $t2, ($sp)         	#Luu ki tu vao stack
    addi $t0, $t0, 1      	#Di chuyen den ki tu tiep theo
    j store_loop

reverse_loop:
    lb $t2, ($sp)         	#Lay ki tu tu stack
    beqz $t2, print_reverse_str #Neu gap ki tu "\0" thi nhay den print_reverse_str
    sb $t2, ($t1)         	#Luu ki tu vao chuoi output
    addi $sp, $sp, 1      	#Tang $sp them 1 byte
    addi $t1, $t1, 1      	#Di chuyen den ki tu tiep theo
    j reverse_loop

print_reverse_str:
    #In ra chuoi xuat
    li $v0, 4            	
    la $a0, output_message  	
    syscall
    
    #In chuoi da dao nguoc
    li $v0, 4           
    la $a0, output_string 
    syscall

    #Ket thuc chuong trinh
    li $v0, 10
    syscall

    
