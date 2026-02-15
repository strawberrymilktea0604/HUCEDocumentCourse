
import java.util.Scanner;
import java.io.FileNotFoundException;

public class MazeTester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the file which contains a maze: ");
        String filename = sc.nextLine();

        Maze maze = new Maze(filename);
        System.out.println(maze);

        MazeRunner runner = new MazeRunner(maze);
        if(runner.traverse())
            System.out.println("Can reach to the end!");
        else
            System.out.println("Can't reach to the end!");

        System.out.println(maze);
        sc.close();
    }
}