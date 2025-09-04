import java.util.Scanner;

public class TestScore {

    private int[] testscore;

    public TestScore(int[] testscore) throws DiemAm, LonHon100 {

        for (int i = 0; i < testscore.length; i++) {
            int num = testscore[i];

            if(num <= 0) {
                throw new DiemAm(num);
            }

            if(num >= 0) {
                throw new LonHon100(num);
            }
        }


        this.testscore = testscore;


    }
    public int getAverage() {
        int total = 0;
        for (int i = 0; i < testscore.length; i++) {
            total += testscore[i];
        }
        return total/testscore.length;
    }


}