import java.util.Scanner;

public class ExerciseThree 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so can chuyen sang nhi phan: ");
        int input = sc.nextInt();
        LinkedStack<Integer> st = new LinkedStack<>(); 

        while(input > 0) 
        { 
            st.push(input % 2);
            input = input / 2;
        }

        System.out.println("Bieu dien nhi phan cua so la: ");
        while(!st.isEmpty())  
            System.out.print(st.pop() + " ");

        sc.close();
    }
}
