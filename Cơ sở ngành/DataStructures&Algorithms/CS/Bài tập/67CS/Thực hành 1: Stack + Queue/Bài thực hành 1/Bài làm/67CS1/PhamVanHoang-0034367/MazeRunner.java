import java.util.Stack;

public class MazeRunner {
    private static int[][] maze; // Mê cung, trong đó 0 là đường đi, 1 là tường
    private static int[][] solution; // Mảng lưu lời giải

    public static void main(String[] args) {
        // Định nghĩa mê cung (ví dụ)
        maze = new int[][] {
            {0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0}
        };

        // Khởi tạo mảng lời giải với kích thước giống mê cung
        solution = new int[maze.length][maze[0].length];

        if (solveMaze(0, 0)) {
            System.out.println("Lời giải cho mê cung:");
            printSolution();
        } else {
            System.out.println("Không tìm thấy lời giải cho mê cung.");
        }
    }

    // Phương thức sử dụng thuật toán quay lui để giải mê cung
    private static boolean solveMaze(int x, int y) {
        if (x == maze.length - 1 && y == maze[0].length - 1) {
            solution[x][y] = 1; // Đã đến đích
            return true;
        }

        if (isValidMove(x, y)) {
            solution[x][y] = 1; // Đánh dấu ô hiện tại là một phần của lời giải

            // Thử di chuyển sang phải
            if (solveMaze(x, y + 1)) {
                return true;
            }

            // Thử di chuyển xuống
            if (solveMaze(x + 1, y)) {
                return true;
            }

            // Nếu không có đường đi nào, hủy đánh dấu ô hiện tại
            solution[x][y] = 0;
        }

        return false;
    }

    // Kiểm tra xem có thể di chuyển đến ô (x, y) không
    private static boolean isValidMove(int x, int y) {
        return x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0;
    }

    // In lời giải
    private static void printSolution() {
        for (int[] row : solution) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}
