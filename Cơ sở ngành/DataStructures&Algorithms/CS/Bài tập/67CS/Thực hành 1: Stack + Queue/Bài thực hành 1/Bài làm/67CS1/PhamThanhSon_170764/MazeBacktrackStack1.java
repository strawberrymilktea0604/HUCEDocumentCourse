import java.util.Stack;

public class MazeBacktrackStack {

    // Define the maze as a 2D array (0s for open path, 1s for walls)
    static int[][] maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Define the dimensions of the maze
    static int rows = maze.length;
    static int cols = maze[0].length;

    // Define the start and exit points
    static int[] start = {0, 0};
    static int[] exit = {rows - 1, cols - 1};

    // Define possible moves (up, down, left, right)
    static int[][] moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Create a stack to keep track of the path
    static Stack<int[]> pathStack = new Stack<>();

    // Function to check if a cell is valid (within bounds and not a wall)
    static boolean isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0;
    }

    // Function to find a path using backtracking
    static boolean findPath(int x, int y) {
        // Mark the current cell as visited
        maze[x][y] = 2; // You can use a different value for marking visited cells if needed

        // Push the current cell to the stack
        pathStack.push(new int[]{x, y});

        // Check if we reached the exit
        if (x == exit[0] && y == exit[1]) {
            return true;
        }

        // Try all possible moves
        for (int[] move : moves) {
            int newX = x + move[0];
            int newY = y + move[1];

            if (isValid(newX, newY) && findPath(newX, newY)) {
                return true; // Path found
            }
        }

        // If no valid move leads to the exit, backtrack
        pathStack.pop();
        return false;
    }

    public static void main(String[] args) {
        if (findPath(start[0], start[1])) {
            System.out.println("A path to the exit exists!");
            System.out.println("Path coordinates:");

            // Print the path coordinates
            for (int[] coord : pathStack) {
                System.out.println("(" + coord[0] + ", " + coord[1] + ")");
            }
        } else {
            System.out.println("No path to the exit found.");
        }
    }
}
