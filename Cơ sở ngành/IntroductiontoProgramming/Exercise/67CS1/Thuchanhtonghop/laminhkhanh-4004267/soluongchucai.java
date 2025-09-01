/**
 * chuoikytu
 */

import java.util.Scanner;

 public class soluongchucai {
    
    public static void main(String[] args) {
        try (Scanner keyboard = new Scanner(System.in)) {
            System.out.println("Nhap chuoi can kiem tra: ");
            String chuoi = keyboard.nextLine();
            char kyTu = 'f';
            int count = 0;

            // duyệt từ đầu đến cuối chuỗi
        for (int i = 0; i < chuoi.length(); i++) {
        // Nếu ký tự tại vị trí thứ i bằng 'f' thì tăng count lên 1
        if (chuoi.charAt(i) == kyTu) {
            count++;
        }
    }
         
    System.out.println("So lan xuat hien o ky tu " + kyTu +
        " trong chuoi " + chuoi + " = " + count);
}
    }
}
