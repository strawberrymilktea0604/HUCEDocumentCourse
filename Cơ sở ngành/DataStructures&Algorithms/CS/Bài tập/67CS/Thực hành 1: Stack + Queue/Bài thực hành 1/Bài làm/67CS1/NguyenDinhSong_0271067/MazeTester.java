import java.util.Scanner;
import java.io.FileNotFoundException;

public class MazeTester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập tên file chứa địa chỉ của maze: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        MazeRunner runner = new MazeRunner(maze);
        if(runner.traverse())
            System.out.println("Có thể đi đến điểm cuối!");
        else
            System.out.println("Không thế đi đến điểm cuối!");

        System.out.println(maze);
        sc.close();
    }
}