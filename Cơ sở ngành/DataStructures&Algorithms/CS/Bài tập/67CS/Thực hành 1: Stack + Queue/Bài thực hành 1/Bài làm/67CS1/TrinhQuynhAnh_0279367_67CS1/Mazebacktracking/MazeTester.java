import java.util.*;
import java.io.*;
public class MazeTester {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name of the file containing the maze: ");
        String filename = sc.nextLine();
        Maze labyrinth = new Maze(filename);
        System.out.println(labyrinth);
        MazeSolver solver = new MazeSolver(labyrinth);
        if (solver.traverse()) {
            System.out.println("The maze was successfully traversed!");
        } else {
            System.out.println("There is no possible path.");
        }
        sc.close();
    }
}