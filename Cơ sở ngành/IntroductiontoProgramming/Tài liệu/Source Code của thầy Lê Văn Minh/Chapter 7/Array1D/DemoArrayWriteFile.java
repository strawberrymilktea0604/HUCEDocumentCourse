import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class DemoArrayWriteFile {
    public static void main(String[] args) throws FileNotFoundException {
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

        //in mảng ra file có thể dùng trực tiếp class PrintWriter
        PrintWriter outputFile = new PrintWriter("Array.txt");
        for (int i = 0; i < numbers.length; i++) {
            outputFile.println(numbers[i]);
        }
        outputFile.close();

        keyboard.close();
    }
}
