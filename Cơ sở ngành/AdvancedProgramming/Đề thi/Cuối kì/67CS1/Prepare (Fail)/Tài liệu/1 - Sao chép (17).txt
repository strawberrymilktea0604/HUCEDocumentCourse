package bai1;

import java.util.Scanner;

public class TestScoreDemo {
    public static void main(String args[]) {
        Scanner keyboard  = new Scanner(System.in);
        int somonhoc;

        System.out.println("Nhap so mon hoc: ");
        somonhoc = keyboard.nextInt();
        while(somonhoc < 1) {
            System.out.println("So mon hoc khong hop le! Nhap lai!");
            System.out.println("Nhap so mon hoc: ");
            somonhoc = keyboard.nextInt();
            }
        double[] scoreArray = new double[somonhoc];
        System.out.printf("Nhap diem cac mon hoc: ", somonhoc);
        System.out.println();
        for (int i = 0; i < somonhoc; i++) {
            scoreArray[i] = keyboard.nextDouble();
            }
        try{
            TestScore t = new TestScore(scoreArray);
            System.out.println("Diem trung binh cua ban la: " + t.getAvarage());
            }
        catch(IllegalArgumentException e) {
            System.out.println(e.getMessage());
            }
    }
}
