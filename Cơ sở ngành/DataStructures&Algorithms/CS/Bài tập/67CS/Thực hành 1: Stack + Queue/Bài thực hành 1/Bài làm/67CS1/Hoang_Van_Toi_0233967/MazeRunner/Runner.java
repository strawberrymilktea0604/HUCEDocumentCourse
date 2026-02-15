package MazeRunner;

import java.util.Stack;

public class Runner {

    Maze maze = new Maze();
    Stack<Point> pointStack = new Stack<Point>();
    Point point = new Point();

    public boolean mazeRunner() {
        pointStack.push(point);
        while (!pointStack.isEmpty()) {
            int row = pointStack.peek().getX();
            int column = pointStack.peek().getY();

            if (row == maze.getNumberRow() - 1 && column == maze.getNumberColmn() - 1) {
                return true;
            }

            if (maze.isValidPoint(row, column + 1)) {
                pointStack.push(new Point(row, column + 1));
                maze.map[row][column + 1] = 0;
            }
            else if (maze.isValidPoint(row + 1, column)) {
                pointStack.push(new Point(row + 1, column));
                maze.map[row + 1][column] = 0;
            }
            else if (maze.isValidPoint(row - 1, column)) {
                pointStack.push(new Point(row - 1, column));
                maze.map[row - 1][column] = 0;
            }
            else if (maze.isValidPoint(row, column - 1)) {
                pointStack.push(new Point(row, column - 1));
                maze.map[row][column - 1] = 0;
            }
            else {
                pointStack.pop();
            }
        }
        return false;
    }
}

