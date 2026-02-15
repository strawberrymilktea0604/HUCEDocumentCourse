
import java.util.Scanner;

public class Prefix_Calc 
{
    final static String ADD = "+";
    final static String SUBTRACTION = "-";
    final static String MUL = "*";
    final static String DIV = "/";

    private static LinkedStack<Integer> st = new LinkedStack<>();
    
    public static int calc(String str) throws EmptyCollectionException
    {
        Scanner sc = new Scanner(str);
        String token; 

        while(sc.hasNext()) 
        {
            token = sc.next();
            if(!isOperator(token)) 
            {
                st.push(Integer.valueOf(token));
            }
            else 
            {
                int op2 = st.pop();
                int op1 = st.pop();
                int res = evaluateOpr(token, op1, op2);
                st.push(res);
            }
        }

        sc.close();
        return st.pop();
    }

    private static boolean isOperator(String token) 
    {
        return (token.equals(ADD) || token.equals(SUBTRACTION) || token.equals(MUL) || token.equals(DIV));
    }

    private static int evaluateOpr(String token, int op1, int op2) 
    {
        int res = 0;
        switch(token) 
        {
            case ADD:  
                res = op1 + op2;
                break;
            case SUBTRACTION: 
                res = op1 - op2;
                break;
            case MUL: 
                res = op1 * op2;
                break;
            case DIV: 
                res = op1 / op2;
                break;
        }
        return res;
    }
}