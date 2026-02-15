
import java.util.Scanner;
import java.io.FileNotFoundException;

public class MazeTester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ten file chua dia chi cua me cung: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        MazeRunner runner = new MazeRunner(maze);
        if(runner.traverse())
            System.out.println("Co the cham toi dich!");
        else
            System.out.println("Khong the cham toi dich!");

        System.out.println(maze);
        sc.close();
    }
}