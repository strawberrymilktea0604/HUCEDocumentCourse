.data
input_message:  .asciiz "Nhap mot chuoi: "    	
output_message: .asciiz "Chuoi da nhap: "    	

input_buffer:   .space 100

.text
    j main

Read:
    # Nhap chuoi tu ban phim
    li $v0, 8            	
    li $a1, 100           	
    syscall
    jr $ra

Print:
    # In ra chuoi da nhap
    li $v0, 4
    syscall
    jr $ra    
        
main:
    #In ra chuoi nhap
    li $v0, 4            
    la $a0, input_message  	
    syscall

    la $a0, input_buffer		#Nap dia chi can nhap chuoi vao $a0
    jal Read				#Nhap chuoi
        
    #In ra chuoi da nhap
    li $v0, 4
    la $a0, output_message 	
    syscall
    
    la $a0, input_buffer		#Nap dia chi chuoi da nhap vao $a0
    jal Print				#In chuoi
    
    #Ket thuc chuong trinh
    li $v0, 10           	
    syscall


    
    
