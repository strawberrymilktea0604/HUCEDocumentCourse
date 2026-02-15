package Stack;

public class DemoStack {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.print();
        stack.pop();
        System.out.println("\nBefore pop\n");
        stack.print();
    }
}
