public class MainProgram {
    public static void main(String[] args)
    {
        PostfixEvaluator evaluator = new PostfixEvaluator();
        System.out.println(evaluator.evaluate("7 4 -3 * 1 5 + / *"));
    }
}
