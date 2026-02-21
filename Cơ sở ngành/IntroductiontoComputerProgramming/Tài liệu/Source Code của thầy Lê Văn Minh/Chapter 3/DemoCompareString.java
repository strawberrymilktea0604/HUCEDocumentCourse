public class DemoCompareString {
    public static void main(String[] args) {
        String str1 = "b";
        String str2 = "a";

        int check = str1.compareTo(str2);
        if (check > 0) {
            System.out.println("");
        } else if (check < 0) {
            System.out.println("");
        } else {
            System.out.println("");
        }

        boolean check2 = str1.equalsIgnoreCase(str2);
        // if (!str1.equals(str2)) {
        //     System.out.println("Khong bang nhau");
        // }

        int hours = 40;
        System.out.printf("I worked%3d hours.\n %d %d %d\n", hours, hours, hours, hours);

        double grossPay = 874.14;
        System.out.printf("Your pay is %-20.1f abc\n", grossPay);

        String name = "Nguyen van a";
        System.out.printf("Xin chao: %s", name);
    }
}
