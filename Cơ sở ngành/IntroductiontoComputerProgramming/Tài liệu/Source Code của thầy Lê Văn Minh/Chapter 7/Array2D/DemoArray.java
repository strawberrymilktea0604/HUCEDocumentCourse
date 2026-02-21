/**
 * DemoArray
 */
public class DemoArray {

    public static int[] findMax(int[][] numbers) {
        int[] maxInRow = new int[numbers.length];

        for (int row = 0; row < numbers.length; row++) {
            int max = Integer.MIN_VALUE;
            for (int col = 0; col < numbers[row].length; col++) {
                if (numbers[row][col] > max) {
                    max = numbers[row][col];
                }
            }
            maxInRow[row] = max;
        }
        return maxInRow;
    }


    public static void main(String[] args) {
        int[][] numbers = {{ 1, 2, 3, 4 },
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}};

        int[] maxInRow = findMax(numbers);

        for (int i = 0; i < maxInRow.length; i++) {
            System.out.printf("%4d", maxInRow[i]);
        }
    }
}