public class DemoCompareArray {
    public static void main(String[] args) {
        int[] array1 = { 1, 2, 3 };
        int[] array2 = { 1, 2, 3 };
        int[] array3 = array1;

        System.out.println("So sanh ve vung nho");
        //so sánh 2 mảng
        if (array1 == array3) {
            System.out.println("Hai mang bang nhau");
        } else {
            System.out.println("Hai mang khong bang nhau");
        }

        System.out.println("So sanh ve gia tri");
        boolean checkEqual = true; //coi là bằng nhau

        if (array1.length != array2.length) {
            System.out.println("Hai mang bang nhau");
        }

        for (int i = 0; i < array1.length; i++) {
            if (array1[i] != array2[i]) {
                checkEqual = false;
                break;
            }
        }

        if (checkEqual) {
            System.out.println("Hai mang bang nhau");
        } else {
            System.out.println("Hai mang khong bang nhau");
        }

    }
}
