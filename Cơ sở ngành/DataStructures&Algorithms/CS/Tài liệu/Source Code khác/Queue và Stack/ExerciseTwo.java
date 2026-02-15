import java.util.Scanner;

public class ExerciseTwo 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in); 
        System.out.print("Nhập chuỗi đầu vào: ");
        String input = sc.nextLine(); 
        LinkedStack<Character> st = new LinkedStack<>();
        boolean flag = true; 

        for(int i = 0; i < input.length(); i++) 
        {
            char ch = input.charAt(i);
            if(ch == '(') 
            {
                st.push(')');
            }
            else if(ch == '[')
            {
                st.push(']');
            }
            else if(ch == '{')
            {
                st.push('}');
            } 
            else
            {
                if(ch != st.pop()) 
                {
                    flag = false; 
                    break; 
                }
            } 
        }

        if(flag)    
            System.out.println("Balanced");
        else 
            System.out.println("Not Balanced");

        sc.close();
    }       
}
