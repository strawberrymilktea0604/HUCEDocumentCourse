import java.util.Deque;
import java.util.LinkedList;

public class MazeSolver {
    private Maze maze;

    public MazeSolver(Maze maze) {
        this.maze = maze;
    }

    public boolean traverse() {
        boolean done = false;
        int row, column;
        Position pos = new Position();
        Deque<Position> stack = new LinkedList<Position>();
        stack.push(pos);
        while (!(done) && !stack.isEmpty()) {
            pos = stack.pop();
            maze.tryPosition(pos.getX(), pos.getY()); // this cell has been tried
            if (pos.getX() == maze.getRows() - 1 && pos.getY() == maze.getColumns() - 1)
                done = true; // the maze is solved
            else {
                push_new_pos(pos.getX() - 1, pos.getY(), stack);
                push_new_pos(pos.getX() + 1, pos.getY(), stack);
                push_new_pos(pos.getX(), pos.getY() - 1, stack);
                push_new_pos(pos.getX(), pos.getY() + 1, stack);
            }
        }
        return done;
    }

    private void push_new_pos(int x, int y, Deque<Position> stack) {
        Position npos = new Position();
        npos.setX(x);
        npos.setY(y);
        if (maze.validPosition(x, y))
            stack.push(npos);
    }

}
