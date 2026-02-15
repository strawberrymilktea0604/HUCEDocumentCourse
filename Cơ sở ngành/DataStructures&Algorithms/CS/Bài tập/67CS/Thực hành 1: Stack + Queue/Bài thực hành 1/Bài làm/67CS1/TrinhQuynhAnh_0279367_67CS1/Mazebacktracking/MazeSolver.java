import java.util.*;


public class MazeSolver {
    private Maze maze;
    public MazeSolver(Maze maze) {
        this.maze = maze;
    }
    class Position {
        private int x;
        private int y;
        
        public Position() {
            this.x = x;
            this.y = y;
        }
        
        public int getX() {
            return x;
        }
        
        public int getY() {
            return y;
        }
    }
    public boolean traverse() {
        boolean done = false;
        int row, column;
        Position pos = new Position();
        Deque<Position> stack = new LinkedList<Position>();
        stack.push(pos);
        while(!(done) && !stack.isEmpty()) {
            pos = stack.pop();
            maze.tryPosition(pos.getX(), pos.getY());
            if (pos.getX() == maze.getRows() - 1 && pos.getY() == maze.getColumns() - 1) {
                done = true;
            } else {
                push_new_pos(pos.getX() - 1, pos.getY(), stack); // down
                push_new_pos(pos.getX() + 1, pos.getY(), stack); // up
                push_new_pos(pos.getX(), pos.getY() - 1, stack); // left
                push_new_pos(pos.getX(), pos.getY() + 1, stack); // right
            }
        }
        return true;
    }
    private void push_new_pos(int x, int y, Deque<Position> stack) {
        Position npos = new Position();
        npos.x = x;
        npos.y = y;
        if (maze.validPosition(x, y))
            stack.push(npos);
    }
}
