import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DemoArrayReadFile {
    public static void main(String[] args) throws FileNotFoundException {
        final int SIZE = 100; // Assuming we know the size.
        int[] numbers = new int[SIZE];
        int i = 0;
        File file = new File("Array.txt");
        Scanner inputFile = new Scanner(file);
        while (inputFile.hasNext() && i < numbers.length)
        {
            numbers[i] = inputFile.nextInt();
            i++;
        }
        inputFile.close();

        System.out.println("Mang vua doc tu file la:");
        for (int num : numbers) {
            System.out.printf("%4d", num);
        }
    }
}
