import java.util.Scanner;

public class bai8 {
    public static void main(String[] args) {
        String input;
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Moi nhap day so: ");
        input = keyboard.nextLine();
        String so[] = input.split(",");
        int sum = 0;
        for(String strnum: so) {
            sum += Integer.parseInt(strnum);
        }
        System.out.println(sum);
    }
}
