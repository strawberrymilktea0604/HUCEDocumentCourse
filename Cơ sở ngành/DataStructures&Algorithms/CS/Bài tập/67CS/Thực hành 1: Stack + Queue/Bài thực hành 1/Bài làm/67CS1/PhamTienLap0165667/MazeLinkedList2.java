public class MazeLinkedList2 {

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

    static class Node {
        int x, y;
        Node next;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static Node pathStackTop = null;

    static boolean isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0;
    }

    static void push(int x, int y) {
        Node newNode = new Node(x, y);
        newNode.next = pathStackTop;
        pathStackTop = newNode;
    }

    static void pop() {
        if (pathStackTop != null) {
            pathStackTop = pathStackTop.next;
        }
    }

    static boolean findPath(int x, int y) {
        maze[x][y] = 2;

        push(x, y);

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

        pop();
        return false;
    }

    public static void main(String[] args) {
        if (findPath(start[0], start[1])) {
            System.out.println("A path to the exit exists!");
            System.out.println("Path coordinates:");

            Node current = pathStackTop;
            while (current != null) {
                System.out.println("(" + current.x + ", " + current.y + ")");
                current = current.next;
            }
        } else {
            System.out.println("No path to the exit found.");
        }
    }
}
