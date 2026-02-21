import java.util.Scanner;


/**
This program will get the values for miles driven and gallons of gas used to calculate the miles per gallon of a car 
*/


//TASK #2 Add import statement here to use the Scanner class
//TASK #2 (Alternate) Add import statment to use JOptionPane
//class
public class Mileage 
{
    public static void main(String[] args)
{
    //TASK #2 Create a Scanner object here
    Scanner keyboard = new Scanner(System.in);
    //(not used for alternate)  

// add your declaration and code here
// ask the user how many miles they have driven.
System.out.println("How many miles did you drive?");
// read the values of miles driven 
double mileage = keyboard.nextDouble();
// ask the user how many gallons of gas used when they drive
System.out.println("How much gas (in gallons) did you use?");
// read the values of gallons of gas used
double gas = keyboard.nextDouble();
// calculate the mileage per gallon
double mpg = mileage / gas; 


// what happen if the value of gallon of gas is zero?
// if (gas = 0.0) {
    String infinicar = new String("You must've used some gas. Try again."); 
    

// print out the mileage per gallon
    System.out.println("You car has " + mpg + " miles per gallon.");
    keyboard.close();


}

}
