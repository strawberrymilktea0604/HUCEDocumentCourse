
.data
str:     .space 128 # số lượng khoảng trống kí tự nhập vào

.text
.globl main

main:                  
  li    $v0, 8         # gọi syscall 
  la    $a0, str       # địa chỉ của chuỗi
  li    $a1, 128       # chiều dài bộ đệm
  syscall

  li    $t0, 0         # đẩy một giá trị rỗng
  subu  $sp, $sp, 4    # đẩy vào stack
  sw    $t0, ($sp)     # để báo hiệu phần phía dưới của nó
  li    $t1, 0         # chỉ sô ký tự đầu tiên của str

pushl:                 # đẩy kí tự lên stack
  lbu    $t0, str($t1) # đưa hết ký tự gộp lại thành 1 chuỗi
  beqz  $t0, stend     # nếu byte bằng 0, kết thúc chuỗi

  subu  $sp, $sp, 4    # đẩy string lên
  sw    $t0, ($sp)     # giữ char lại

  addu  $t1, $t1 1     # tăng chỉ số
  j      pushl         # vòng lặp

stend:                 # đưa ký tự từ ngăn xếp trở lại bộ đệm
  li    $t1, 0         # chỉ số byte đầu tiên của char
popl:
  lw    $t0, ($sp)     # lấy một ký tự ra khỏi ngăn xếp
  addu  $sp, $sp, 4
  beqz  $t0, done      # khi null = 0 nghĩa là stack trống không

  sb    $t0, str($t1)  # lưu trữ tại chuỗi[$t1]
  addu  $t1, $t1, 1    # tăng chỉ số
  j      popl
done:                  # in ký tự đảo ngược
  li    $v0, 4         # gọi syscall
  la    $a1, str       # địa chỉ của chuỗi
  syscall
  li    $v0, 10        # kết thúc chương trình
  syscall
