public class MainProgram {
    public static void main(String[] args) {
        ArrayStack<String> stack1 = new ArrayStack<String>();
        stack1.push("A");
        stack1.push("B");
        stack1.push("C");

        System.out.println(stack1.pop());
        System.out.println(stack1.pop());
        System.out.println(stack1.pop());

        PostfixEvaluator evaluator = new PostfixEvaluator();
        System.out.println(evaluator.evaluate("7 4 -3 * 1 5 + / *"));
    }
}
