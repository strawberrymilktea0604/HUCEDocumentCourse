public class MainProgram {
    public static void main(String[] args) {
        Box<String> box1 = new Box<String>();
        box1.setValue("A");
        Box<Integer> box2 = new Box<Integer>();
        box2.setValue(Integer.valueOf(100));

        String value1 = box1.getValue();
        Integer value2 = box2.getValue();
    }
}
