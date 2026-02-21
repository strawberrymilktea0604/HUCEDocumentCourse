import java.util.Random;
import java.util.Scanner;

public class DemoArrayNumber {
    public static void main(String[] args) {
        final int SIZE = 10;

        int[] numbers = new int[SIZE];
        int[] numbers2 = { 1, 2, 3, 4, 5, 6 }; //khai báo và khởi tạo luôn giá trị cho mảng
        Random random = new Random(); //lấy ngẫu nhiên
        for (int i = 0; i < SIZE; i++) {
            //numbers[i] = i; //0 -> 99
            numbers[i] = random.nextInt(5) + 1; //1 -> 5
        }

        // numbers[0] = 10; //gán giá trị cho phần tử trong mảng theo chỉ số
        for (int i = 0; i < numbers.length; i++) {
            System.out.printf("%4d", numbers[i]);
        }

        //cách lặp thứ 2 không quan tâm đến index
        for (int num : numbers) {
            System.out.printf("%4d", num);
        }

        int sum = 0;
        for (int i = 0; i < numbers.length; i++) { //lặp theo độ dài của mảng
            sum += numbers[i];
        }
        System.out.printf("sum = %5d\n", sum);

        double avg = sum / (double)numbers.length;
        System.out.printf("avg = %5.2f\n", avg);


    }
}
