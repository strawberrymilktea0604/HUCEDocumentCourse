public class Demo {
    public static void main(String[] args) throws EmptyCollectionException {

        String postFixOperator = "7 3 -4 * 5 7 + / *";
        System.out.println(Prefix_Calc.calc(postFixOperator));

    }
}
