/**
 * chuoikytu
 */

import java.util.Scanner;

 public class chuoikytu {
    
    public static void main(String[] args) {
        try (Scanner keyboard = new Scanner(System.in)) {
            System.out.println("Nhap chuoi can kiem tra: ");
            String str = keyboard.nextLine();
            System.out.println("Nhap ky tu: ");
            String compile = keyboard.next();
            char ch = compile.charAt(0);
            boolean bool = false;
            for(int i = 0;i < str.length(); i++) {
                if(str.charAt(i) == ch) {
                    bool = true;
                }
            }

            
                if(bool) {
                    System.out.println("Co ky tu " + ch);
            }

            else {
                System.out.println("Khong co ky tu " + ch);
            }
            keyboard.close();
        }

    }

}
    