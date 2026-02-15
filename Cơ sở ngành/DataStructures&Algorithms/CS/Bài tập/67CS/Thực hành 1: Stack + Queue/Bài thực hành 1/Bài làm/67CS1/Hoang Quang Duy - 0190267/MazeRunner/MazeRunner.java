import java.util.Stack;

public class MazeRunner
{

    public static boolean traverse(Maze maze) 
    {
        boolean done = false; 

        Position pos = new Position();
        Stack<Position> stack = new Stack<>(); 

        stack.push(pos);

        while(!done && !stack.isEmpty()) 
        {
            pos = stack.pop(); 
            maze.tryPosition(pos.getx(), pos.gety());
            if(pos.getx() == maze.getRows() - 1 && pos.gety() == maze.getCols() - 1) 
                done = true; 
            else 
            {
                pushNewPos(pos.getx() - 1, pos.gety(), stack, maze); 
                pushNewPos(pos.getx() + 1, pos.gety(), stack, maze); 
                pushNewPos(pos.getx(), pos.gety() + 1, stack, maze); 
                pushNewPos(pos.getx(), pos.gety() - 1, stack, maze);  
            }
        }
        return done; 
    }

    private static void pushNewPos(int x, int y, Stack<Position> stack, Maze maze) 
    {
        Position new_pos = new Position(x, y);

        if(maze.validPosition(x, y))
            stack.push(new_pos);

    }

}
