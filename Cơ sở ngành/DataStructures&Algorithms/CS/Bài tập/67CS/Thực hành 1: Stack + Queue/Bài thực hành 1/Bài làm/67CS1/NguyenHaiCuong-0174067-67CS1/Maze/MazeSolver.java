package Maze;

import java.util.*;

public class MazeSolver {
    private Maze maze;
    
    public MazeSolver(Maze maze) {
        this.maze = maze;
    }



    public boolean traverse() {
        boolean done = false;
        Position pos = new Position();
        Deque<Position> stk = new LinkedList<Position>();
        stk.push(pos);
        while (!(done) && !stk.isEmpty()) {
            pos = stk.pop();
            maze.tryPos(pos.getx(), pos.gety());
            if (pos.getx() == maze.getRows()-1 && pos.gety() == maze.getColumns() -1)
                done = true;
            else{
                pushNewPos(pos.getx() - 1, pos.gety(), stk);
                pushNewPos(pos.getx() + 1, pos.gety(), stk);
                pushNewPos(pos.getx(), pos.gety() - 1, stk);
                pushNewPos(pos.getx(), pos.gety() + 1, stk);
            }
        }

        return done;
    }

    private void pushNewPos(int x, int y, Deque<Position> stk){
        Position npos = new Position();
        npos.setx(x);
        npos.sety(y);
        if (maze.validPosition(x, y))
            stk.push(npos);
    }
}

