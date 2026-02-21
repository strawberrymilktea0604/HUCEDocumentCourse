.data
    nhapSo1: .asciiz "Nhap so thu nhat: "
    nhapSo2: .asciiz "\nNhap so thu hai: "
    tong: .asciiz "\nTong: "
    hieu: .asciiz "\nHieu: "
    tich: .asciiz "\nTich: "
    thuong: .asciiz "\nThuong: "
    
.text
    li $v0,4
    la $a0,nhapSo1
    syscall             #cum nay de in ra nhapSo1
    
    li $v0,5            #nhap so thu nhat, gia tri so thu nhat duoc luu vao $v0
    syscall            
    
    addi $s0,$v0,0      #gan gia tri vua nhap vao $s0
    
    li $v0,4
    la $a0,nhapSo2
    syscall             #cum nay de in ra nhapSo2
    
    li $v0,5            #nhap so thu hai, gia tri so thu hai duoc luu vao $v0
    syscall
    
    addi $s1,$v0,0      #gan gia tri vua nhap vao $s1
    
    li $v0,4
    la $a0,tong
    syscall             #cum nay de in ra tong
    
    li $v0,1            #print integer
    add $a0,$s0,$s1     #tinh tong 2 so vua nhap
    syscall             
    
    li $v0,4
    la $a0,hieu         
    syscall             #cum nay de in ra hieu
    
    li $v0,1            #print integer
    sub $a0,$s0,$s1     #tinh hieu 2 so vua nhap
    syscall             
    
    li $v0,4
    la $a0,tich        
    syscall             #cum nay de in ra tich 
    
    li $v0,1            #print integer
    mult  $s0,$s1       #tinh tich 2 so vua nhap
    mflo  $t1           #luu gia tri tich vao $t1
    add   $a0,$0,$t1    #gan gia tri $a0=$t1
    syscall             
    
    li $v0,4
    la $a0,thuong       
    syscall             #cum nay de in ra thuong
    
    li $v0,1            #print integer
    div  $s0,$s1        #tinh thuong 2 so vua nhap
    mflo  $t2           #luu gia tri thuong vao $t2
    add   $a0,$0,$t2    #gan gia tri $a0=$t2
    syscall
    
 
    
    
    
    
  
    
    
    
    
    
