public class DiceRoller {
    public static void main(String[] args)
    {
        final int ROLLS = 500;
        int count = 0;
        Die die1 = new Die();
        Die die2 = new Die();
        for (int i = 0; i < ROLLS; i++)
        {
            int faceValue1 = die1.roll();
            int faceValue2 = die2.roll();
            if(faceValue1 == faceValue2)
                count++;
        }

        System.out.println("Count: "+count);
    }
}
