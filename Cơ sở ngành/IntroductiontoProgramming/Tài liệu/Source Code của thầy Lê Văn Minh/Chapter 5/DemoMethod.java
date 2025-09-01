import java.util.Scanner;

/**
 * DemoMethod
 */
public class DemoMethod {
    /**
     * In số ra màn hình
     * @param num số cần in
     */
    public static void displayNumber(double num) {
        System.out.printf("%.2f\n", num);
    }

    /**
     * Tổng 2 số
     * @param num1 số thứ nhất
     * @param num2 số thứ hai
     * @return trả về tổng 2 số
     */
    public static double sum(double num1, double num2) {
        displayNumber(num1);
        displayNumber(num2);
        return num1 + num2;
    }

    public static int sum(int num1, int num2) {
        return num1 + num2;
    }

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        double num1 = 1.2;
        double num2 = 3.2;
        double sum = sum(num1, num2);
        displayNumber(sum);

        keyboard.close();
    }
}