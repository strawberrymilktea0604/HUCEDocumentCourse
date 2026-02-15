
import java.util.Stack;

public class MazeRunner {

    private static final int N = 5; // Kích thước của mê cung

    // Hàm kiểm tra xem có thể di chuyển từ mê cung[x][y] hay không
    private static boolean isSafe(int[][] maze, int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
    }

    // Hàm in ra một lời giải cho mê cung
    private static void printSolution(int[][] solution) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(solution[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Hàm sử dụng thuật toán quay lui để tìm lời giải cho mê cung
    public static boolean solveMaze(int[][] maze) {
        int[][] solution = new int[N][N]; // Mảng lưu lời giải

        // Khởi tạo lời giải với các ô đều là 0
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                solution[i][j] = 0;
            }
        }

        // Khởi tạo ngăn xếp để lưu các bước di chuyển trong quá trình tìm lời giải
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{0, 0}); // Đặt điểm bắt đầu vào ngăn xếp

        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int x = current[0];
            int y = current[1];

            // Đánh dấu ô hiện tại là đã đi qua trong lời giải
            solution[x][y] = 1;

            // Kiểm tra xem đã đến ô đích hay chưa
            if (x == N - 1 && y == N - 1) {
                printSolution(solution);
                return true;
            }

            // Di chuyển sang ô bên phải (x, y+1)
            if (isSafe(maze, x, y + 1)) {
                stack.push(new int[]{x, y + 1});
            }

            // Di chuyển sang ô bên dưới (x+1, y)
            if (isSafe(maze, x + 1, y)) {
                stack.push(new int[]{x + 1, y});
            }
        }

        // Nếu không tìm được lời giải
        System.out.println("Khong ton tai loi giai");
        return false;
    }

    public static void main(String[] args) {
        int[][] maze = {
                {1, 0, 0, 0, 1},
                {1, 1, 0, 1, 1},
                {0, 1, 0, 0, 1},
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1}
        };

        solveMaze(maze);
    }
}

