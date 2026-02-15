import java.util.Scanner;
import java.io.FileNotFoundException;

public class Tester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap 'maze.txt' de thuc hien tim duong: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        if(MazeRunner.traverse(maze))
            System.out.println("Tim duong den diem cuoi thanh cong!");
        else
            System.out.println("Khong the di den diem cuoi!");

        System.out.println(maze);
        sc.close();
    }
}