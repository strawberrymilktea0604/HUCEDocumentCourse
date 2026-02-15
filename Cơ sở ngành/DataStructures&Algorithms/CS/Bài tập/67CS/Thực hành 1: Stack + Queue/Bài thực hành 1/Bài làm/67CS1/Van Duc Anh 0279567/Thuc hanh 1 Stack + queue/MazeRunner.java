import java.util.Stack;

public class MazeRunner {
    private Maze maze;

    public MazeRunner(Maze maze) {
        this.maze = maze;
    }

    public boolean traverse() {
        boolean done = false;

        Position pos = new Position();
        Stack<Position> stack = new Stack<>();

        stack.push(pos);

        while (!done && !stack.isEmpty()) {
            pos = stack.pop();
            maze.tryPosition(pos.getx(), pos.gety());
            if (pos.getx() == maze.getRows() - 1 && pos.gety() == maze.getCols() - 1)
                done = true;
            else {
                pushNewPos(pos.getx() - 1, pos.gety(), stack);
                pushNewPos(pos.getx() + 1, pos.gety(), stack);
                pushNewPos(pos.getx(), pos.gety() + 1, stack);
                pushNewPos(pos.getx(), pos.gety() - 1, stack);
            }
        }
        return done;
    }

    private void pushNewPos(int x, int y, Stack<Position> stack) {
        Position npos = new Position();
        npos.setx(x);
        npos.sety(y);

        if (maze.validPosition(x, y))
            stack.push(npos);

    }
}
