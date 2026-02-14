    .data
    prompt:    .asciiz "Nhap vao so phan tu cua mang: "
    element:   .asciiz "Nhap phan tu thu  "
    space:     .asciiz " "
    max:       .asciiz "Gia tri lon nhat la: "
    min:       .asciiz "Gia tri nho nhat la: "
    newline:   .asciiz "\n"
    array:     .space 100

    .text
    .globl main

main:
    # Hiển thị thông báo "Nhập số phần tử của mảng: " và đợi người dùng nhập giá trị
    li $v0, 4
    la $a0, prompt
    syscall

    # Nhập số phần tử của mảng
    li $v0, 5
    syscall
    move $t0, $v0   # Lưu giá trị n (số phần tử) vào $t0

    # Nhập giá trị các phần tử của mảng
    li $t1, 0   # Đếm số phần tử đã nhập
    la $t2, array   # Địa chỉ bắt đầu của mảng

    LOOP_INPUT:
        addi $t1, $t1, 1

        # Hiển thị thông báo "Nhập phần tử thứ i: " và đợi người dùng nhập giá trị
        li $v0, 4
        la $a0, element
        syscall

        move $a0, $t1
        li $v0, 1
        syscall

        # Địa chỉ lưu giá trị vào thanh ghi $a0
        move $a0, $t2
        li $v0, 5
        syscall

        addi $t2, $t2, 4   # Di chuyển con trỏ đến phần tử kế tiếp trong mảng

        bne $t1, $t0, LOOP_INPUT   # Lặp lại cho đến khi đã nhập đủ số phần tử

    # Tìm giá trị lớn nhất và giá trị nhỏ nhất trong mảng
    la $t2, array   # Địa chỉ bắt đầu của mảng
    lw $t3, 0($t2)  # Lấy giá trị đầu tiên trong mảng

    li $t1, 1    # Bắt đầu từ phần tử thứ 2 trong mảng
    LOOP_COMPARE:
        addi $t1, $t1, 1

        lw $t4, 0($t2)    # Lấy giá trị mới từ mảng

        slt $t5, $t4, $t3   # So sánh giá trị mới với giá trị hiện tại nhỏ hơn
        beqz $t5, NOT_MIN   # Nếu không nhỏ hơn, nhảy qua bước kiểm tra giá trị lớn nhất

        move $t3, $t4   # Gán giá trị mới là giá trị nhỏ nhất hiện tại
        j COMPARE_NEXT

        NOT_MIN:
        slt $t5, $t3, $t4   # So sánh giá trị hiện tại với giá trị mới nhỏ hơn
        beqz $t5, COMPARE_NEXT   # Nếu không nhỏ hơn, nhảy qua bước tiếp theo

        move $t3, $t4   # Gán giá trị mới là giá trị nhỏ nhất hiện tại

        COMPARE_NEXT:
        addi $t2, $t2, 4   # Di chuyển con trỏ đến phần tử kế tiếp trong mảng

        bne $t1, $t0, LOOP_COMPARE   # Lặp lại cho đến khi đã so sánh hết các phần tử trong mảng

    # Hiển thị giá trị lớn nhất
    li $v0, 4
    la $a0, max
    syscall

    move $a0, $t3   # Di chuyển giá trị lớn nhất vào thanh ghi $a0
    li $v0, 1
    syscall

    # Hiển thị giá trị nhỏ nhất
    li $v0, 4
    la $a0, min
    syscall

    move $a0, $t4   # Di chuyển giá trị nhỏ nhất vào thanh ghi $a0
    li $v0, 1
    syscall

    # Kết thúc chương trình
    li $v0, 10
    syscall
