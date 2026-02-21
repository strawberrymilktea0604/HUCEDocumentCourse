.data
	Nhap: .asciiz " Nhap mot chuoi: "  
	Inkq: .asciiz " Chieu dai cua chuoi: "
	string: .word 100  
.text   
        li $v0,4         
	la $a0,Nhap      
	syscall          #in ra Nhap
	
	li $v0,8         
	la $a0,string     
	li $a1,100        
	syscall          #Nhap chuoi
	
	
	li $t0,0
	la $t1,string
	
	Tinhchieudaichuoi:       
		lb $t2,($t1)     #luu tung ky tu cua chuoi vao $t2
		
		sge $t3,$t2,32		
		sle $t4,$t2,126	 #kiem tra ky tu co nam trong bang ma ascii in duoc hay khong	 
		
		bne $t3,$t4,In   #khi khong con ky tu thi in ra chieu dai cua chuoi
		
		addi $t0,$t0,1   
		addi $t1,$t1,1   #thoa man dieu kien kiem tra thi tang bien dem chieu dai $t0 va chi so $t1
		j    Tinhchieudaichuoi  #vong lap
	
	In:
	        li $v0,4         
	        la $a0,Inkq   
	        syscall          #in ra Inkq
	        
	        li $v0,1
	        move $a0,$t0
	        syscall         #in ra chieu dai chuoi
	
	