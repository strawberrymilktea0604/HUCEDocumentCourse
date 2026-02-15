import java.util.Scanner;

public class PostfixEvaluator {
    private static final String ADD = "+";
    private static final String SUBTRACTION = "-";
    private static final String MULTIPLY = "*";
    private static final String DIVISION = "/";

    private ArrayStack<Integer> stack;

    public PostfixEvaluator()
    {
        stack = new ArrayStack<Integer>();
    }

    /**
     * A method to evaluate a postfix expression
     * @param exp : an expression
     * @return result
     */
    public int evaluate(String exp)
    {
        int op1,op2, result = 0;
        Scanner scanner = new Scanner(exp);

        while(scanner.hasNext())
        {
            String token = scanner.next();
            if (isOperator(token)) {
                op2 = stack.pop().intValue();
                op1 = stack.pop().intValue();
                result = evaluateSingleOperator(token, op1, op2);
                stack.push(result);
            } else
                stack.push(Integer.valueOf(token));
        }
        scanner.close();
        return result;
    }

    private boolean isOperator(String token) {
        return (token.equals(ADD) || token.equals(SUBTRACTION) || token.equals(MULTIPLY) || token.equals(DIVISION));
    }

    private int evaluateSingleOperator(String token, int op1, int op2)
    {
        int result = 0;
        switch (token) {
            case ADD: result = op1 + op2;
                break;
            case SUBTRACTION: result = op1 - op2;
                break;
            case MULTIPLY: result = op1 * op2;
                break;
            case DIVISION: result = op1 / op2;
                break;
        }
        return result;
    }
}