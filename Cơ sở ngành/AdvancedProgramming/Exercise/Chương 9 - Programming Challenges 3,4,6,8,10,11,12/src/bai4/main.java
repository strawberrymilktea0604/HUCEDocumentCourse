package bai4;

import java.util.Scanner;


public class main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap chuoi sau: ");
        String input = sc.nextLine();

        char choice = ' ';


        do {

            bai4 words = new bai4(input);

            System.out.println("Chao mung ban den voi chuong trinh.");
            System.out.println("Hay lua chon: ");
            System.out.println();
            System.out.print("a. Dem so nguyen am.\n"
                    + "b. Dem so phu am.\n"
                    + "c. Dem ca so phu am voi nguyen am.\n"
                    + "d. Nhap chuoi khac. \n"
                    + "e. Ket thuc chuong trinh. \n");

            System.out.println("Lua chon cua ban: \n");
            choice = sc.nextLine().charAt(0);





            switch (choice) {
                case 'a':
                case 'A':
                    System.out.println("So nguyen am: " + words.getVowels());
                    break;
                case 'b':
                case 'B':
                    System.out.println("So phu am: " + words.getConsonants());
                    break;
                case 'c':
                case 'C':
                    System.out.println("So nguyen am va phu am: " + words.getConsonants()
                            + words.getVowels());
                    break;
                case 'd':
                case 'D':
                    System.out.println("Nhap chuoi sau: ");
                    input = sc.nextLine();
                    break;
                case 'e':
                case 'E':
                    System.out.println("Cam on va hen gap lai!");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Lua chon cua ban khong hop le!");
            }

        } while (choice != 'e');
    }
}