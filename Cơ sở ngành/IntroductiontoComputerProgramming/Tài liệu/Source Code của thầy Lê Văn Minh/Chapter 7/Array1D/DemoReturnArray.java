public class DemoReturnArray {
    public static double[] getArray()
    {
        double[] array = { 1.2, 2.3, 4.5, 6.7, 8.9 };
        return array;
    }

    /**
     * Tính tổng mảng
     * @param array mảng đầu vào
     * @return tổng
     */
    public static double sumArray(double[] array) {
        double sum = 0;
        for (double num : array) {
            sum += num;
        }
        return sum;
    }

    public static void main(String[] args) {
        double[] array = getArray();
        for (double num : array) {
            System.out.printf("%5.2f", num);
        }
        System.out.println();
        System.out.printf("Tong cua mang la: %7.4f", sumArray(array));

        
    }
}
