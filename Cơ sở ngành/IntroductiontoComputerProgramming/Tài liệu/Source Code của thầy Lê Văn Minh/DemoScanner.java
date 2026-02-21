import java.util.Random;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class DemoScanner {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        // System.out.print("Nhap vao so thap phan: ");
        // double num1;
        // num1 = keyboard.nextDouble();

        System.out.print("Nhap vao ten: ");
        String name;
        name = keyboard.nextLine();
        System.out.print("Ten cua ban la: " + name);
        // System.out.print("So vua nhap la: " + num1);

        // String name;
        // //nhập vào từ dialog
        // name = JOptionPane.showInputDialog("Nhap vao ten:");

        // //hiện ra màn hình
        // JOptionPane.showMessageDialog(null, "Ten cua ban la: " + name);

        Random random = new Random();
        // Generates random integers 0 to 50
        int x = random.nextInt(50) + 1;
    }
}
