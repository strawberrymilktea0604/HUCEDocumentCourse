import java.util.Stack;

public class MazeBacktrackStack1 {

    static int[][] maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    static int rows = maze.length;
    static int cols = maze[0].length;

    static int[] start = {0, 0};
    static int[] exit = {rows - 1, cols - 1};

    static int[][] moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    static Stack<int[]> pathStack = new Stack<>();

    static boolean isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0;
    }

    static boolean findPath(int x, int y) {
        maze[x][y] = 2;

        pathStack.push(new int[]{x, y});

        if (x == exit[0] && y == exit[1]) {
            return true;
        }

        for (int[] move : moves) {
            int newX = x + move[0];
            int newY = y + move[1];

            if (isValid(newX, newY) && findPath(newX, newY)) {
                return true;
            }
        }

        pathStack.pop();
        return false;
    }

    public static void main(String[] args) {
        if (findPath(start[0], start[1])) {
            System.out.println("A path to the exit exists!");
            System.out.println("Path coordinates:");

            for (int[] coord : pathStack) {
                System.out.println("(" + coord[0] + ", " + coord[1] + ")");
            }
        } else {
            System.out.println("No path to the exit found.");
        }
    }
}
