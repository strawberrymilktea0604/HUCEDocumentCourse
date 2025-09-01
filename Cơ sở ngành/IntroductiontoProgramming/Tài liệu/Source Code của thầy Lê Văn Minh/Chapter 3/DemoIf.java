
class DemoIf {
    public static void main(String[] args) {
        int x = 2;
        int y = 3;
        int num1 = (x > 3) ? 1 : 2;

        String str = (x > 3) ? ((y > 3) ? "Nguyen Van A" : "Nguyen Van A1") : "Nguyen Van B";

        //#region xử lý if
        // if (x > y)
        //     System.out.println("X is greater than Y");
        // if (x == y)
        //     System.out.println("X is equal to Y");
        // if (x != y) {
        //     System.out.println("X is not equal to Y");
        //     x = 9;
        //     x = y;
        // }
        // System.out.println("However, now it is.");
        //#endregion

        int z = 10;
        if (x >= y) {
            z = --x;
        } else if (x > y) {
            z = 3;
        } else {
            z = x++;
        }

        // if (x >= y) {
        //     z = --x;
        // }
        // if (x > y) {
        //     z = 3;
        // } else {
        //     z = x++;
        // }

        // if (x == 1) {
        //     z = 1;
        // } else if (x == 2) {
        //     z = 2;
        // } else if (x == 3) {
        //     z = 3;
        // } else if (x == 4) {
        //     z = 4;
        // } else if (x == 5) {
        //     z = 5;
        // } else {
        //     z = -1;
        // }
        //String str = "4";
        // char char1 = '1';
        // switch (char1) {
        //     case '1':
        //         z = 1;
        //         break;
        //     case '2':
        //         z = 2;
        //         break;
        //     case '3':
        //         z = 3;
        //         break;
        //     case '4':
        //         break;
        //     case '5':
        //         z = 5;
        //         break;
        //     default:
        //         z = -1;
        //         break;
        // }
        // System.out.println(z);

        int a = 1;
        int b = 1;
        int c = -1;
        boolean check = !((a < b && a > c) || a == 4);
        if (check) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
    }
}