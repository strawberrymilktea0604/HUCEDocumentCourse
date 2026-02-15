import java.util.Scanner;
import java.io.FileNotFoundException;

public class MazeTester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ten file chua dia chi cua maze: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        MazeRunner runner = new MazeRunner(maze);
        if(runner.traverse())
            System.out.println("Da tim thay duong di");
        else
            System.out.println("Khong tim duoc duong di");

        System.out.println(maze);
        sc.close();
    }
}