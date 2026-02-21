import java.util.Random;
import java.util.Scanner;

public class DemoArrayNumber2 {
    public static void main(String[] args) {
        int numOfArray;
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Nhap vao so phan tu cua mang: ");
        numOfArray = keyboard.nextInt();

        int[] numbers = new int[numOfArray];

        Random random = new Random(); //lấy ngẫu nhiên
        for (int i = 0; i < numOfArray; i++) {
            numbers[i] = random.nextInt(5) + 1; //1 -> 5
        }

        int[] numbers2 = numbers;

        //tạo mảng mới
        numbers = new int[1]; //biến numbers đã trỏ sang mảng mới

        for (int i = 0; i < numbers.length; i++) {
            System.out.printf("%4d", numbers[i]);
        }
        System.out.println();

        for (int i = 0; i < numbers2.length; i++) {
            System.out.printf("%4d", numbers2[i]);
        }

        keyboard.close();
    }
}
