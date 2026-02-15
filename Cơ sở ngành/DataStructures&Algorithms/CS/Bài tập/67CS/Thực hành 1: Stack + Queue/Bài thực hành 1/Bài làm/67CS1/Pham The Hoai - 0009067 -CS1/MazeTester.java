import java.io.FileNotFoundException;
import java.util.Scanner;

public class MazeTester {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the name of the file containing the maze: ");
        String filename = scan.nextLine();
        Maze labyrinth = new Maze(filename);
        System.out.println(labyrinth);
        MazeSolver solver = new MazeSolver(labyrinth);
        if (solver.traverse())
            System.out.println("The maze was successfully traversed!");
        else
            System.out.println("There is no possible path.");
        System.out.println(labyrinth);
    }
}
