import java.util.*;
import java.io.*;

/**
 * MazeTester determines if a maze can be traversed.
 *
 * @author Java Foundations
 * @version 4.0
 */
public class MazeTester {
    /**
     * Creates a new maze, prints its original form, attempts to
     * solve it, and prints out its final form.
     */
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
        scan.close();
    }
}