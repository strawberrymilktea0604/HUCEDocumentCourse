import java.util.Scanner;

public class bai3  {
    public static void main(String[] args) {
        String input;
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Moi nhap: ");
        input = keyboard.nextLine();
        String chu[] = input.split("\\.");
        for (int i = 0; i < chu.length; i++) {

            System.out.print(Character.toUpperCase(chu[i].trim().
                    charAt(0)) + chu[i].trim().substring(1) + ". ");
        }
    }
}