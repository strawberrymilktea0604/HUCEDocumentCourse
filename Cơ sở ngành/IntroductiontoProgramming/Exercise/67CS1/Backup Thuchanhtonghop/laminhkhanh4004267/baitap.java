package laminhkhanh4004267;
import java.util.Scanner;

public class baitap {

    public static void main(String [] args) {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Nhap vao so:");
        long num = keyboard.nextLong();
        String numStr = String.valueOf(num);

        //logic ở đây
        System.out.printf("So luong chu so: %d \n", numStr.length());
        int sum = 0;
        for (int i = 0; i < numStr.length(); i++) { 
            int numI = Integer.valueOf(numStr.charAt(i));
            sum += numI;
        }
             
    
        System.out.printf("Tong cac chu so la: %d \n", sum);

        int max = Integer.MIN_VALUE;
        for (int i= 0; i < numStr.length(); i++) {
            int numI = Integer.valueOf (numStr.charAt(i));
            if (numI > max) {
                max = numI;
            }
        }
        System.out.printf("Chu so lon nhat la: %d \n", max);

        int min = Integer.MAX_VALUE;
        for (int i= 0; i < numStr.length(); i++) {
            int numI = Integer.valueOf (numStr.charAt(i));
            if (numI < max) {
                min = numI;
            }
        }
        System.out.printf("Chu so nho nhat la: %d \n", min);

        int count = 0;
        for (int i= 0; i < numStr.length(); i++) {
            int numI = Integer.valueOf (numStr.charAt(i));
            if (numI == max) {
                count++;
            }
        }
        System.out.printf("So luong chu so lon nhat la: %d \n", min);


        while (num == min){
            count++;
        }
        System.out.printf("So luong chu so nho nhat la: %d \n", max);


    keyboard.close();
             


    }
    
}
