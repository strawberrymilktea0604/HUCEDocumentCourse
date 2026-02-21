.data
	str: .asciiz " Nhap mot chuoi: "  
	str1: .asciiz " Chuoi da nhap: "
	chuoi: .asciiz  #khai bao chuoi can nhap
.text   
        li $v0,4         #in ra chuoi str
	la $a0,str       #dua dia chi cua chuoi vao $a0
	syscall          #lenh thuc thi
	
	li $v0,8         #nhap chuoi
	la $a0,chuoi     #dia chi cua chuoi nhap vao
	li $a1,50        #size cua chuoi nhap vao
	syscall          #lenh thuc thi
	
	li $v0,4         #in ra chuoi str1
	la $a0,str1      #dua dia chi cua chuoi vao $a0
	syscall          #lenh thuc thi
	
	li $v0,4        #in ra chuoi vua nhap
	la $a0,chuoi    #dua dia chi cua chuoi vao $a0
	syscall         #lenh thuc thi
	
