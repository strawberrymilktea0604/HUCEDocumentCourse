// Java program to solve Rat in a maze
// problem with backtracking using stack
import java.util.Stack;
 
class Node
{
    private int x, y;
    private int dir;
 
    public Node(int i, int j)
    {
        this.x = i;
        this.y = j;
         
        // default value for direction set to 0 (Up)
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
 
public class RatInMaze
{
    private static final int N = 4;
    private static final int M = 5;
 
    // maze of n*m matrix
    int n = N, m = M;
 
    private static boolean[][] visited = new boolean[N][M];
 
        // Driver code
    public static void main(String[] args)
    {
        // Initially setting the visited
        // array to true (unvisited)
        setVisited(true);
 
        // Maze matrix
        int maze[][] = {{ 1, 0, 1, 1, 0 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 1, 0, 1, 1 },
                        { 1, 1, 1, 1, 1 } };
 
        if (isReachable(maze))
        {
            System.out.println("Path Found!\n");
        }
        else
            System.out.println("No Path Found!\n");
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
        // Initially starting at (0, 0).
        int i = 0, j = 0;
         
        // Food coordinates
        // Coordinates of food
        int fx, fy;
        fx = 2;
        fy = 3;
 
        Stack<Node> s = new Stack<Node>();
 
        Node temp = new Node(i, j);
 
        s.push(temp);
 
        while (!s.empty())
        {
 
            // Pop the top node and move to the
            // left, right, top, down or retract
            // back according the value of node's
            // dir variable.
            temp = s.peek();
            int d = temp.getDir();
            i = temp.getX();
            j = temp.getY();
 
            // Increment the direction and
            // push the node in the stack again.
            temp.setDir(temp.getDir() + 1);
            s.pop();
            s.push(temp);
 
            // If we reach the Food coordinates
            // return true
            if (i == fx && j == fy)
            {
                return true;
            }
 
            if (d == 0)
            {
                // Checking the Up direction.
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
                // Checking the left direction
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
                // Checking the down direction
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
                // Checking the right direction
                if (j + 1 < M && maze[i][j + 1] == 1 &&
                                        visited[i][j + 1])
                {
                    Node temp1 = new Node(i, j + 1);
                    visited[i][j + 1] = false;
                    s.push(temp1);
                }
            }
 
            // If none of the direction can take
            // the rat to the Food, retract back
            // to the path where the rat came from.
            else
            {
                visited[temp.getX()][temp.getY()] = true;
                s.pop();
            }
        }
 
        // If the stack is empty and
        // no path is found return false.
        return false;
    }
}
 
// This code is contributed by nirajtechi