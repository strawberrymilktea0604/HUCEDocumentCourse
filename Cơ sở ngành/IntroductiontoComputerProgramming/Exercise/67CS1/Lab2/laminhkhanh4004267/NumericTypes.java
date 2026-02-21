import java.util.Scanner;

/**
This program demonstrates how numeric types and operators behave
*/

//TASK #2 Add import statement here to use the Scanner class
//TASK #2 (Alternate) Add import statment to use JOptionPane
//class

public class NumericTypes 
{ 

public static void main (String [] args)
    {
    //TASK #2 Create a Scanner object here
    Scanner keyboard = new Scanner (System.in);
    //(not used for alternate)
    
    //identifier declarations
    final int NUMBER = 2 ; // number of scores
    final int SCORE1 = 100; // first test score
    final int SCORE2 = 95; // second test score
    final int BOILING_IN_F = 212; // freezing temperature
    int fToC; // temperature in Celsius
    double average; // arithmetic average
    String output; // line of output to print out
    //TASK #2 declare variables used here
    //TASK #3 declare variables used here
    //TASK #4 declare variables used here
    
    // Find an arithmetic average
    average = (double) (SCORE1 + SCORE2) / NUMBER;
    output = SCORE1 + " and " + SCORE2 +
    " have an average of " + average;
    System.out.println(output);
    
    // Convert Fahrenheit temperatures to Celsius
    fToC = (5 * (BOILING_IN_F - 32)) / 9;
    output = BOILING_IN_F + " in Fahrenheit is " + fToC
    + " in Celsius.";
    
    
    System.out.println(output);
    System.out.println(); // to leave a blank line

    
    // ADD LINES FOR TASK #2 HERE
// prompt the user for first name
System.out.println ("Enter your first name:"); 
// read the user’s first name
String filname = keyboard.next();
// prompt the user for last name
System.out.println ("Enter your last name:");
// read the user’s last name
String lsname = keyboard.next();
// concatenate the user’s first and last names
String FullName = filname + " " + lsname; 
System.out.println ("Your full name is: " + FullName);
// print out the user’s full name

    
    System.out.println(); // to leave a blank line
    
    // ADD LINES FOR TASK #3 HERE
    char ch = filname.charAt(0);
    // get the first character from the user’s first name
    System.out.println("Your first initial is " + ch); 
    // print out the user’s first initial
    // convert the user’s full name to all capital letters
    FullName = FullName.toUpperCase();
    // print out the user’s full name in all capital
    System.out.println ("Your full name to all capital letters is: " + FullName);
    // letters and the number of characters in it
    
    for (int i = 0; i < FullName.length(); i++) {
    System.out.print(FullName.charAt(i) + " ");
    }

    int n = FullName.length() - 1;
    System.out.println ();
    System.out.println ("Number of Characters:" + n);
    System.out.println ();


    
    System.out.println(); // to leave a blank line
    
    // ADD LINES FOR TASK #4 HERE
    // prompt the user for a diameter of a sphere
    System.out.println("Enter the diameter: ");
    // read the diameter
    double d = keyboard.nextDouble();
    // calculate the radius
    double r = ((double) d)/2;
    // calculate the volume
    double vol = (4 * Math.PI * Math.pow(r, 3))/3;
    // print out the volume
    System.out.println("The volume is: " + vol);
    keyboard.close ();


    
    
     }
}
