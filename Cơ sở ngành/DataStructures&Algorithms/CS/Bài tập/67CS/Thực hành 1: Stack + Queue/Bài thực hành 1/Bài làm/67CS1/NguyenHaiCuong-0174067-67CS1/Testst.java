package HW;
import java.util.Stack;

public class Testst{
    public static void main(String[] args) {
        Stack<Integer> stk = new Stack<>();
        Stack<String> stk2 = new Stack<>();
        boolean res = stk.isEmpty();
        boolean res2 = stk.isEmpty();

        System.out.println("Does two arrays empty?" + res + "and" + res2);

        stk.push(23);
        stk.push(42);
        stk.push(12);
        stk.push(65);
        stk.push(87);
        stk2.push("DJSSW");
        stk2.push("DJDAS");
        stk2.push("dapod");
        stk2.push("sdadD");

        System.out.println("First array: " + stk);
        stk.pop();
        System.out.println("Second array: " + stk);
        System.out.println("Area of 23: " + stk.search(23));
        System.out.println("Area of 87: " + stk.search(87));

        System.out.println("First array: " + stk2);
        stk2.pop();
        System.out.println("Second array: " + stk2);
        System.out.println("Area of sdadD: " + stk2.search("sdadD"));
        System.out.println("Area of DJSSW: " + stk2.search("DJSSW"));
    }
}