import java.util.Scanner; 
public class bubbleSort
{
    public static void main(String args[])
    {
        //declaration 
        Scanner sc = new Scanner(System.in);
        int n,temp; 
        int[] a;
        
        //reading the number of array elements
        System.out.println("Enter the number of array elements: ");
        n = sc.nextInt();
        
        //creating an array of size n
        a = new int[n];
        
        //reading the array elements 
        System.out.println("Enter " + n + " array elements");
        for(int i = 0 ; i < n ; i++)
        {
            a[i] = sc.nextInt();
        }
        
        //bubble sort techinique 
        for(int i = 0 ;  i < n-1 ; i++)
        {
            for(int j = 0 ; j < n-i-1 ; j++)
            {
                if(a[j] > a[j+1])
                {
                    temp = a[j] ;
                    a[j] = a[j+1];
                    a[j+1] = temp; 
                }
            }
        }
        
        //display statement 
        for(int i = 0 ; i < a.length ; i++)
        {
            System.out.println(a[i] + " "); 
        }
    }
}
