import java.util.Scanner;
import java.io.FileNotFoundException;

public class MazeTester {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ten file dia chi maze: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        MazeRunner runner = new MazeRunner(maze);
        if (runner.traverse())
            System.out.println("Co the di den diem cuoi");
        else
            System.out.println("Khong the di den diem cuoi");

        System.out.println(maze);
        sc.close();
    }
}