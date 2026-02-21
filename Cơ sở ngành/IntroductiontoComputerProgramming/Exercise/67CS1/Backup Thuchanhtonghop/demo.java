public class demo {
    public static void main(String[] args) {
    int funny = 7, serious = 15;
    funny = serious % 2;
    if (funny != 1) {
    funny = 0;
    serious = 0;
    } else if (funny == 2) {
    funny = 10;
    serious = 10;
    } else {
    funny = 1;
    serious = 1;
    }
    System.out.println(funny + " " + serious);
    }
   }