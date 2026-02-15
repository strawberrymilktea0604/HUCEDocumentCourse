/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package arraydemo;

/**
 *
 * @author Lenovo
 */
public class ArrayDEMO {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scoreboard board = new Scoreboard(5);
        board.add(new GameEntry("Alice", 400));
        board.add(new GameEntry("Bob", 300));
        board.add(new GameEntry("Carol", 500));
        board.add(new GameEntry("Dave", 700));

        System.out.println("After adding 4 entries:");
        for (int i = board.getNumEntries() - 1; i >= 0; i--) {
            System.out.println(board.remove(i));
        }
        board.add(new GameEntry("Eve", 600));
        System.out.println("After adding Eve:");
        for (int i = board.getNumEntries() - 1; i >= 0; i--) {
            System.out.println(board.remove(i));
        }
    }
}
