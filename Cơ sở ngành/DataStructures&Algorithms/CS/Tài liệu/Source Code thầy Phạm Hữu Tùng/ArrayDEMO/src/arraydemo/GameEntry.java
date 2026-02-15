/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arraydemo;

/**
 *
 * @author Lenovo
 */
public class GameEntry {
    private String name;   // player’s name
    private int score;     // player’s score

    // constructor
    public GameEntry(String n, int s) {
        name = n;
        score = s;
    }

    // accessors
    public String getName() { return name; }
    public int getScore() { return score; }

    // string representation
    public String toString() {
        return "(" + name + ", " + score + ")";
    }
}

