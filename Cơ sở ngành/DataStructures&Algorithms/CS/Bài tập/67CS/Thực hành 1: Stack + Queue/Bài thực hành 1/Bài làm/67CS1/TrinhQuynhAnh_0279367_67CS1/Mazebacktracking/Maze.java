import java.util.*;
import java.io.*;
public class Maze {
    private static final int TRIED = 2;
    private static final int PATH = 3;
    private int numRows, numCols;
    private int [][] grid;
    public Maze(String filename) throws FileNotFoundException {
        Scanner input = new Scanner(new File(filename));
        numRows = input.nextInt();
        numCols = input.nextInt();
        grid = new int[numRows][numCols];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                grid[i][j] = input.nextInt();
            }
        }
        input.close();
    }
    public void tryPosition(int row, int col) {
        grid[row][col] = TRIED;
    }
    public int getRows() {
        return grid.length;
    }
    public int getColumns() {
        return grid[0].length;
    }
    public void markPath(int row, int col) {
        grid[row][col] = PATH;
    }
    public boolean validPosition(int row, int col) {
        boolean result = false;
        if (row >= 0 && row < grid.length && col >= 0 && col < grid[row].length) {
            if (grid[row][col] == 1) {
                result = true;
            }
        }
        return result;
    }
    public String toString() {
        String ans = "\n";
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[row].length; col++) {
                ans += grid[row][col] + " ";
            }
            ans += "\n"; 
        }
        return ans;
    }
}