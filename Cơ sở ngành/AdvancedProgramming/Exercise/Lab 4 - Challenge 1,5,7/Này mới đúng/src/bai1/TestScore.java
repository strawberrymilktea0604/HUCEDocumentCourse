package bai1;

public class TestScore {
    private double[] testscore;

    public TestScore(double[] s) {
        testscore = s;

        for(int i = 0; i < testscore.length; i++) {

            if (testscore[i] < 0 || testscore[i] > 100) {
                throw new IllegalArgumentException("Diem trung binh khong hop le!");
            }
        }
    }

    public double getAvarage() {
        double avarage = 0;

        for(int i = 0; i < testscore.length; i++) {
            avarage += testscore[i];
        }
        avarage /= testscore.length;
        return avarage;
    }
}
