import java.util.*;

/**
 * MazeSolver attempts to traverse a Maze. The goal is to get from the
 * given starting position to the bottom right, following a path of 1’s.
 * Arbitrary
 * constants are used to represent locations in the maze that have been TRIED
 * and that are part of the solution PATH.
 *
 * @author Java Foundations
 * @version 4.0
 */
public class MazeSolver {
    private Maze maze;

    /**
     * Constructor for the MazeSolver class.
     */
    public MazeSolver(Maze maze) {
        this.maze = maze;
    }

    /**
     * Attempts to recursively traverse the maze. Inserts special
     * characters indicating locations that have been TRIED and that
     * eventually become part of the solution PATH.
     *
     * @param row    row index of current location
     * @param column column index of current location
     * @return true if the maze has been solved
     */
    public boolean traverse() {
        boolean done = false;
        Position pos = new Position();
        Stack<Position> stack = new Stack<>();
        stack.push(pos);
        while (!(done) && !stack.isEmpty()) {
            pos = stack.pop();
            maze.tryPosition(pos.getx(), pos.gety()); // this cell has been tried
            if (pos.getx() == maze.getRows() - 1 && pos.gety() == maze.getColumns() - 1)
                done = true; // the maze is solved
            else {
                pushNewPos(pos.getx() - 1, pos.gety(), stack);
                pushNewPos(pos.getx() + 1, pos.gety(), stack);
                pushNewPos(pos.getx(), pos.gety() - 1, stack);
                pushNewPos(pos.getx(), pos.gety() + 1, stack);
            }
        }
        return done;
    }

    /**
     * Push a new attempted move onto the stack
     * 
     * @param x     represents x coordinate
     * @param y     represents y coordinate
     * @param stack the working stack of moves within the grid
     * @return stack of moves within the grid
     */
    private void pushNewPos(int x, int y, Stack<Position> stack) {
        Position npos = new Position();
        npos.setx(x);
        npos.sety(y);
        if (maze.validPosition(x, y))
            stack.push(npos);
    }
}