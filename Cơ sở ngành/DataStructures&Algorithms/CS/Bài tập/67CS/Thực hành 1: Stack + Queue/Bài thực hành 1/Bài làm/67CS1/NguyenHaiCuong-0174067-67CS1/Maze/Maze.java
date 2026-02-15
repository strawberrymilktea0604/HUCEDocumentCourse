package Maze;

import java.util.*;
import java.io.*;

public class Maze {
    private static final int tries = 2;
    private static final int path = 3;
    
    private int numR, numC;
    private int[][] grid;


    public Maze(String filename) throws FileNotFoundException {
        Scanner keyboard = new Scanner(new File(filename));
        numR = keyboard.nextInt();
        numC = keyboard.nextInt();

        grid = new int[numR][numC];
        for (int i = 0; i < numR; i++)
            for (int j = 0; j < numC; j++)
                grid[i][j] = keyboard.nextInt();
        keyboard.close();
    }

    public void tryPos(int row, int col) {
        grid[row][col] = tries;
    }

    public int getRows() {
        return grid.length;
    }

    public int getColumns() {
        return grid[0].length;
    }

    public void markPath(int row, int col){
        grid[row][col] = path;
    }

    public boolean validPosition(int row, int col) {
        boolean res = false;

        if (row >= 0 && row < grid.length &&
            col >= 0 && col < grid[row].length)
            if (grid[row][col] == 1)
                res = true;
        
        
        return res;
    }

    public String toString() {
        String result = "\n";

        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[row].length; col++)
                result += grid[row][col] + "";
            result += "\n"; 
        }
        return result;
    }
}
