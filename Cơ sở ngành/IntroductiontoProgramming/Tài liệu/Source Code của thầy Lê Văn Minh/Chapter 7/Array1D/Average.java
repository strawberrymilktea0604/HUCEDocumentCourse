import java.util.Arrays;
import java.util.Scanner;

public class Average {
    private int[] data;
    private double mean;

    public void calculateMean() {
        double sum = 0;
        for (int i = 0; i < data.length; i++) {
            sum += data[i];
        }
        mean = sum / data.length;
    }

    public String toString() {
        return "Average [data=" + Arrays.toString(data) + ", mean=" + mean + "]";
    }

    public Average() {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Nhap vao so luong phan tu: ");
        int numberOfData = keyboard.nextInt();
        data = new int[numberOfData];

        for (int i = 0; i < data.length; i++) {
            System.out.printf("Nhap vao gia tri thu %d: ", i + 1);
            data[i] = keyboard.nextInt();
        }
        keyboard.close();
    }
}
