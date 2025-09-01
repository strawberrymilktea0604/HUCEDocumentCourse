import java.util.Scanner;

public class DemoFillArray {
    public static void main(String[] args) {
        int numOfArray;
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Nhap vao so phan tu cua mang: ");
        numOfArray = keyboard.nextInt();

        int[] numbers = new int[numOfArray]; //khởi tạo mảng

        //lặp để nhập vào giá trị từng phần tử trong mảng
        for (int i = 0; i < numbers.length; i++) {
            System.out.printf("Nhap vao gia tri thu %d: ", i + 1);
            numbers[i] = keyboard.nextInt();
        }

        System.out.println("Mang vua nhap la:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.printf("%4d", numbers[i]);
        }

        //tìm index của phần tử có giá trị bằng 5
        int indexFind = -1;
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == 5) {
                indexFind = i;
                break;
            }
        }

        //duyệt từ cuối mảng về đầu
        for (int i = numbers.length - 1; i >= 0; i--) {
            if (numbers[i] == 5) {
                indexFind = i;
                break;
            }
        }

        keyboard.close();
    }
}
