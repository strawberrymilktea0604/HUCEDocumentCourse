package MazeRunner;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Maze {
    private int numberRow;
    private int numberColmn;
    int[][] map;

    public Maze() {
        try {
            Scanner scanner = new Scanner(new File("D:\\Code\\CTDL&GT\\MazeRunner\\map.txt"));
            numberRow = scanner.nextInt();
            numberColmn = scanner.nextInt();
            map = new int[numberRow][numberColmn];
            for (int i = 0; i < numberRow; i++) {
                for (int j = 0; j < numberColmn; j++) {
                    map[i][j] = scanner.nextInt(); 
                }
            }
        }
        catch (FileNotFoundException f) {
            f.printStackTrace();
        }
    }

    public boolean isValidPoint(int row, int column) {
        return (row >= 0 && row < map.length && column >= 0 && column < map[row].length && map[row][column] == 1);
    }

    public int getNumberRow() {
        return numberRow;
    }


    public int getNumberColmn() {
        return numberColmn;
    }

    
}
