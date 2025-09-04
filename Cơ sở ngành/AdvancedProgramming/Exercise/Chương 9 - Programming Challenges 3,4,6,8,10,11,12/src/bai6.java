import java.util.*;

public class bai6 {
    static ArrayList<String> names = new ArrayList<>();
    static ArrayList<String> phoneNumber = new ArrayList<>();

    private static void searchName(String name) {
        int index = 0;

        System.out.println();
        for (String x : names) {
            if(x.contains(name)) {
                index++;
                System.out.println("Ten: " + x + "\nSo dien thoai: " + phoneNumber.get(index));
            }
        }
    }

    public static void main(String[] args) {
        names.add("Harrison, Rose");
        names.add("James, Jean");
        names.add("Smith, William");
        names.add("Smith, Brad");

        phoneNumber.add("555-2234");
        phoneNumber.add("555-9098");
        phoneNumber.add("555-1785");
        phoneNumber.add("555-9224");

        Scanner sc = new Scanner(System.in);
        System.out.println("Tim kiem: ");
        String name = sc.nextLine();

        searchName(name);


    }
}
