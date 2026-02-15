package MazeRunner;

public class MazeRunner {
    public static void main(String[] args) {
        Runner runner = new Runner();
        if (runner.mazeRunner()) {
            System.out.println("Đã tìm thấy đường đi.");
        }
        else {
            System.out.println("Không tìm thấy đường đi.");
        }
    }
}
