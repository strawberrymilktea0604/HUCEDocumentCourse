package CS1;
import java.util.Scanner;

public class Class {
    //input thông tin sinh viên
    void inputInfo() {
        Scanner input = new Scanner(System.in);
        Student keyboard = new Student();
        System.out.println("Nhap ho ten sinh vien: ");
        keyboard.hoTen = input.nextLine();
        System.out.println("Nhap tuoi sinh vien: ");
        keyboard.tuoi = input.nextDouble();
        System.out.println("Nhap ten lop sinh vien: ");
        keyboard.lop = input.nextLine();
        System.out.println("Nhap ma so sinh vien: ");
        keyboard.masosinhvien = input.nextInt();
        System.out.println("Nhap diem trung binh sinh vien: ");
        keyboard.diemTrungbinh = input.nextFloat();
    }

        //để hiện thị đối tượng
    void showInfo() {
        Object keyboard;
        System.out.println("Ho va ten: " + keyboard.hoTen());
        System.out.println("Lop: "+ lop);
        System.out.println("Tuoi: " + tuoi);
        System.out.println("Ma so sinh vien: " + masosinhvien);
        System.out.println("Diem trung binh: " + );
    }
        
        

    
}
