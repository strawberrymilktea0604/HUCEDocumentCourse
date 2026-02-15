import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Maze {
    private static final int TRIED = 2;  

    private int nRows, nCols; 
    private int[][] grid; 

    public Maze(String fileName) throws FileNotFoundException
    {
        Scanner sc = new Scanner(new File(fileName)); 
        nRows = sc.nextInt();
        nCols = sc.nextInt(); 

        grid = new int[nRows][nCols];
        for(int i = 0; i < nRows; i++) 
        {
            for(int j = 0; j < nCols; j++) 
            {
                grid[i][j] = sc.nextInt();
            }
        }
        
        sc.close();
    }

    public void tryPosition(int row, int col) 
    {
        grid[row][col] = TRIED;
    }

    public int getRows() 
    {
        return grid.length;
    }

    public int getCols() 
    {
        return grid[0].length;
    }

    public int[][] clone() 
    {
        int[][] replica = new int[grid.length][]; 

        for(int i = 0; i < grid.length; i++) 
            replica[i] = Arrays.copyOf(grid[i], grid[i].length);
        
        return replica;
    }

    public boolean validPosition(int row, int col) 
    {
        boolean res = false;
        if(row >= 0 && col >= 0 && row < getRows() && col < getCols() && grid[row][col] == 1)
            res = true;
            
        return res; 
    }

    public String toString() 
    {
        String res = "\n"; 
        
        for(int i = 0; i < grid.length; i++) 
        {
            for(int j = 0; j < grid[0].length; j++) 
            {
                res += grid[i][j] + "  ";
            }
            res += "\n";
        }

        return res; 
    }
}