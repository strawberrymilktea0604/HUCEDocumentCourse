public class Demo 
{
    public static void main(String[] args) throws EmptyCollectionException
    {
        
        String postFixOperator = "7 4 -3 * 1 5 + / *";
        System.out.println(Prefix_Calc.calc(postFixOperator));

    }
}