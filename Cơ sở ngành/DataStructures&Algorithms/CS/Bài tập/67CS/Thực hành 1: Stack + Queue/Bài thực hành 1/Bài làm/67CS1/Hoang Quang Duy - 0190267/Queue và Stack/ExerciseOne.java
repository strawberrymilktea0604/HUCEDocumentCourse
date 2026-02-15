import java.util.Scanner;

public class ExerciseOne 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập chuỗi kí tự (viết liền nhau): ");

        String input = sc.nextLine(); 
        int len = input.length();
        char[] arr = input.toCharArray();
        LinkedStack<Character> st = new LinkedStack<>();

        for(char ch: arr)
            st.push(ch);

        System.out.print("Reverse Order: ");
        while(len > 0) 
        {
            System.out.print(st.pop() + " ");
            len--; 
        }

        sc.close();
    }
}