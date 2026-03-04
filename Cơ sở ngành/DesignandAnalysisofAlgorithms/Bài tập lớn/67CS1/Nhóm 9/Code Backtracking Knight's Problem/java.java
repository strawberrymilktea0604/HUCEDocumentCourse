import java.util.Scanner;

public class java {
    public static void printSolution(int n, int[][] board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print((board[i][j] + 1) + " ");
            }
            System.out.println();
        }
    }

    public static boolean knightTourHelper(int n, int[][] board, int x, int y, int counter) {
        if (counter == n * n) {
            return true;
        }
        if (x < 0 || x >= n || y < 0 || y >= n || board[y][x] != -1) {
            return false;
        }
        board[y][x] = counter;
        int[] xMoves = {-2, -2, -1, -1, 1, 1, 2, 2};
        int[] yMoves = {-1, 1, -2, 2, -2, 2, -1, 1};
        for (int i = 0; i < xMoves.length; i++) {
            if (knightTourHelper(n, board, x + xMoves[i], y + yMoves[i], counter + 1)) {
                return true;
            }
        }
        board[y][x] = -1;
        return false;
    }

    public static void knightTour(int n, int x, int y) {
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = -1;
            }
        }
        if (!knightTourHelper(n, board, x, y, 0)) {
            System.out.println("Solution does not exist");
        } else {
            printSolution(n, board);
        }
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter n: ");
            int n = scanner.nextInt();
            while (n < 0 || n > 8) {
                System.out.println("Invalid n! Enter again.");
                System.out.print("Enter n: ");
                n = scanner.nextInt();
            }
            System.out.print("Enter x coordinate: ");
            int x = scanner.nextInt();
            while (x < 0 || x > n - 1) {
                System.out.println("Invalid x coordinate! Enter again.");
                System.out.print("Enter x coordinate: ");
                x = scanner.nextInt();
            }
            System.out.print("Enter y coordinate: ");
            int y = scanner.nextInt();
            while (y < 0 || y > n - 1) {
                System.out.println("Invalid y coordinate! Enter again.");
                System.out.print("Enter y coordinate: ");
                y = scanner.nextInt();
            }
            knightTour(n, x, y);
        }
    }
}

