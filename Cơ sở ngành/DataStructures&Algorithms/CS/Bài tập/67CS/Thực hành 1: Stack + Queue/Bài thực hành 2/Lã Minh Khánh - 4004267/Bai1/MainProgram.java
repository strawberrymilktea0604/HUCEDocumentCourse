class MainProgram
{
    public static String reverse(String str)
    {
        if (str == null || str.equals("")) {
            return str;
        }
        LinkedStack<Character> stack = new LinkedStack<Character>();
        for (int i = 0; i < str.length(); i++) {
            stack.push(str.charAt(i));
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        return sb.toString();
    }
 
    public static void main(String[] args)
    {
        String str = "67CS1";
 
        str = reverse(str);
 
        System.out.println(str);
    }
}