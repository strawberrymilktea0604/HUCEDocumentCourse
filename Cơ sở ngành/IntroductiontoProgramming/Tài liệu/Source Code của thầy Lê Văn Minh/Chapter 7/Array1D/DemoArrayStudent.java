import java.util.Scanner;

/**
 * DemoArray
 */
public class DemoArrayStudent {

    public static void main(String[] args) {
        Student student1 = new Student(); //khởi tạo đối tượng qua hàm khởi tạo mặc định
        //System.out.printf("%4s - %5d\n", student1.getName(), student1.getAge()); //null 0

        Scanner keyboard = new Scanner(System.in);

        Student[] students = new Student[100];
        //Student student2 = students[0];
        //student2.setAge(0);
        for (int i = 0; i < students.length; i++)
        {
            System.out.println("Nhap vao thong tin sinh vien thu " + (i + 1));
            System.out.print("Nhap vao ten sinh vien: ");
            String name = keyboard.nextLine();
            System.out.print("Nhap vao tuoi: ");
            int age = keyboard.nextInt();
            students[i] = new Student(name, age);
        }

        students[0].setName("B");
        students[0].setAge(2);

        for (int i = 0; i < students.length; i++)
        {
            //nếu như không khởi tạo từng đối tượng trong mảng sẽ sinh ra ngoại lệ khi gọi các hàm get
            if (students[i] != null) {
                System.out.printf("%4s - %5d\n", students[i].getName(), students[i].getAge());
            }
        }
    }
}