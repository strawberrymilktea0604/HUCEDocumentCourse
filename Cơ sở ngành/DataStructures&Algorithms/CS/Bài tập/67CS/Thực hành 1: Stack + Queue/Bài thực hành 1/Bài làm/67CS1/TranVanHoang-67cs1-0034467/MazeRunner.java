import java.util.Stack;

public class MazeRunner {
    private static final int ROWS = 5;
    private static final int COLS = 5;

    private static int[][] maze = {
            { 0, 1, 0, 0, 0 },
            { 0, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 1, 1, 1, 0 },
            { 0, 0, 0, 0, 0 }
    };

    private static int[][] directions = {
            { 1, 0 }, // Down
            { 0, 1 }, // Right
            { -1, 0 }, // Up
            { 0, -1 } // Left
    };

    public static boolean solveMaze() {
        Stack<int[]> stack = new Stack<>();
        int[] start = { 0, 0 };
        stack.push(start);

        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int row = current[0];
            int col = current[1];

            if (row == ROWS - 1 && col == COLS - 1) {
                // Reached the exit
                return true;
            }

            boolean found = false;
            for (int[] direction : directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                if (isValidMove(newRow, newCol)) {
                    stack.push(new int[] { newRow, newCol });
                    maze[newRow][newCol] = 2; // Mark the cell as part of the path
                    found = true;
                    break;
                }
            }

            if (!found) {
                // Backtrack if no valid move is possible
                stack.pop();
            }
        }

        return false; // No path found
    }

    private static boolean isValidMove(int row, int col) {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0;
    }

    public static void printMaze() {
        for (int[] row : maze) {
            for (int cell : row) {
                if (cell == 0) {
                    System.out.print(" "); // Empty cell
                } else if (cell == 1) {
                    System.out.print("#"); // Wall
                } else {
                    System.out.print("X"); // Path
                }
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        System.out.println("Initial Maze:");
        printMaze();

        if (solveMaze()) {
            System.out.println("Path found!");
        } else {
            System.out.println("No path found.");
        }

        System.out.println("Maze with Path:");
        printMaze();
    }
}
