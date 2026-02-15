// Chương trình Java để dò tìm đường đi ma trận
// sử dụng thuật toán quay lui với ngăn xếp
import java.util.Stack;
 
class Node
{
    private int x, y;
    private int dir;
 
    public Node(int i, int j)
    {
        this.x = i;
        this.y = j;
         
        // giá trị mặc định cho hướng đi đặt về 0 (hướng lên)
        this.dir = 0;
    }
 
    public int getX()
    {
        return x;
    }
 
    public void setX(int x)
    {
        this.x = x;
    }
 
    public int getY()
    {
        return y;
    }
 
    public void setY(int y)
    {
        this.y = y;
    }
 
    public int getDir()
    {
        return dir;
    }
 
    public void setDir(int dir)
    {
        this.dir = dir;
    }
}
 
public class bai1
{
    private static final int N = 4;
    private static final int M = 5;
 
    // Mê cung ma trận N*M
    int n = N, m = M;
 
    private static boolean[][] visited = new boolean[N][M];
 
        // Chương trình chính
    public static void main(String[] args)
    {
        // Ban đầu ta sẽ thiết lập truy cập
        // Mảng hướng đến vị trí đúng (nhưng chưa truy cập)
        setVisited(true);
 
        // Ma trận mê cung
        int maze[][] = {{ 1, 0, 1, 1, 0 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 1, 0, 1, 1 },
                        { 1, 1, 1, 1, 1 } };
 
        if (isReachable(maze))
        {
            System.out.println("Ta da tim thay duong di me cung!\n");
        }
        else
            System.out.println("Mo di cung, ma tran khong de an dau!\n");
    }
 
    private static void setVisited(boolean b)
    {
        for (int i = 0; i < visited.length; i++)
        {
            for (int j = 0; j < visited[i].length; j++)
            {
                visited[i][j] = b;
            }
        }
 
    }
 
    private static boolean isReachable(int maze[][])
    {
        // Ban đầu vị trí sẽ bắt đầu từ tọa độ (0, 0)
        int i = 0, j = 0;
         
        // Tọa độ chìa khóa 
        int fx, fy;
        fx = 2;
        fy = 3;
 
        Stack<Node> s = new Stack<Node>();
 
        Node temp = new Node(i, j);
 
        s.push(temp);
 
        while (!s.empty())
        {
 
            // Xóa vị trí trên cùng và di chuyển sang trái, phải, trên, xuống hoặc rút lại theo giá trị của biến dir của nvị trí đó.
            temp = s.peek();
            int d = temp.getDir();
            i = temp.getX();
            j = temp.getY();
 
            // Mở rộng hướng đi và đẩy vị trí trong ngăn xếp một lần nữa.
            temp.setDir(temp.getDir() + 1);
            s.pop();
            s.push(temp);
 
            // Nếu ta thấy đích đến thì trả về giá trị đúng
            if (i == fx && j == fy)
            {
                return true;
            }
 
            if (d == 0)
            {
                // Quan sát hướng lên trên.
                if (i - 1 >= 0 && maze[i - 1][j] == 1 &&
                                        visited[i - 1][j])
                {
                    Node temp1 = new Node(i - 1, j);
                    visited[i - 1][j] = false;
                    s.push(temp1);
                }
            }
            else if (d == 1)
            {
                // Quan sát hướng bên trái.
                if (j - 1 >= 0 && maze[i][j - 1] == 1 &&
                                        visited[i][j - 1])
                {
                    Node temp1 = new Node(i, j - 1);
                    visited[i][j - 1] = false;
                    s.push(temp1);
                }
            }
            else if (d == 2)
            {
                // Quan sát hướng xuống dưới.
                if (i + 1 < N && maze[i + 1][j] == 1 &&
                                        visited[i + 1][j])
                {
                    Node temp1 = new Node(i + 1, j);
                    visited[i + 1][j] = false;
                    s.push(temp1);
                }
            }
            else if (d == 3)
            {
                // Quan sát hướng bên trái.
                if (j + 1 < M && maze[i][j + 1] == 1 &&
                                        visited[i][j + 1])
                {
                    Node temp1 = new Node(i, j + 1);
                    visited[i][j + 1] = false;
                    s.push(temp1);
                }
            }
 
            // Nếu không có hướng nào có thể đưa chúng ta tìm ra đáp án, hãy quay lại đúng vị trí ban đầu!
            else
            {
                visited[temp.getX()][temp.getY()] = true;
                s.pop();
            }
        }
 
        // Nếu ngăn xếp trống rỗng và không có đường đi nào thì trả về giá trị sai
        return false;
    }
}
 