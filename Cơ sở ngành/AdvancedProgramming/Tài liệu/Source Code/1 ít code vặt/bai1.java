public class bai1 {
    private static int x;
    static int c;

    public static int getX() {
        return x;
    }

    public void setX (int x) {
        System.out.println(this);
        this.x = x;
    }

    public static int getC() {
        return c;
    }

    public static void setC(int c) {
        bai1.c = c;
    }

    public static void main(String[]args) {
        bai1 obj1 = new bai1();
        bai1 obj2 = new bai1();

        System.out.println(obj1);
        obj1.setX(10);

        System.out.println(obj2);
        obj2.setX(100);

        System.out.println("Object 1: " + obj1.getX());
        System.out.println("Object 2: " + obj1.getX());
        obj1.setC(1);

        System.out.println("Object 1 c = " + obj1.getC());
        System.out.println("Object 2 c = " + obj1.getC());
        obj1.setC(50);

        bai1.setC(1);

        
    }
}