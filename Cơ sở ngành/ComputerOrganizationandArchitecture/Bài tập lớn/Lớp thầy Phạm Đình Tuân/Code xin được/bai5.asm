.data
    nhapSo1: .asciiz "\nNhap so thu nhat: "
    nhapSo2: .asciiz "\nNhap so thu hai: "
    xuat: .asciiz "\nSo lon hon la: "
.text

       
    li $v0,4
    la $a0,nhapSo1
    syscall             #cum nay de in ra nhapSo1
    
    li $v0,5            #nhap so thu nhat, gia tri so thu nhat duoc luu vao $v0
    syscall 
    
    addi $s0,$v0,0      #gan gia tri so thu nhat vao $s0
    
    li $v0,4
    la $a0,nhapSo2      #cum nay de in ra nhapSo2
    syscall
    
    li $v0,5            #nhap so thu hai, gia tri so thu hai duoc luu vao $v0
    syscall
    
    addi $s1,$v0,0     #gan gia tri so thu nhat vao $s1
    
    slt $t0,$s0,$s1    # if ($s0<$s1) then $t0=1 else $t0=0
    
    bne $t0,$0,TH1 # if ($t0!=0) thuc thi tap lenh TH1
    jal TH2        # else thuc thi tap lenh TH2
    j   Exit       #thoat

     
TH1:     li $v0,1          #print integer
         add $a0,$0,$s1    #gan gia tri $a0=$s1
         syscall  
         j Exit    #thoat
TH2:      li $v0,1         #print integer
         add $a0,$0,$s0    #gan gia tri $a0=$s0
         syscall
         j Exit    #thoat
Exit:    #thoat
    
 
