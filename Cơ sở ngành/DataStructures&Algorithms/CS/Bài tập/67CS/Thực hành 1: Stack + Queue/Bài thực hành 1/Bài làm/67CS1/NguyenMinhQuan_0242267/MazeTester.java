import java.util.Scanner;
import java.io.FileNotFoundException;

public class MazeTester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập tên của file chứa địa chỉ của Maze: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        MazeRunner runner = new MazeRunner(maze);
        if(runner.traverse())
            System.out.println("Có thể đi được đến điểm cuối!");
        else
            System.out.println("Không thế đi được đến điểm cuối!");

        System.out.println(maze);
        sc.close();
    }
}