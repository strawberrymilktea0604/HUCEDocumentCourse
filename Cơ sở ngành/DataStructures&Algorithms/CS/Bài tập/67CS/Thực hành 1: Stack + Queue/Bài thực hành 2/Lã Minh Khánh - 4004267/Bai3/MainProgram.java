public class MainProgram {
    public static void main(String[] args) {
    LinkedStack<Integer> stack = new LinkedStack<Integer>();

    int num = 23;

    while(num>0)
    {
        int r = num%2;
        stack.push(r);
        num/=2;
    }
   
     while (!(stack.isEmpty() ))
     {
         System.out.print(stack.pop());
     }


    }
}