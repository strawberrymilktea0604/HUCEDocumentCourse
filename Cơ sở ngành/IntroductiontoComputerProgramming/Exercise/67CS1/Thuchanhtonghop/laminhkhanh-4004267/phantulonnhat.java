/**
 * phantulonnhat
 */

import java.util.Scanner;

 public class phantulonnhat {




    public static void main(String[] args) {
        try (Scanner keyboard = new Scanner(System.in)) {
        System.out.println("Nhap so chu so vao: "); 
            int n = keyboard.nextInt();

            int max = Integer.MIN_VALUE;
            int num = 0;
            //nhập
            for (int i = 0; i < n; i++) {
        System.out.println("nhap gia tri thu: " + (i + 1));
        num = keyboard.nextInt();

        //kiểm tra số đó có nhỏ hơn min
        
        if (num > max); {
            max = num;
        }
            
        


    System.out.println("So lon nhat la:" + max);
     }

     keyboard.close();

        }
    }
 }