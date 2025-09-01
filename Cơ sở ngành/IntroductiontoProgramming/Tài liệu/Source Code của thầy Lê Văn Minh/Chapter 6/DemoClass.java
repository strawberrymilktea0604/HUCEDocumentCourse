import java.util.Scanner;

public class DemoClass {

    public static void showInfo(Student student) {
        System.out.printf("Thong tin sinh vien vua nhap: %s\n", student.getInfo());
    }

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        Rectangle rec1 = new Rectangle();

        for (int i = 0; i < 2; i++) {
            System.out.printf("Nhap vao sinh vien thu %d \n", (i + 1));
            System.out.print("Nhap vao ten sinh vien: ");
            Student sv = new Student();
            sv.setName(keyboard.nextLine());
            System.out.print("Nhap vao tuoi sinh vien: ");
            sv.setAge(keyboard.nextInt());
            keyboard.nextLine();
            showInfo(sv);
        }

        keyboard.close();
    }
}