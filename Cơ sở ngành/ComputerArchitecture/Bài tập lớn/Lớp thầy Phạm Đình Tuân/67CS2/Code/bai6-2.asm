.data
    prompt:  .asciiz "Nhap mot ki tu: "
    result:  .asciiz "Ky tu vua nhap la:"
    newline: .asciiz "\n"
    checkNum: .asciiz"So"
    checkUpper: .asciiz"Chu hoa"
    checklowercase :.asciiz"Chu thuong"
    
.text
    main:
        # Hiển thị thông điệp nhắc người dùng nhập ký tự
        li $v0, 4
        la $a0, prompt
        syscall
        
        # Nhận một ký tự từ người dùng
        li $v0, 12
        syscall
        
        # Lưu giá trị ký tự nhập vào $t0
        move $t0, $v0
        
        # Kiểm tra xem ký tự nhập thuộc [0-9]
        li $t1, 48   # Giá trị ASCII của '0'
        li $t2, 57   # Giá trị ASCII của '9'
        bgt $t0, $t2, check_lowercase   # Nếu ký tự là số, kiểm tra ký tự chữ thứ 2
        
        # In ký tự và loại của ký tự
        li $v0, 4
        la $a0, result
        syscall
        
        li $v0, 11
        move $a0, $t0   # Đưa giá trị ký tự vào $a0 để in
        syscall
        
        li $v0, 4
        la $a0, newline
        syscall
        
        li $v0, 4
        la $a0, checkNum
        syscall
        
        j exit
        
    check_lowercase:
        # Kiểm tra xem ký tự nhập thuộc [a-z]
        li $t1, 97   # Giá trị ASCII của 'a'
        li $t2, 122  # Giá trị ASCII của 'z'
        bgt $t0, $t2, check_uppercase  # Nếu không phải chữ thường, kiểm tra ký tự chữ hoa
        
        # In ký tự và loại của ký tự
        li $v0, 4
        la $a0, result
        syscall
        
        li $v0, 11
        move $a0, $t0   # Đưa giá trị ký tự vào $a0 để in
        syscall
        
        li $v0, 4
        la $a0, newline
        syscall
        
        li $v0, 4
        la $a0, checklowercase
        syscall
        
        j exit
        
    check_uppercase:
        # Kiểm tra xem ký tự nhập thuộc [A-Z]
        li $t1, 65   # Giá trị ASCII của 'A'
        li $t2, 90   # Giá trị ASCII của 'Z'
        bgt $t0, $t2, exit  # Nếu ký tự không thuộc [A-Z] thì thoát chương trình
        
        # In ký tự và loại của ký tự
        li $v0, 4
        la $a0, result
        syscall
        
        li $v0, 11
        move $a0, $t0   # Đưa giá trị ký tự vào $a0 để in
        syscall
        
        li $v0, 4
        la $a0, newline
        syscall
        
        li $v0, 4
        la $a0, checkUpper
        syscall
        
    exit:
        # Kết thúc chương trình
        li $v0, 10
        syscall
