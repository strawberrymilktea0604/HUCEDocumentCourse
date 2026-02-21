public class DemoLoop {
    public static void main(String[] args) {
        int index = 0;
        do {
            index++;
        } while (index < 3);
        System.out.println(index); //3

        int index2 = 0;
        while (index2 < 3) {
            index2++;
        }
        System.out.println(index2); //3

        int count = 0;
        for (int i = 0; i < 3; i++) {
            count++;
        }
        System.out.println(count);

        
    }
}