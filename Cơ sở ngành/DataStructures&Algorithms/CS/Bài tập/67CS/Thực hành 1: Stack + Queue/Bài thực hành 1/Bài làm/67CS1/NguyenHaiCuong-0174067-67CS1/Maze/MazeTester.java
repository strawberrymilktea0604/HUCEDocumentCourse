package Maze;

import java.util.*;
import java.io.*;

public class MazeTester {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner key = new Scanner(System.in);
        System.out.print("Enter the name of the file containing the maze: ");
        String filename = key.nextLine();

        Maze laby = new Maze(filename);
        System.out.println(laby);

        MazeSolver solve = new MazeSolver(laby);

        if (solve.traverse())
            System.out.println("The maze was successfully traversed!");
        else
            System.out.println("No possible path!");

        System.out.println(laby);
        key.close();
    } 
}
