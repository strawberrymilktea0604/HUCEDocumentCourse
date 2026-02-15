/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arraydemo;

/**
 *
 * @author Lenovo
 */
public class Scoreboard {
    private int numEntries = 0;           // number of actual entries
    private GameEntry[] board;            // array of game entries (sorted by score)

    public int getNumEntries() {
        return numEntries;
    }

    // constructor
    public Scoreboard(int capacity) {
        board = new GameEntry[capacity];
    }

    // add a new game entry
    public void add(GameEntry e) {
        int newScore = e.getScore();

        // is the new entry e really a high score?
        if (numEntries < board.length || newScore > board[numEntries - 1].getScore()) {
            if (numEntries < board.length)
                numEntries++;  // no score drops from the board
            // shift lower scores rightward to make room for the new entry
            int j = numEntries - 1;
            while (j > 0 && board[j - 1].getScore() < newScore) {
                board[j] = board[j - 1];
                j--;
            }
            board[j] = e;
        }
    }

    // remove and return the high score at index i
    public GameEntry remove(int i) throws IndexOutOfBoundsException {
        if (i < 0 || i >= numEntries)
            throw new IndexOutOfBoundsException("Invalid index: " + i);
        GameEntry temp = board[i];
        for (int j = i; j < numEntries - 1; j++)
            board[j] = board[j + 1];
        board[numEntries - 1] = null;
        numEntries--;
        return temp;
    }
}

