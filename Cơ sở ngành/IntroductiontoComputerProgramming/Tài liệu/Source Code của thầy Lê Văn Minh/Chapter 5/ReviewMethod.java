public class ReviewMethod {
    public static int sum(int num1, int num2) {
        return num1 + num2;
    }

    public static void main(String[] args) {
        String str = "ABC";
        for (int i = 0; i < str.length(); i++) {
            System.out.print(str.charAt(i));
        }

        int index = 1;
        int num3 = 1;
        num3 += --index;
        System.out.print(num3); //3 
    }
}
