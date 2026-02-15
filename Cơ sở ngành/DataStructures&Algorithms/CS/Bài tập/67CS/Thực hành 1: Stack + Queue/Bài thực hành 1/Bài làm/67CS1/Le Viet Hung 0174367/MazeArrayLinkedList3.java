public class MazeArrayLinkedList {

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

    // Create an array to store the path coordinates
    static int[][] pathArray = new int[rows * cols][2];
    static int pathSize = 0;

    // Create a linked list to implement the stack
    static class Node {
        int x, y;
        Node next;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static Node pathStackTop = null;

    // Function to check if a cell is valid (within bounds and not a wall)
    static boolean isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0;
    }

    // Function to push a cell onto the stack (linked list)
    static void push(int x, int y) {
        Node newNode = new Node(x, y);
        newNode.next = pathStackTop;
        pathStackTop = newNode;
    }

    // Function to pop a cell from the stack (linked list)
    static void pop() {
        if (pathStackTop != null) {
            pathStackTop = pathStackTop.next;
        }
    }

    // Function to add a cell to the path array
    static void addToPathArray(int x, int y) {
        pathArray[pathSize][0] = x;
        pathArray[pathSize][1] = y;
        pathSize++;
    }

    // Function to find a path using backtracking
    static boolean findPath(int x, int y) {
        // Mark the current cell as visited
        maze[x][y] = 2; // You can use a different value for marking visited cells if needed

        // Push the current cell onto the linked list stack
        push(x, y);

        // Check if we reached the exit
        if (x == exit[0] && y == exit[1]) {
            // Add the path coordinates to the path array
            Node current = pathStackTop;
            while (current != null) {
                addToPathArray(current.x, current.y);
                current = current.next;
            }
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
        pop();
        return false;
    }

    public static void main(String[] args) {
        if (findPath(start[0], start[1])) {
            System.out.println("A path to the exit exists!");
            System.out.println("Path coordinates:");

            // Print the path coordinates from the path array
            for (int i = pathSize - 1; i >= 0; i--) {
                System.out.println("(" + pathArray[i][0] + ", " + pathArray[i][1] + ")");
            }
        } else {
            System.out.println("No path to the exit found.");
        }
    }
}
