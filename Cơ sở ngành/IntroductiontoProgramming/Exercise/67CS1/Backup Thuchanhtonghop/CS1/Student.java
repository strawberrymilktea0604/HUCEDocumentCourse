package CS1;
import java.util.Scanner;

public class Student {
    String hoTen;
    String lop;
    int masosinhvien;
    float diemTrungbinh;
    double tuoi;

    //khởi tạo constructor mặc định
    public Student() {

    }
    //khởi tạo constructor có tham số
    public Student(String hoTen, String lop, int masosinhvien, float diemTrungbinh, double tuoi) {
        this.masosinhvien = masosinhvien;
        this.hoTen = hoTen;
        this.lop = lop;
        this.diemTrungbinh = diemTrungbinh;
        this.tuoi = tuoi;
    }
    //--------------begin getter and setter--------------------
    public int getmasosinhvien() {
        return masosinhvien;
    }

    public void setmasosinhvien(int masosinhvien) {
        this.masosinhvien = masosinhvien;
    }

    public String gethoTen() {
        return hoTen;
    }

    public void setHoten(String hoTen) {
        this.hoTen = hoTen;
    }

    public double gettuoi() {
        return tuoi;
    }

    public void settuoi(double tuoi) {
        this.tuoi = tuoi;
    }

    public String getlop() {
        return lop;
    }

    public void setlop(String lop) {
        this.lop = lop;
    }

    public float getdiemTrungbinh() {
        return diemTrungbinh;
    }

    public void setdiemTrungbinh(float diemTrungbinh) {
        this.diemTrungbinh = diemTrungbinh;
    }
    //--------------end getter and setter--------------------



}